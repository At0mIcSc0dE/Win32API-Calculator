#include "Sandbox.h"

int allocsize = 0;
void* operator new(size_t size)
{
	allocsize += size;
	return malloc(size);
}


int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR nCmdLine, int nCmdShow)
{
	Sandbox sandbox;
	sandbox.Init(nCmdShow);

	sandbox.Run();

	wchar_t buff[256];
	wsprintfW(buff, L"%d", allocsize);
	MessageBox(NULL, buff, buff, NULL);

	return 0;

}
