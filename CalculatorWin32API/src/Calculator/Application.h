/**
* File containing Application class declarations
*/

#pragma once

#include "Core.h"
#include "Window/MainWindow.h"


namespace Calculator
{

	class CL_API Application
	{
	protected:
		Application() : m_Win() {}
	
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
		[[noreturn]] void Run();

		/**
		* Static function to get static Application instance
		*/
		static Application& GetApplication() { return *m_Application; }

		/**
		* Adds a widget to the window (parent variable)
		*
		* @param name is the name which the widget will be accesible in the unordered_map
		* @param args are the arguments to initialize the widget
		* @returns false if incorrect arguments for WIDGET type were provided
		*
		* @warning EXPERIMENTAL APPROACH
		* @warning currently does not return false when passing the wrong arguments
		*/
		template<typename WIDGET, typename... Args>
		bool AddWidget(Args... args);

		/**
		* Receives all Events,  
		* calls m_AppData.eventCallback defined by the client in function SetEventCallback
		*
		* @see Calculator::Application::SetEventCallback(const EventCallbackFn& eCFn)
		*/
		virtual void OnEvent(Event& e);

		/**
		* Getter for MainWindow
		*
		* @returns the main window
		*/
		const MainWindow& GetMainWindow() const { return m_Win; }

		/**
		* Casts a object of type Widget to template argument
		*
		* @param index is the widget's index in the vector
		* @returns a reference of type WIDGET
		* @throws std::bad_cast if widgets[index] can't be casted to WIDGET
		*/
		template<typename WIDGET>
		const WIDGET& CastToWidget(const std::string& name);

		/**
		* Destructor for application
		*/
		virtual ~Application();

		/**
		* Sets the event callback function which is called when an event is received
		*/
		[[noreturn]] void SetEventCallback(const EventCallbackFn& eCFn) { m_AppData.eventCallback = eCFn; }

		Application(const Application& app) = delete;
		Application operator=(const Application& app) = delete;
		
		/**
		* Getter for m_Win widgets
		*
		* @returns a vector of all the widgets in the window
		*/
		std::map<const std::string_view, Widget*>& GetWidgets() { return m_Win.GetWidgets(); }

	private:
		static Application* m_Application;
		MainWindow m_Win;

		struct ApplicationData
		{
			EventCallbackFn eventCallback;
		};
		ApplicationData m_AppData;
	};

	
	template<typename WIDGET, typename ...Args>
	inline bool Application::AddWidget(Args ...args)
	{
		WIDGET* widget = new WIDGET;
		widget->Init(args...);
		//m_Win.GetModifiableWidgets().emplace_back(std::move(widget));
		m_Win.GetWidgets().insert({ "h", std::move(widget) });
		auto& vec = m_Win.GetWidgets();

		return true;
	}

	template<typename WIDGET>
	inline const WIDGET& Application::CastToWidget(const std::string& name)
	{
		//if (WIDGET::GetStaticWidgetType() == m_Win.GetWidgets()[index]->GetWidgetType())
		//	return (WIDGET&)*m_Win.GetWidgets()[index];
		//else
		//	throw std::bad_cast();
		if (WIDGET::GetStaticWidgetType() == m_Win.GetWidgets()["name"]->GetWidgetType())
			return (WIDGET&)*m_Win.GetWidgets()["h"];
		else
			throw std::bad_cast();

	}

}