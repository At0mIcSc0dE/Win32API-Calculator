/**
* File containing the MainWindow class' definitions
*/

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
		case WM_CREATE:
		{

		}
		return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_CLOSE:
		{
			DestroyWindow(m_hWnd);
			UnregisterClass(ClassName(), GetModuleHandle(NULL));
		}
		case WM_LBUTTONDOWN:
		{
		}
		return 0;
		case WM_COMMAND:
		{

			m_WinData.eventCallback(wParam);
		
		}
		return 0;
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(m_hWnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
			EndPaint(m_hWnd, &ps);
		}
		return 0;
		default:
			return DefWindowProc(m_hWnd, uMsg, wParam, lParam);
		}
		return TRUE;
	}

	MainWindow::~MainWindow()
	{
	}

}
