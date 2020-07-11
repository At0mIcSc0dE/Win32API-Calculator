/**
* File containing the Button class' definitions
*/

#include "pch.h"
#include "Button.h"


namespace Calculator
{

	void Button::Init(const LPCWSTR& text, const Rect& rect, HWND& parent, int flags)
	{
		m_WidgetID = s_NextID;
		++s_NextID;

		m_hWnd = CreateWindow(L"BUTTON", text, flags, rect.x, rect.y, rect.width, rect.height,
			parent, (HMENU)m_WidgetID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);

		m_hFont = CreateFont(70, 10, 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");
		if (!m_hFont)
		{
			return;
		}
		SendMessage(m_hWnd, WM_SETFONT, (WPARAM)m_hFont, 0);

	}

	void Button::Init(const LPCWSTR& text, int x, int y, int width, int height, HWND& parent, int flags)
	{
		m_WidgetID = s_NextID;
		++s_NextID;

		m_hWnd = CreateWindow(L"BUTTON", text, flags, x, y, width, height,
			parent, (HMENU)m_WidgetID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);

		m_hFont = CreateFont(70, 0, 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");
		if (!m_hFont)
		{
			return;
		}
		SendMessage(m_hWnd, WM_SETFONT, (WPARAM)m_hFont, 0);
	}

	void Button::Resize(int width, int height)
	{
		//TODO: To be implemented
	}

	void Button::Hide() const
	{
		ShowWindow(m_hWnd, SW_HIDE);
	}

	void Button::Show() const
	{
		ShowWindow(m_hWnd, SW_SHOW);
	}
	
	void Button::SetText(const std::wstring& text)
	{
		SetDlgItemText(m_hWnd, m_WidgetID, text.c_str());
	}

	const std::wstring Button::GetText() const
	{
		wchar_t buff[256];
		GetWindowText(m_hWnd, buff, 256);
		return buff;
	}
}
