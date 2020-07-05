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
	}

	void Textfield::Init(const LPCWSTR& name, int x, int y, int width, int height, HWND& parent, int flags)
	{
		m_WidgetID = s_NextID;
		++s_NextID;

		m_hWnd = CreateWindow(L"Edit", name, flags, x, y, width, height,
			parent, (HMENU)m_WidgetID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);
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

    void Textfield::SetText(const LPCWSTR& text)
    {
		SetDlgItemText(m_hWnd, m_WidgetID, text);
    }
}
