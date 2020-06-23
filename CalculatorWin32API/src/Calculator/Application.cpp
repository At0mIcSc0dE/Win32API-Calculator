#include "pch.h"
#include "Application.h"


Application* Application::m_Application = new Application();

bool Application::Init(int nCmdShow)
{
	if (!m_Win.CreateMainWindow(L"Calculator", WS_OVERLAPPEDWINDOW))
	{
		return false;
	}

	ShowWindow(m_Win.GetMainWindow(), nCmdShow);

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

Application::~Application()
{
	delete m_Application;
}
