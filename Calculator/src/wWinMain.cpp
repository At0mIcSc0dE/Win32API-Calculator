#include "Sandbox.h"


int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR nCmdLine, int nCmdShow)
{
	Sandbox sandbox;
	sandbox.Init(nCmdShow);
	sandbox.Run();

	return 0;

}
