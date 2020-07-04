#include "Sandbox.h"


Sandbox::Sandbox()
	:m_Application(Calculator::Application::GetApplication())
{
}

bool Sandbox::Init(const int& nCmdShow)
{
	m_Application.Init(nCmdShow);
	m_Application.SetEventCallback(SET_EVENT_FN(OnEvent));
	AddWidgets();
	return true;
}

void Sandbox::Run()
{
	m_Application.Run();
}

void Sandbox::AddWidgets()
{
	m_Application.AddWidget<Calculator::Button>(L"1", 10, 40, 90, 30, m_Application.GetMainWindow().GetHWND());
	m_Application.AddWidget<Calculator::Button>(L"2", 10, 10, 90, 30, m_Application.GetMainWindow().GetHWND());
	m_Application.AddWidget<Calculator::Textfield>(L"txt1", 10, 90, 90, 30, m_Application.GetMainWindow().GetHWND());
}

void Sandbox::OnEvent(Calculator::Event& e)
{
	//Dispatch Events here
}
