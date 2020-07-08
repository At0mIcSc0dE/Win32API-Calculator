#pragma once
#include <CalculatorAPI.h>


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
		_In_ const int& nCmdShow
	);
	
	/**
	* Enters the application event loop
	*/
	[[noreturn]] void Run();
	
	/**
	* Adds all widgets defined in function definition to application
	*/
	[[noreturn]] void AddWidgets();

	/**
	* Receives all events from Calculator::Application, should dispatch them to seperate functions
	*/
	[[noreturn]] virtual void OnEvent(Calculator::Event& e) override;

	/**
	* Getter for the application
	*
	* @returns currently running application
	*/
	Calculator::Application& GetApplication() const { return m_Application; }

	bool TestFn(Calculator::Event& e);

private:
	Calculator::Application& m_Application;

	Calculator::Button* m_Btn1 = nullptr;
	Calculator::Button* m_Btn2 = nullptr;
	Calculator::Button* m_Btn3 = nullptr;
	Calculator::Button* m_Btn4 = nullptr;
	Calculator::Button* m_Btn5 = nullptr;
	Calculator::Button* m_Btn6 = nullptr;
	Calculator::Button* m_Btn7 = nullptr;
	Calculator::Button* m_Btn8 = nullptr;
	Calculator::Button* m_Btn9 = nullptr;
	Calculator::Button* m_Btn0 = nullptr;
	Calculator::Button* m_BtnEquals = nullptr;
	Calculator::Button* m_BtnPlus = nullptr;
	Calculator::Button* m_BtnMinus = nullptr;
	Calculator::Button* m_BtnTimes = nullptr;
	Calculator::Button* m_BtnDivide = nullptr;
	Calculator::Button* m_BtnClear = nullptr;

	Calculator::Textfield* m_TxtCalc = nullptr;
};

