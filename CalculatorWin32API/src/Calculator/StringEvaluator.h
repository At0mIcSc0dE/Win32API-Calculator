#pragma once

#include "pch.h"


namespace Calculator
{

	class StringEvaluator
	{
	public:
		StringEvaluator() = default;

		static double EvaluateString(const std::string& str);

	private:
		static bool IsNumeric(const char& str);
	};

}