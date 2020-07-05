#include "Sandbox.h"


Sandbox::Sandbox()
	:m_Application(Calculator::Application::GetApplication())
{
}

bool Sandbox::Init(const int& nCmdShow)
{
	m_Application.Init(nCmdShow);
	m_Application.SetEventCallback(BIND_EVENT_FN(OnEvent));
	AddWidgets();
	return true;
}

void Sandbox::Run()
{
	m_Application.Run();
}

void Sandbox::AddWidgets()
{
	m_Application.AddWidget<Calculator::Button>(L"0", 10, 40, 90, 30, m_Application.GetMainWindow().GetHWND());
	m_Application.AddWidget<Calculator::Button>(L"1", 10, 10, 90, 30, m_Application.GetMainWindow().GetHWND());
	m_Application.AddWidget<Calculator::Button>(L"2", 10, 70, 90, 30, m_Application.GetMainWindow().GetHWND());
	m_Application.AddWidget<Calculator::Textfield>(L"txt1", 10, 100, 90, 30, m_Application.GetMainWindow().GetHWND());
}


bool Sandbox::TestFn(Calculator::Event& e)
{
	auto& widgets = m_Application.GetWidgets();
	if (ID(e) == widgets[0]->GetID())
	{
		MessageBox(NULL, L"0", L"0", NULL);
		return true;
	}
	else if (ID(e) == widgets[1]->GetID())
	{
		MessageBox(NULL, L"1", L"1", NULL);
		return true;
	}
	else if (ID(e) == widgets[2]->GetID())
	{
		MessageBox(NULL, L"2", L"2", NULL);
		return true;
	}
	else if (ID(e) == widgets[3]->GetID())
	{
		MessageBox(NULL, L"3Txt", L"3", NULL);
		return true;
	}
	else
	{
		return false;
	}
}


void Sandbox::OnEvent(Calculator::Event& e)
{

	Calculator::EventDispatcher dispatcher(e);
	for (int i = 0; i < m_Application.GetWidgets().size(); ++i)
	{
		dispatcher.Dispatch(std::bind(&Sandbox::TestFn, this, std::placeholders::_1), m_Application.GetWidgets()[i]);
	}

}
