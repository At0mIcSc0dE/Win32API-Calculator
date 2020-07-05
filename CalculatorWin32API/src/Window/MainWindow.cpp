/**
* File containing the MainWindow class' definitions
*/

#pragma once

#include "pch.h"
#include "MainWindow.h"
#include "Calculator/StringEvaluator.h"

#include <Dwmapi.h>

#include "Widgets/Button.h"


#define RECTWIDTH(rc)			(rc.right - rc.left)
#define RECTHEIGHT(rc)			(rc.bottom - rc.top)

#define LEFTEXTENDWIDTH			8
#define RIGHTEXTENDWIDTH		8
#define BOTTOMEXTENDWIDTH		20
#define TOPEXTENDWIDTH			33
#define TOPEXTENDWIDTH_ZOOM		33

#define BIT_COUNT				32

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#endif
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))
#endif

#define TMT_CAPTIONFONT			1

namespace Calculator
{

	void my_paint(HDC hdc, RECT rc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 128, 0));
		FillRect(hdc, &rc, brush);
		DeleteObject(brush);
	}

	LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		static RECT border_thickness;
		switch (uMsg)
		{
		case WM_CREATE:
		{
			//find border thickness
			SetRectEmpty(&border_thickness);
			if (GetWindowLongPtr(m_hwnd, GWL_STYLE) & WS_THICKFRAME)
			{
				AdjustWindowRectEx(&border_thickness, GetWindowLongPtr(m_hwnd, GWL_STYLE) & ~WS_CAPTION, FALSE, NULL);
				border_thickness.left *= -1;
				border_thickness.top *= -1;
			}
			else if (GetWindowLongPtr(m_hwnd, GWL_STYLE) & WS_BORDER)
			{
				SetRect(&border_thickness, 1, 1, 1, 1);
			}

			MARGINS margins = { 0 };
			DwmExtendFrameIntoClientArea(m_hwnd, &margins);
			SetWindowPos(m_hwnd, NULL, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
			break;

		}
		return 0;
		case WM_ACTIVATE:
		{
			MARGINS margins;
			margins.cxLeftWidth = 8;		// 8
			margins.cxRightWidth = 8;		// 8
			margins.cyBottomHeight = 20;	// 20
			margins.cyTopHeight = 0;		// 27

			HRESULT hr = DwmExtendFrameIntoClientArea(m_hwnd, &margins);
			if (!SUCCEEDED(hr))
			{
				MessageBox(NULL, L"Failed to extend", L"", NULL);
			}

		}
		return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_CLOSE:
		{
			DestroyWindow(m_hwnd);
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
			HDC hdc = BeginPaint(m_hwnd, &ps);

			RECT rc = ps.rcPaint;
			BP_PAINTPARAMS params = { sizeof(params), BPPF_NOCLIP | BPPF_ERASE };
			HDC memdc;
			HPAINTBUFFER hbuffer = BeginBufferedPaint(hdc, &rc, BPBF_TOPDOWNDIB, &params, &memdc);

			my_paint(memdc, rc);

			BufferedPaintSetAlpha(hbuffer, &rc, 255);
			EndBufferedPaint(hbuffer, TRUE);

			EndPaint(m_hwnd, &ps);
			return 0;
		}
		case WM_NCCALCSIZE:
			if (lParam)
			{
				NCCALCSIZE_PARAMS* sz = (NCCALCSIZE_PARAMS*)lParam;
				sz->rgrc[0].left += border_thickness.left;
				sz->rgrc[0].right -= border_thickness.right;
				sz->rgrc[0].bottom -= border_thickness.bottom;
				return 0;
			}
			break;
		return 0;
		case WM_NCHITTEST:
		{
			//do default processing, but allow resizing from top-border
			LRESULT result = DefWindowProc(m_hwnd, uMsg, wParam, lParam);
			if (result == HTCLIENT)
			{
				POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
				ScreenToClient(m_hwnd, &pt);
				if (pt.y < border_thickness.top) return HTTOP;
			}
			return result;
		}
		default:
			return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
		}
		return TRUE;
	}

	MainWindow::~MainWindow()
	{
	}

}
