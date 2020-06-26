#pragma once

#include "pch.h"


namespace Calculator
{

	struct Rect
	{
		unsigned int x, y, width, height;
	};



	class Widget
	{
	public:
		virtual void Resize(const int& width, const int& height) = 0;
		virtual void Show() const = 0;
		virtual void Hide() const = 0;
		virtual void SetText(const LPCWSTR& text) = 0;
	};

}
