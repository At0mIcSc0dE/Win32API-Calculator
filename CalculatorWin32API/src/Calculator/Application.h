/**
* File containing Application class declarations
*/

#pragma once

#include "Window/MainWindow.h"

#define ADD_WIDGET(widget) m_Win.


namespace Calculator
{

	class Application
	{
	protected:
		Application() {}
	public:
		/**
		* Function has to be called after getting an Application& using the Getter
		*
		* @param nCmdShow is the nCmdShow of the main function
		* @see const MainWindow& GetMainWindow() const function
		*/
		bool Init(
			_In_ const int& nCmdShow
		);

		/**
		* Starts application loop
		*/
		void Run();

		/**
		* Static function to get static Application instance
		*/
		static Application& GetApplication() { return *m_Application; }

		/**
		* @param name is the name which the widget will be accesible in the unordered_map
		* @param args are the arguments to initialize the widget
		* @returns false if incorrect arguments for WIDGET type were provided
		*
		* @warning EXPERIMENTAL APPROACH
		* @warning currently does not return false when passing the wrong arguments
		*/
		template<typename WIDGET, typename... Args>
		bool AddWidget(const wchar_t* name, Args... args);

		/**
		* Getter for MainWindow
		*
		* @returns the main window
		*/
		const MainWindow& GetMainWindow() const { return m_Win; }

		~Application();

	private:
		static Application* m_Application;
		MainWindow m_Win;
	};

	
	template<typename WIDGET, typename ...Args>
	inline bool Application::AddWidget(const wchar_t* name, Args ...args)
	{
		//WIDGET* widget = new WIDGET;
		std::unique_ptr<WIDGET> widget = std::make_unique<WIDGET>();
		widget->Init(args...);
		m_Win.GetWidgets().insert({ name, std::move(widget) });

		return true;
	}

}