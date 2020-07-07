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

	Calculator::Button* m_Btn1;
	Calculator::Button* m_Btn2;
	Calculator::Button* m_Btn3;
	Calculator::Textfield* m_Txt1;
};

