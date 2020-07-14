#pragma once

#include "pch.h"
#include "Evaluator/Core.h"


namespace Calculator
{

	class EV_API Logger
	{
	public:
		static void Init(const std::string& filepath);

		static void Log(const std::string& message, const std::string& filepath);
	};

}


#if EV_LOG_ACTIVE
	#define EV_LOG(text) Calculator::Logger::Log(text, "D:\\dev\\Cpp\\Projects\\CalculatorWin32API\\log.txt")
	#define EV_CLEAR() Calculator::Logger::Init("D:\\dev\\Cpp\\Projects\\CalculatorWin32API\\log.txt")
#else
	#define EV_LOG(text)
	#define EV_CLEAR()
#endif