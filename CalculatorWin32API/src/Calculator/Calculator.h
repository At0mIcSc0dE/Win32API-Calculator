/**
* Header file including global declarations/#defines
*/
#pragma once

#include "pch.h"
#include "Calculator/Logger/Logger.h"


#define ID(Event)						LOWORD(Event)

#define BIND_EVENT_CALLBACK_FN(func)	[this](Calculator::Event& e) { this->func(e); }
#define BIND_EVENT_FN(func)				[this](Calculator::Event& e) { return this->func(e); }


#ifdef CL_ASSERT_ENABLED
	#define ASSERT(x) if(!(x)) { CL_LOG(std::string("Assertion in file ") + std::string(__FILE__) + std::string(" (") + std::to_string(__LINE__) + std::string(") failed")); __debugbreak(); } else { CL_LOG(std::string("Assertion in file ") + std::string(__FILE__) + std::string(" (") + std::to_string(__LINE__) + std::string(") succeded")); }
#else
	#define ASSERT(x)
#endif

namespace Calculator
{

	typedef WPARAM Event;
	using EventFn = std::function<bool(Event&)>;
	using EventCallbackFn = std::function<void(Event&)>;

}