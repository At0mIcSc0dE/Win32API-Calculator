#pragma once

#include "pch.h"


namespace Calculator
{

	/**
	* Struct which defines the widget's transform
	*/
	struct Rect
	{
		unsigned int x, y, width, height;
	};


	/**
	* Abstract class, any widget should be derived from this class
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
	};

}
