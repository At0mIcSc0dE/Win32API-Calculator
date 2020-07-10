#include "Sandbox.h"


size_t allocsize = 0;
void* operator new(size_t size)
{
	allocsize += size;
	return malloc(size);
}


int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR nCmdLine, int nCmdShow)
{
	CL_CLEAR();
	CL_LOG("Application started");
	
	Sandbox sandbox;
	sandbox.Init(nCmdShow);

	sandbox.Run();

	std::stringstream ss;
	ss << "Application allocated " << allocsize << " bytes of memory";
	CL_LOG(ss.str());		//- approx. 184 bytes for logging

	return 0;

}
