#pragma once

#include "Widget.h"


namespace Calculator
{

	class Button : Widget
	{
	public:
		Button(const LPCWSTR& name, const Rect& rect, HWND& parent, const int& flags);
		Button(const LPCWSTR& name, const int& x, const int& y, const int& width, const int& height, HWND& parent, const int& flags);

		virtual void Resize(const int& width, const int& height) override;
		virtual void Hide() override;
		virtual void Show() override;
		virtual void SetText(const LPCWSTR& text) override;

	private:
		HWND m_hwndButton;
	};

}