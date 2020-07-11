#pragma once

#include <Calculator/CalculatorAPI.h>
#include <Evaluator/EvaluatorAPI.h>


class Sandbox : public Calculator::Application
{
public:
	
	/**
	* Standart contructor for Sandbox, only assingns m_Application with Calculator::Application.GetApplication()
	*
	* @returns new Sandbox instance
	*/
	Sandbox();
	
	/**
	* Initializes the instance
	*
	* @returns true if it initialized it correctly, else false
	* @warning does not currently return anything other than true
	*/
	bool Init(
		_In_ int nCmdShow
	);
	
	/**
	* Enters the application event loop
	*/
	void Run();
	
	/**
	* Adds all widgets defined in function definition to application
	*/
	void AddWidgets();

	/**
	* Receives all events from Calculator::Application, should dispatch them to seperate functions
	*/
	virtual void OnEvent(Calculator::Event& e) override;

	/**
	* Getter for the application
	*
	* @returns currently running application
	*/
	Calculator::Application& GetApplication() const { return m_Application; }

	bool TestFn(Calculator::Event& e, const Calculator::Widget* w);

private:
	Calculator::Application& m_Application;

	Calculator::Button*		m_Btn1;
	Calculator::Button*		m_Btn2;
	Calculator::Button*		m_Btn3;
	Calculator::Button*		m_Btn4;
	Calculator::Button*		m_Btn5;
	Calculator::Button*		m_Btn6;
	Calculator::Button*		m_Btn7;
	Calculator::Button*		m_Btn8;
	Calculator::Button*		m_Btn9;
	Calculator::Button*		m_Btn0;
	Calculator::Button*		m_BtnEquals;
	Calculator::Button*		m_BtnPlus;
	Calculator::Button*		m_BtnMinus;
	Calculator::Button*		m_BtnTimes;
	Calculator::Button*		m_BtnDivide;
	Calculator::Button*		m_BtnClear;

	Calculator::Textfield*	m_TxtCalc;
};

