#include "pch.h"
#include "StringEvaluator.h"


namespace Calculator
{

	double StringEvaluator::EvaluateString(const std::string& str)
	{
		enum class Operation
		{
			NONE = -1, ADD, SUBTRACT, MULTIPLY, DIVIDE
		};

		int result = 0;
		bool hasDoubles = false;
		bool hasMultiOrDivide = false;
		bool firstNumber = true;
		int num1 = 0;
		int num2 = 0;
		Operation op = Operation::NONE;

		for (const char& ch : str)
		{
			if (ch == *".")
				hasDoubles = true;
			else if (ch == *"*" || ch == *"/")
				hasMultiOrDivide = true;
		}

		for (unsigned int i = 0; i < str.size(); ++i)
		{
			if (hasDoubles)
			{
				if (hasMultiOrDivide)
				{

				}
				else
				{

				}
			}
			else
			{
				if (hasMultiOrDivide)
				{

				}
				else
				{
					//Take first number and add/subtract it with the second
					if (str[i] == '+')
					{
						firstNumber = false;
						op = Operation::ADD;
					}
					else if (str[i] == '-')
					{
						firstNumber = false;
						op = Operation::SUBTRACT;
					}
					else
					{
						if (firstNumber)
						{
							num1 *= 10;
							num1 += str[i] - 48;
						}
						else
						{
							num2 *= 10;
							num2 += str[i] - 48;
						}
					}
				}
			}
		}

		if (op == Operation::ADD)
			return num1 + num2;
		else if (op == Operation::SUBTRACT)
			return num1 - num2;

	}

	bool StringEvaluator::IsNumeric(const char& str)
	{
		char* p;
		strtod(&str, &p);
		return *p ? false : true;
	}

}