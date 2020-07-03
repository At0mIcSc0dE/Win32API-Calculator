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
	* Getter for the application
	*
	* @returns currently running application
	*/
	Calculator::Application& GetApplication() const { return m_Application; }

private:
	Calculator::Application& m_Application;
};

