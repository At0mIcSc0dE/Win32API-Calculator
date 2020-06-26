#pragma once

#include "Widget.h"



namespace Calculator
{

	class Button : Widget
	{
	public:
		Button(const LPCWSTR& name, const Rect& rect, HWND& parent,
				const int& buttonID, const int& flags = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
		
		Button(const LPCWSTR& name, const int& x, const int& y, const int& width,
				const int& height, HWND& parent, const int& buttonID, const int& flags = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);

		virtual void Resize(const int& width, const int& height) override;
		virtual void Hide() const override;
		virtual void Show() const override;
		virtual void SetText(const LPCWSTR& text) override;

	private:
		HWND m_hwndButton;
	};

}