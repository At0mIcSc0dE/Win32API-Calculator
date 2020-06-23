#include "pch.h"

#include "Calculator/Application.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Application& app = Application::GetApplication();
	app.Init(nCmdShow);
	app.Run();

	return 0;
}