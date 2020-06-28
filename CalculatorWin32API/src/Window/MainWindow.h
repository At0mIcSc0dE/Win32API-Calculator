/**
* File containing the MainWindow class and declarations
*/

#pragma once

#include "BaseWindow.hpp"
#include "Widgets/Button.h"

namespace Calculator
{

	class MainWindow : public BaseWindow<MainWindow>
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
		virtual PCWSTR ClassName() const override { return L"MAINWINDOWCLASS"; }

		MainWindow() = default;

	private:
		Button btn;
		Button btn2;
	};

}