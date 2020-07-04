/**
* File containing Application class definitions
*/

#include "pch.h"
#include "Application.h"

namespace Calculator
{
	
	Application* Application::m_Application = new Application();

	bool Application::Init(const int& nCmdShow)
	{
		m_Win.SetEventCallback(SET_EVENT_FN(OnEvent));
		if (!m_Win.CreateMainWindow(L"Calculator", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 0UL, CW_USEDEFAULT, CW_USEDEFAULT, 0x14F, 0x21E))	//335, 542
		{
			return false;
		}

		ShowWindow(m_Win.GetHWND(), nCmdShow);
		return true;
	}

	void Application::Run()
	{
		MSG msg = {};
		while (GetMessage(&msg, NULL, NULL, NULL))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	void Application::OnEvent(Event& e)
	{
		//switch (LOWORD(e))
		//{
		//case 0x0:
		//	MessageBox(NULL, L"Button 1 pressed", L"1", NULL);
		//	break;
		//case 0x1:
		//	MessageBox(NULL, L"Button 2 pressed", L"2", NULL);
		//	break;
		//case 0x2:
		//	MessageBox(NULL, L"Txt 1 pressed", L"3", NULL);
		//	break;
		//default:
		//	break;
		//}
		m_AppData.eventCallback(e);
	}

	Application::~Application()
	{
		delete m_Application;
	}

}