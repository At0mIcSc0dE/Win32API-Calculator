#include "pch.h"

#include "Calculator/Application.h"

#include "Widgets/Button.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Calculator::Application& app = Calculator::Application::GetApplication();
	app.Init(nCmdShow);

	app.AddWidget<Calculator::Button>(L"1", 100, 100, 100, 100, app.GetMainWindow().GetHWND());

	app.Run();

	return 0;
}