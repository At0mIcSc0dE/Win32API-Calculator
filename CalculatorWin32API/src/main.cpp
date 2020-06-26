#include "pch.h"

#include "Calculator/Application.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Calculator::Application& app = Calculator::Application::GetApplication();
	app.Init(nCmdShow);
	app.Run();

	return 0;
}