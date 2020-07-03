#include "Sandbox.h"


int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR nCmdLine, int nCmdShow)
{
	Sandbox sandbox;
	sandbox.Init(nCmdShow);
	sandbox.AddWidgets();
	sandbox.Run();

	return 0;

}
