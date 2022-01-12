#pragma once

#ifdef ING_EXPORTS
#define ING_API __declspec(dllexport)
#define ING_EXTERN
#else
#define ING_API __declspec(dllimport)
#define ING_EXTERN extern
#endif