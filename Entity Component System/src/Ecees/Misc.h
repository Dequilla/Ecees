#pragma once

/*
	If you are compiling ecees as a library define
	#define ECEES_EXPORT

	If you are just using ecees as a library in your
	application you don't have to do anything.
*/

#ifdef _WIN32
	#ifdef ECEES_EXPORT
		#define ECEES_API __declspec(dllexport)
	#else
		#define ECEES_API __declspec(dllimport)
	#endif
#endif