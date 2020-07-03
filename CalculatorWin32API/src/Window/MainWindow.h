/**
* File containing the MainWindow class and declarations
*/

#pragma once

#include "BaseWindow.hpp"
#include "Widgets/Button.h"
#include "Widgets/Textfield.h"
#include "Calculator/Core.h"


namespace Calculator
{

	class CL_API MainWindow : public BaseWindow<MainWindow>
	{
	public:
		/**
		* Function is called by WindowProc in BaseWindow class. 
		* HandleMessages receives all window messages sent out by the operating system
		*
		* @param uMsg is the current message code
		* @param wParam is the window's WPARAM and is used for determining which button was pressed
		* @param lParam is the window's LPARAM
		*
		* @returns LRESULT to the operating system
		*/
		virtual LRESULT HandleMessage(
			_In_ UINT uMsg, 
			_In_ WPARAM wParam, 
			_In_ LPARAM lParam
		) override;

		/**
		* Defines the name of the window class.
		*
		* @returns the name of the window class, user defined
		*/
		virtual PCWSTR ClassName() const override { return L"MAINWINDOW"; }

		/**
		* MainWindow destructor
		*/
		~MainWindow();

		/**
		* Getter for the std::vector which stores all widgets
		*
		* @returns std::vector of all widgets
		*/
		std::vector<std::unique_ptr<Widget>>& GetWidgets() { return m_Widgets; }

		/**
		* Deleted copy constructors to allow std::unique_ptr in dll-linkage
		*/
		MainWindow(const MainWindow&) = delete;

		/**
		* Deleted copy constructors to allow std::unique_ptr in dll-linkage
		*/
		MainWindow& operator=(const MainWindow&) = delete;

	private:
		std::vector<std::unique_ptr<Widget>> m_Widgets;
	
	protected:
		/**
		* Mainwindow constructor, used to initialize m_Widgets
		*
		* @returns MainWindow instance
		*/
		MainWindow()
			:m_Widgets{} {}
	};

}