/**
* File containing Application class definitions
*/

#include "pch.h"
#include "Application.h"

namespace Calculator
{
	
	Application* Application::m_Application = new Application();

	bool Application::Init(int nCmdShow)
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
		m_AppData.eventCallback(e);
	}

	Application::~Application()
	{
	}

}