#pragma once

#include "pch.h"
#include "Core.h"

namespace Eval
{

	struct Indices
	{
		int indexBeforeOperator;
		int indexAfterOperator;
	};

	struct Numbers
	{
		int num1;
		int num2;
	};


	class EV_API Evaluator
	{
	public:
		Evaluator() = delete;

		static int Evaluate(const std::wstring& term);
		
	private:
		static Indices GetStartAndEndIndexOfFirstTerm();
		static Numbers GetNumbers(const Indices& indices);
		static Indices GetIndexOfNumbers(unsigned int operatorIndex);

		enum class Operations
		{
			NONE = -1, Add, Subtract, Multiply, Divide
		};

		static Operations m_Operation;
		static std::wstring m_Term;

	};

	inline int Evaluator::Evaluate(const std::wstring& term)
	{
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

		//replaces too much!!
		m_Term.replace(indices.indexBeforeOperator, indices.indexAfterOperator - indices.indexBeforeOperator + 1, std::to_wstring(result));
		// return might not be necessary
		return Evaluate(m_Term);
	}

}