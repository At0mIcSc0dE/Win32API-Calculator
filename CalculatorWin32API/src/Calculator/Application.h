#pragma once

#include "Window/MainWindow.h"


class Application
{
protected:
	Application() {}
public:
	
	bool Init(int nCmdShow);
	void Run();
	
	static Application& GetApplication() { return *m_Application; }

	~Application();

private:
	static Application* m_Application;
	MainWindow m_Win;
};

