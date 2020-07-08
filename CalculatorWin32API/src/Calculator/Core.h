#pragma once


#ifdef CL_WINDOWS
	#ifdef CL_BUILD
		#define CL_API __declspec(dllexport)
	#else
		#define CL_API __declspec(dllimport)
	#endif
#else
	#error "Calculator only supports Windows" 
#endif
