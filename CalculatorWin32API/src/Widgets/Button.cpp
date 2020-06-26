#include "pch.h"
#include "Button.h"


namespace Calculator
{
	Button::Button(const LPCWSTR& name, const Rect& rect, HWND& parent, const int& buttonID, const int& flags)
		:m_hwndButton(CreateWindow(L"BUTTON", name, flags, rect.x, rect.y, rect.width, rect.height,
									parent, (HMENU)buttonID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL))
	{

	}

	Button::Button(const LPCWSTR& name, const int& x, const int& y, const int& width, const int& height, HWND& parent, const int& buttonID, const int& flags)
		:m_hwndButton(CreateWindow(L"BUTTON", name, flags, x, y, width, height,
									parent, (HMENU)buttonID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL))
	{

	}

	void Button::Resize(const int& width, const int& height)
	{
		//TODO: To be implemented
	}

	void Button::Hide() const
	{
		ShowWindow(m_hwndButton, SW_HIDE);
	}

	void Button::Show() const
	{
		ShowWindow(m_hwndButton, SW_SHOW);
	}

	void Button::SetText(const LPCWSTR& text)
	{
		//TODO: To be implemented
	}
}
