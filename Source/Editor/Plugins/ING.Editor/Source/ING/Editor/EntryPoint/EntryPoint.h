#pragma once



#ifdef ING_EDITOR_EXPORTS
#define ING_EDITOR_API __declspec(dllexport)
#define ING_EDITOR_EXTERN
#else
#define ING_EDITOR_API __declspec(dllimport)
#define ING_EDITOR_EXTERN extern
#endif



#define ING_EDITOR_EVENT \
extern "C" ING_EDITOR_API