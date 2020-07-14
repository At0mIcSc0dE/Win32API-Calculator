#include "pch.h"
#include "Evaluator.h"
#include "Debug/Timer.h"


namespace Eval
{
	std::wstring Evaluator::m_Term = L"";
	Evaluator::Operations Evaluator::m_Operation = Evaluator::Operations::NONE;

	int Evaluator::Evaluate(const std::wstring& term)
	{
		// +1000us per run!!!, first run aprox. 200us, next 1000us, next 2000us, next 3000us... 
		TIMER;
		m_Term = term;

		Indices indices = GetStartAndEndIndexOfFirstTerm();

		// Found no more operations to perform
		if (indices.indexBeforeOperator == -1)
		{
			return std::stoi(m_Term);
		}

		Numbers nums = GetNumbers(indices);
		int result = 0;

		switch (m_Operation)
		{
		case Operations::Add:
			result = nums.num1 + nums.num2;
			break;
		case Operations::Subtract:
			result = nums.num1 - nums.num2;
			break;
		case Operations::Multiply:
			result = nums.num1 * nums.num2;
			break;
		case Operations::Divide:
			result = nums.num1 / nums.num2;
			break;
		}

		m_Term.replace(indices.indexBeforeOperator, indices.indexAfterOperator - indices.indexBeforeOperator + 1, std::to_wstring(result));
		return Evaluate(m_Term);
	}

	Indices Evaluator::GetStartAndEndIndexOfFirstTerm()
	{
		// aprox. 370us
		TIMER;
		Indices indices = {};

		bool termHasNoMultiplyOrDivide = true;

		for (unsigned int i = 0; i < m_Term.size(); ++i)
		{
			if (m_Term[i] == L'*' || m_Term[i] == L'/')
			{
				termHasNoMultiplyOrDivide = false;
				break;
			}
		}

		for (unsigned int i = 0; i < m_Term.size(); ++i)
		{
			if (m_Term[i] == L'*' || m_Term[i] == L'/')
			{
				m_Term[i] == L'*' ? m_Operation = Operations::Multiply : m_Operation = Operations::Divide;
				return GetIndexOfNumbers(i);
			}
			else if (termHasNoMultiplyOrDivide && (m_Term[i] == L'+' || m_Term[i] == L'-'))
			{
				m_Term[i] == L'+' ? m_Operation = Operations::Add : m_Operation = Operations::Subtract;
				return GetIndexOfNumbers(i);
				
			}
		}

		return { -1, -1 };

	}

	Numbers Evaluator::GetNumbers(const Indices& indices)
	{
		TIMER;
		Numbers nums = { 0, 0 };

		bool afterOperator = false;
		for (unsigned int i = indices.indexBeforeOperator; i < indices.indexAfterOperator + 1; ++i)
		{

			if (afterOperator && (m_Term[i] == '+' || m_Term[i] == '-' || m_Term[i] == '*' || m_Term[i] == '/'))
			{
				break;
			}

			if(m_Term[i] == '1' || m_Term[i] == '2' || m_Term[i] == '3' || m_Term[i] == '4' || m_Term[i] == '5' || m_Term[i] == '6' || m_Term[i] == '7' || m_Term[i] == '8' || m_Term[i] == L'9' || m_Term[i] == L'0')
			{
				if (afterOperator)
				{
					nums.num2 *= 10;
					wchar_t s = m_Term[i];
					const wchar_t* t = &s;
					nums.num2 += std::stoi(t);
				}
				else
				{
					nums.num1 *= 10;
					wchar_t s = m_Term[i];
					const wchar_t* t = &s;
					nums.num1 += std::stoi(t);

				}
				continue;
			}
			afterOperator = true;

		}

		return nums;

	}

	Indices Evaluator::GetIndexOfNumbers(unsigned int operatorIndex)
	{
		// aprox 9us
		TIMER;
		Indices indices = {};
		for (unsigned int i = operatorIndex + 1; i < m_Term.size(); ++i)
		{
			if (m_Term[i] != '1' && m_Term[i] != '2' && m_Term[i] != '3' && m_Term[i] != '4' && m_Term[i] != '5' && m_Term[i] != '6' && m_Term[i] != '7' && m_Term[i] != '8' && m_Term[i] != '9' && m_Term[i] != '0')
			{
				indices.indexAfterOperator = i - 1;
				break;
			}
			else if (i == m_Term.size() - 1)
			{
				indices.indexAfterOperator = i;
				break;
			}
		}

		for (int i = operatorIndex - 1; i >= 0; --i)
		{
			if (m_Term[i] != '1' && m_Term[i] != '2' && m_Term[i] != '3' && m_Term[i] != '4' && m_Term[i] != '5' && m_Term[i] != '6' && m_Term[i] != '7' && m_Term[i] != '8' && m_Term[i] != L'9' && m_Term[i] != L'0')
			{
				indices.indexBeforeOperator = i + 1;
				break;
			}
			else if (i == 0)
			{
				indices.indexBeforeOperator = i;
				break;
			}
		}

		return indices;

	}
}
