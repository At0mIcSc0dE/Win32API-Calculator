#include "pch.h"

#include "Calculator/Application.h"

#include "Widgets/Button.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Calculator::Application& app = Calculator::Application::GetApplication();
	app.Init(nCmdShow);

	app.AddWidget<Calculator::Button>(L"1", L"1", 10, 40, 90, 30, app.GetMainWindow().GetHWND());
	app.AddWidget<Calculator::Button>(L"2", L"2", 10, 10, 90, 30, app.GetMainWindow().GetHWND());

	app.Run();

	return 0;
}