/**
* File containing the BaseWindow class' declarations and definitions
*/

#pragma once

#include "pch.h"
#include "Calculator/Core.h"


namespace Calculator
{

	template<class DERIVED_TYPE>
	class CL_API BaseWindow
	{
	private:
		static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			DERIVED_TYPE* pThis = NULL;

			if (uMsg == WM_NCCREATE)
			{
				CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
				pThis = (DERIVED_TYPE*)pCreate->lpCreateParams;
				SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pThis);

				pThis->m_hWnd = hWnd;
			}
			else
			{
				pThis = (DERIVED_TYPE*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
			}
			if (pThis)
			{
				return pThis->HandleMessage(uMsg, wParam, lParam);
			}
			else
			{
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
		}

	public:
		BaseWindow()
			:m_hWnd(NULL), wc{} {}

		BOOL CreateMainWindow(
			PCWSTR lpWindowName,
			DWORD dwStyle,
			DWORD dwExStyle = 0,
			int x = CW_USEDEFAULT,
			int y = CW_USEDEFAULT,
			int nWidth = CW_USEDEFAULT,
			int nHeight = CW_USEDEFAULT,
			HWND hWndParent = 0,
			HMENU hMenu = 0)
		{
			wc.lpfnWndProc = DERIVED_TYPE::WindowProc;
			wc.hInstance = GetModuleHandle(NULL);
			wc.lpszClassName = ClassName();

			RegisterClass(&wc);
			m_hWnd = CreateWindowEx(dwExStyle, ClassName(), lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this);

			return (m_hWnd ? TRUE : FALSE);
		}

		HWND GetHWND() const { return m_hWnd; }

		virtual ~BaseWindow() {}

	protected:
		HWND m_hWnd;
		WNDCLASS wc;

		virtual PCWSTR ClassName() const = 0;
		virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
	};

}