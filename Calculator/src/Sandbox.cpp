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
	m_TxtCalc	=	m_Application.AddWidget<Calculator::Textfield>(L"", 0, 0, 320, 171, m_Application.GetMainWindow().GetHWND());	//320, 503 -> total window

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


bool Sandbox::TestFn(Calculator::Event& e, const Calculator::Widget* w)
{
	auto* button = m_Application.CastToWidget<Calculator::Button>(w);
	
	if (button == m_BtnEquals)
	{
		// Call evaluater here
		Eval::Evaluator::Evaluate<int>(L"3+4");
		return true;
	}
	else if (button == m_BtnClear)
	{
		m_TxtCalc->SetText(L"");
		return true;
	}

	m_TxtCalc->SetText(m_TxtCalc->GetText() + button->GetText());


	return true;
}


void Sandbox::OnEvent(Calculator::Event& e)
{
	Calculator::EventDispatcher dispatcher(e);
	for (unsigned short i = 0; i < m_Application.GetWidgets().size(); ++i)
	{
		if(m_Application.GetWidgets()[i]->GetWidgetType() == Calculator::Button::GetStaticWidgetType())
			dispatcher.Dispatch(BIND_EVENT_FN(TestFn), m_Application.GetWidgets()[i]);
	}

}
