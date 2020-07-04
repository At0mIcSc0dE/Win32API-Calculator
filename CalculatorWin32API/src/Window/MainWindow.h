/**
* File containing the MainWindow class and declarations
*/

#pragma once

#include "BaseWindow.hpp"
#include "Widgets/Button.h"
#include "Widgets/Textfield.h"
#include "Calculator/Core.h"


#define SET_EVENT_FN(func) [this](Calculator::Event& e) { func(e); }

namespace Calculator
{
	typedef WPARAM Event;
	using EventFn = std::function<bool(Event&)>;
	using EventCallbackFn = std::function<void(Event&)>;

	class CL_API MainWindow : public BaseWindow<MainWindow>
	{
	public:

		/**
		* Mainwindow constructor, used to initialize m_Widgets
		*
		* @returns MainWindow instance
		*/
		MainWindow()
			:m_Widgets{} {}

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
		* Deleted copy constructors to allow std::unique_ptr in dll-linkage
		*/
		MainWindow(const MainWindow&) = delete;

		/**
		* Deleted copy constructors to allow std::unique_ptr in dll-linkage
		*/
		MainWindow& operator=(const MainWindow&) = delete;

		/**
		* Sets the event callback function which is called when an event is received
		* Dispatches all Events to Application
		*/
		void SetEventCallback(const EventCallbackFn& eCFn) { m_WinData.eventCallback = eCFn; }

		/**
		* Getter for the std::vector which stores all widgets
		*
		* @returns std::vector of all widgets
		*/
		std::vector<std::unique_ptr<Widget>>& GetWidgets() { return m_Widgets; }

	private:
		std::vector<std::unique_ptr<Widget>> m_Widgets;

		struct WindowData
		{
			EventCallbackFn eventCallback;
		};
		WindowData m_WinData;
	};

}