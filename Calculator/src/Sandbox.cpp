#include "Sandbox.h"


Sandbox::Sandbox(int nCmdShow)
{
	Calculator::Application& app = Calculator::Application::GetApplication();
	app.Init(nCmdShow);

	app.AddWidget<Calculator::Button>(L"1", 10, 40, 90, 30, app.GetMainWindow().GetHWND());
	app.AddWidget<Calculator::Button>(L"2", 10, 10, 90, 30, app.GetMainWindow().GetHWND());
	app.AddWidget<Calculator::Textfield>(L"txt1", 10, 90, 90, 30, app.GetMainWindow().GetHWND());

	app.Run();
}