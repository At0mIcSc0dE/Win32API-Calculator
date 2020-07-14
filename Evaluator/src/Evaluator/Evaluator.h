#pragma once

#include "pch.h"
#include "Core.h"

namespace Eval
{

	/**
	* Struct containing two integers which represent the index of the first number and the index of the last number in an equation
	*/
	struct Indices
	{
		int indexBeforeOperator;
		int indexAfterOperator;
	};

	/**
	* Struct containing two integers which represent the two numbers of an equation
	*/
	struct Numbers
	{
		int num1;
		int num2;
	};


	class EV_API Evaluator
	{
	public:
		Evaluator() = delete;

		/**
		* Evaluates mathematical operation
		*
		* @param term is the operation as std::wstring
		* @returns the result of the equation
		* @warn does not check if the equation is valid, might give back unexpected results
		* @warn does not handle doubles or floats
		*/
		static int Evaluate(const std::wstring& term);
		
	private:
		/**
		* Figures out the starting and ending index for the first equation to be calculated, 
		* function also sets Eval::Evaluator::m_Operation
		*
		* @returns the index where the first number starts and the index where the second number ends
		*/
		static Indices GetStartAndEndIndexOfFirstTerm();
		
		/**
		* Gets the two numbers at the indices from the Eval::Evaluator::GetStartAndEndIndexOfFirstTerm function
		*
		* @parm indices are the indices from the Eval::Evaluator::GetStartAndEndIndexOfFirstTerm function
		* @returns the two numbers of the equation
		*/
		static Numbers GetNumbers(const Indices& indices);
		
		/**
		* Function is used by the Eval::Evaluator::GetStartAndEndIndexOfFirstTerm function
		*
		* @param operatorIndex is the index of the operator between two numbers
		* @returns the indices of the first and second number
		*/
		static Indices GetIndexOfNumbers(unsigned int operatorIndex);

		/**
		* Enum defines arithmetic operations
		*/
		enum class Operations
		{
			NONE = -1, Add, Subtract, Multiply, Divide
		};

		static Operations m_Operation;
		static std::wstring m_Term;

	};

}