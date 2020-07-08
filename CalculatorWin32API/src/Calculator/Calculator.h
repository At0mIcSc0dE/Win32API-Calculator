/**
* Header file including global declarations
*/
#pragma once

#include "pch.h"

#define ID(Event) LOWORD(Event)

#define BIND_EVENT_FN(func) [this](Calculator::Event& e) { this->func(e); }

namespace Calculator
{

	typedef WPARAM Event;
	//typedef WORD Event;
	using EventFn = std::function<bool(Event&)>;
	
	using EventCallbackFn = std::function<void(Event&)>;
	//using EventCallbackFn = void(*)(Event&);
	//typedef void(*EventCallbackFn)(Event&);

	//struct EventCallbackFn
	//{
	//	static const _EventCallbackFn* eCFn;
	//
	//	static void Run(Event& e)
	//	{
	//		(*eCFn)(e);
	//	}

	//};
}