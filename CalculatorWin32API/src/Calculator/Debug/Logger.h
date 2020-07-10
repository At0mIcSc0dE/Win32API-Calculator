#pragma once

#include "pch.h"
#include "Calculator/Core.h"


namespace Calculator
{

	class CL_API Logger
	{
	public:
		static void Init(const std::string& filepath);

		static void Log(const std::string& message, const std::string& filepath);
	};

}


#if CL_LOG_ACTIVE
	#define CL_LOG(text) Calculator::Logger::Log(text, "D:\\dev\\Cpp\\Projects\\CalculatorWin32API\\log.txt")
	#define CL_CLEAR() Calculator::Logger::Init("D:\\dev\\Cpp\\Projects\\CalculatorWin32API\\log.txt")
#else
	#define CL_LOG(text)
	#define CL_CLEAR()
#endif