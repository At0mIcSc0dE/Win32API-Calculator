#pragma once

#include "pch.h"


namespace Calculator
{
	/**
	* Enum which defines all the existing Widgets
	*/
	enum class WidgetType
	{
		UNDEFINED = 0, Button, Textbox
	};

	/**
	* Struct which defines the widget's transform
	*/
	struct Rect
	{
		unsigned int x, y, width, height;
	};


	/**
	* Any widget should be derived from this class
	*/
	class Widget
	{
	public:
		/**
		* Changes widget's width and height
		*
		* @param width is the target widget width
		* @param height is the target widget height
		*/
		virtual void Resize(const int& width, const int& height) = 0;

		/**
		* Hides the widget after it was shown, does nothing if button is already hidden
		*/
		virtual void Show() const = 0;

		/**
		* Shows the widget after it was hidden, does nothing if button is already displayed
		*/
		virtual void Hide() const = 0;

		/**
		* Sets text which is displayed when the widget is rendered
		* @param text is the new widget text
		*/
		virtual void SetText(const LPCWSTR& text) = 0;

		/**
		* Function to get the current widget type, e.g. Button, Textbox, Checkbox...
		* @returns the widget's type
		* @note this function needs to be implemented in every widget, along with a static function doing the same
		*/
		virtual const WidgetType GetWidgetType() const = 0;
	};

}
