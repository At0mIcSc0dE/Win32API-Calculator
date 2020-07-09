#include "Sandbox.h"


Sandbox::Sandbox()
	:m_Application(Calculator::Application::GetApplication())
{
	TIMER;
}

bool Sandbox::Init(int nCmdShow)
{
	TIMER;
	m_Application.Init(nCmdShow);
	m_Application.SetEventCallback(BIND_EVENT_CALLBACK_FN(OnEvent));
	AddWidgets();
	return true;
}

void Sandbox::Run()
{
	m_Application.Run();
}

void Sandbox::AddWidgets()
{
	TIMER;
	m_TxtCalc	=	m_Application.AddWidget<Calculator::Textfield>(L"txt1", 0, 0, 320, 171, m_Application.GetMainWindow().GetHWND());	//320, 503 -> total window

	m_Btn7		=	m_Application.AddWidget<Calculator::Button>(L"7", 0,   171, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_Btn8		=	m_Application.AddWidget<Calculator::Button>(L"8", 80,  171, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_Btn9		=	m_Application.AddWidget<Calculator::Button>(L"9", 160, 171, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_BtnClear	=	m_Application.AddWidget<Calculator::Button>(L"C", 240, 171, 80, 83, m_Application.GetMainWindow().GetHWND());

	m_Btn4		=	m_Application.AddWidget<Calculator::Button>(L"4", 0,   254, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_Btn5		=	m_Application.AddWidget<Calculator::Button>(L"5", 80,  254, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_Btn6		=	m_Application.AddWidget<Calculator::Button>(L"6", 160, 254, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_BtnDivide	=	m_Application.AddWidget<Calculator::Button>(L"/", 240, 254, 80, 83, m_Application.GetMainWindow().GetHWND());
	
	m_Btn1		=	m_Application.AddWidget<Calculator::Button>(L"1", 0,   337, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_Btn2		=	m_Application.AddWidget<Calculator::Button>(L"2", 80,  337, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_Btn3		=	m_Application.AddWidget<Calculator::Button>(L"3", 160, 337, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_BtnTimes	=	m_Application.AddWidget<Calculator::Button>(L"*", 240, 337, 80, 83, m_Application.GetMainWindow().GetHWND());

	m_BtnPlus	=	m_Application.AddWidget<Calculator::Button>(L"+", 0,   420, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_Btn0		=	m_Application.AddWidget<Calculator::Button>(L"0", 80,  420, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_BtnMinus	=	m_Application.AddWidget<Calculator::Button>(L"-", 160, 420, 80, 83, m_Application.GetMainWindow().GetHWND());
	m_BtnEquals	=	m_Application.AddWidget<Calculator::Button>(L"=", 240, 420, 80, 83, m_Application.GetMainWindow().GetHWND());
}


bool Sandbox::TestFn(Calculator::Event& e)
{
	TIMER;
	auto& widgets = m_Application.GetWidgets();
	if (ID(e) == m_Btn1->GetID())
	{
		MessageBox(NULL, L"1", L"1", NULL);
		return true;
	}
	else if (ID(e) == m_TxtCalc->GetID())
	{
		MessageBox(NULL, L"txt1", L"txt1", NULL);
		return true;
	}
	return false;
}


void Sandbox::OnEvent(Calculator::Event& e)
{
	TIMER;
	Calculator::EventDispatcher dispatcher(e);
	for (int i = 0; i < m_Application.GetWidgets().size(); ++i)
	{
		dispatcher.Dispatch(BIND_EVENT_FN(TestFn), m_Application.GetWidgets()[i]);
	}

}
