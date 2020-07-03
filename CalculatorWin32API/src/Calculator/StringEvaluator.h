#pragma once

#include "pch.h"
#include "Calculator/Core.h"


namespace Calculator
{

	class CL_API StringEvaluator
	{
	public:
		StringEvaluator() = default;

		static double EvaluateString(const std::string& str);

	private:
		static bool IsNumeric(const char& str);
	};

}