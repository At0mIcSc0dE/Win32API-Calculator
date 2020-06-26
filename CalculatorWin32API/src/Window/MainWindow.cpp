#pragma once
#include "pch.h"
#include "MainWindow.h"
#include "Calculator/StringEvaluator.h"

#include "Widgets/Button.h"


namespace Calculator
{

	LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_CLOSE:
		{
			DestroyWindow(m_hwnd);
		}
		case WM_LBUTTONDOWN:
		{
			Button btn(L"Hello", { 10, 10, 90, 30 }, m_hwnd, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
		}
		return 0;
		case WM_COMMAND:
		{
			MessageBox(NULL, L"JFDDSKLJF", L"JFKD", NULL);
		}
		return 0;
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(m_hwnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
			EndPaint(m_hwnd, &ps);
		}
		return 0;
		default:
			return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
		}
		return TRUE;
	}

}