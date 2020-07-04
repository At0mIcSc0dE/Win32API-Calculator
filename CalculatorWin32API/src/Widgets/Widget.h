#pragma once

#include "pch.h"
#include "Calculator/Core.h"

namespace Calculator
{
	/**
	* Enum which defines all the existing Widgets
	*/
	enum class CL_API WidgetType
	{
		UNDEFINED = 0, Button, Textfield
	};

	/**
	* Struct which defines the widget's transform
	*/
	struct CL_API Rect
	{
		unsigned int x, y, width, height;
	};


	/**
	* Any widget should be derived from this class
	*/
	class CL_API Widget
	{
	public:
		/**
		* Changes widget's width and height
		*
		* @param width is the target widget width
		* @param height is the target widget height
		*/
		[[noreturn]] virtual void Resize(const int& width, const int& height) = 0;

		/**
		* Hides the widget after it was shown, does nothing if button is already hidden
		*/
		[[noreturn]] virtual void Show() const = 0;

		/**
		* Shows the widget after it was hidden, does nothing if button is already displayed
		*/
		[[noreturn]] virtual void Hide() const = 0;

		/**
		* Gets the current widget type, e.g. Button, Textbox, Checkbox...
		*
		* @returns the widget's type
		* @note this function needs to be implemented in every widget, along with a static function doing the same
		*/
		virtual const WidgetType GetWidgetType() const = 0;

		/**
		* Method to get the name of the current class
		*
		* @returns the name of the current class e.g. Widget, Button, Textbox...
		*/
		virtual const wchar_t* GetName() const { return L"Widget"; }

		/**
		* Gets the current widget's ID which was defined in Application::AddWidget
		*
		*@see Calculator::Application::AddWidget
		*@returns the current widget's ID
		*/
		virtual const int& GetID() const = 0;

		/**
		* Getter for widget HWND
		*
		* @returns the widget's HWND
		*/
		virtual const HWND& GetHWND() const = 0;

	protected:
		static int s_NextID;
	};


}
