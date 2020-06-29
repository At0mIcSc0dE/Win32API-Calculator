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
			DestroyWindow(m_hwnd);
		}
		case WM_LBUTTONDOWN:
		{
		}
		return 0;
		case WM_COMMAND:
		{

			/**
			* TODO:
			*	Add something like an event dispatcher which checks what button was pressed
			*	Execute function argument if event matches target event
			*
			* GOAL:
			*	Eliminate the need to create button IDs
			*/

			if (LOWORD(wParam) == m_Widgets[L"btn1"]->GetID())
			{
				MessageBox(NULL, L"Button 1 pressed!", L"1", NULL);
			}
			else if (LOWORD(wParam) == m_Widgets[L"btn2"]->GetID())
			{
				MessageBox(NULL, L"Button 2 pressed!", L"2", NULL);
			}
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

	MainWindow::~MainWindow()
	{
	}

}
