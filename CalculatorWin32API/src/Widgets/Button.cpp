/**
* File containing the Button class' definitions
*/

#include "pch.h"
#include "Button.h"


namespace Calculator
{

	void Button::Init(const LPCWSTR& text, const Rect& rect, HWND& parent, const int& flags)
	{
		m_WidgetID = s_NextID;
		++s_NextID;

		m_hwnd = CreateWindow(L"BUTTON", text, flags, rect.x, rect.y, rect.width, rect.height,
			parent, (HMENU)m_WidgetID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);
	}

	void Button::Init(const LPCWSTR& text, const int& x, const int& y, const int& width, const int& height, HWND& parent, const int& flags)
	{
		m_WidgetID = s_NextID;
		++s_NextID;

		m_hwnd = CreateWindow(L"BUTTON", text, flags, x, y, width, height,
			parent, (HMENU)m_WidgetID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);
	}

	void Button::Resize(const int& width, const int& height)
	{
		//TODO: To be implemented
	}

	void Button::Hide() const
	{
		ShowWindow(m_hwnd, SW_HIDE);
	}

	void Button::Show() const
	{
		ShowWindow(m_hwnd, SW_SHOW);
	}

	void Button::SetText(const LPCWSTR& text)
	{
		SetDlgItemText(m_hwnd, m_WidgetID, text);
	}
}
