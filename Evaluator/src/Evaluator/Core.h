#pragma once

#ifdef EV_WINDOWS
	#ifdef EV_BUILD
		#define EV_API __declspec(dllexport)
	#else
		#define EV_API __declspec(dllimport)
	#endif
#else
	#error "Evaluator only supports windows"
#endif


#define EV_LOG_ACTIVE 1
#define EV_TIMER_ACTIVE 1
