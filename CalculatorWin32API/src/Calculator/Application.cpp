/**
* File containing Application class definitions
*/

#include "pch.h"
#include "Application.h"

namespace Calculator
{
	
	Application* Application::m_Application = nullptr;

	Application::Application()
		: m_Win(), m_AppData{}
	{
		ASSERT(!m_Application);
		m_Application = this;
	}

	bool Application::Init(const int& nCmdShow)
	{
		//m_Win.SetEventCallback(BIND_EVENT_FN(OnEvent));
		ASSERT(&m_Win);
		ASSERT(m_Application);
		m_Win.SetEventCallback([&](Event& e) { m_Application->OnEvent(e); });
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
		ASSERT(&e);
		m_AppData.eventCallback(e);
	}

	Application::~Application()
	{
	}

}