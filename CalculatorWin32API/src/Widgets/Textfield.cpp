#include "pch.h"
#include "Textfield.h"


namespace Calculator
{
	void Textfield::Init(const LPCWSTR& name, const Rect& rect, HWND& parent, const int& flags)
	{
		m_TextfieldID = s_NextID;
		++s_NextID;

		m_hwndTextfield = CreateWindow(L"Edit", name, flags, rect.x, rect.y, rect.width, rect.height,
			parent, (HMENU)m_TextfieldID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);
	}

	void Textfield::Init(const LPCWSTR& name, const int& x, const int& y, const int& width, const int& height, HWND& parent, const int& flags)
	{
		m_TextfieldID = s_NextID;
		++s_NextID;

		m_hwndTextfield = CreateWindow(L"Edit", name, flags, x, y, width, height,
			parent, (HMENU)m_TextfieldID, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), NULL);
	}

    void Textfield::Resize(const int& width, const int& height)
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

    }
}
