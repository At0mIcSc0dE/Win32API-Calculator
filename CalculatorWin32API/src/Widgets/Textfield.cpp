#include "pch.h"
#include "Textfield.h"


namespace Calculator
{
	void Textfield::Init(const LPCWSTR& name, const Rect& rect, HWND& parent, int flags)
	{
		m_WidgetID = s_NextID;
		++s_NextID;

		m_hWnd = CreateWindow(L"Edit", name, flags, rect.x, rect.y, rect.width, rect.height,
			parent, (HMENU)m_WidgetID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);

		m_hFont = CreateFont(60, 0, 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");
		if (!m_hFont)
		{
			return;
		}
		SendMessage(m_hWnd, WM_SETFONT, (WPARAM)m_hFont, 0);
	}

	void Textfield::Init(const LPCWSTR& name, int x, int y, int width, int height, HWND& parent, int flags)
	{
		m_WidgetID = s_NextID;
		++s_NextID;

		m_hWnd = CreateWindow(L"Edit", name, flags, x, y, width, height,
			parent, (HMENU)m_WidgetID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);

		m_hFont = CreateFont(60, 0, 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");
		if (!m_hFont)
		{
			return;
		}
		SendMessage(m_hWnd, WM_SETFONT, (WPARAM)m_hFont, 0);
	}

    void Textfield::Resize(int width, int height)
    {

    }

    void Textfield::Show() const
    {

    }

    void Textfield::Hide() const
    {

    }

    void Textfield::SetText(const std::wstring& text)
    {
		//SetDlgItemText(m_hWnd, m_WidgetID, text.c_str());
		SetWindowText(m_hWnd, text.c_str());
    }

	const std::wstring Textfield::GetText() const
	{
		wchar_t buff[256];
		GetWindowText(m_hWnd, buff, 256);
		return buff;
	}
}
