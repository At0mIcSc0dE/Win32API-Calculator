#include "pch.h"
#include "Evaluator.h"


namespace Eval
{
	std::wstring Evaluator::m_Term = L"";
	Evaluator::Operations Evaluator::m_Operation = Evaluator::Operations::NONE;

	Indices Evaluator::GetStartAndEndIndexOfFirstTerm()
	{
		Indices indices = {};

		bool termHasNoMultiplyOrDivide = true;

		for (int i = 0; i < m_Term.size(); ++i)
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
		
		Indices indices = {};
		for (int i = operatorIndex + 1; i < m_Term.size(); ++i)
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
