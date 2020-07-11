#pragma once

#include "pch.h"
#include "Calculator/Calculator.h"
#include "Widgets/Widget.h"

namespace Calculator
{

	class EventDispatcher
	{
	public:
		/**
		* Constructor for EventDispatcher
		*
		* @param e is the event id which should match the dispatched widget id
		*/
		EventDispatcher(Event& e) : m_Event(e) {}

		/**
		* Dispatches events to their specified functions
		*
		* @param fn is the function which will be called, if the event matches
		* @param w is the widget which sent the event
		* @returns false if the event id didn't match the widget id, else it returns the result of the function fn
		*/
		bool Dispatch(_In_ const EventFn& fn, _In_ Widget* w)
		{
			ASSERT(w);
			if (LOWORD(m_Event) == w->GetID())
			{
				return fn(m_Event, w);
			}
			return false;
		}

	private:
		Event& m_Event;
	};

}