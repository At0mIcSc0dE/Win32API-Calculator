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

	inline void CL_LOG(const std::string& text, const std::string& filepath = "D:\\dev\\Cpp\\Projects\\CalculatorWin32API\\log.txt")
	{
		Logger::Log(text, filepath);
	}

	inline void CL_CLEAR(const std::string& filepath = "D:\\dev\\Cpp\\Projects\\CalculatorWin32API\\log.txt")
	{
		Logger::Init(filepath);
	}

}

//#define CL_LOG(text, filepath = "log.txt") Logger::Log(text, filepath);

