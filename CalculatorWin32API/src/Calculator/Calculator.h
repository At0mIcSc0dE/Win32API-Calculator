/**
* Header file including global declarations
*/
#pragma once

#include "pch.h"

#define ID(Event) LOWORD(Event)


namespace Calculator
{

	typedef WPARAM Event;
	//typedef WORD Event;
	using EventFn = std::function<bool(Event&)>;
	using EventCallbackFn = std::function<void(Event&)>;



}