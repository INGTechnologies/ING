#pragma once

#ifdef ING_SDK_LIB_EXPORTS
#define ING_SDK_API __declspec(dllexport)
#define ING_SDK_EXTERN
#else
#define ING_SDK_API __declspec(dllimport)
#define ING_SDK_EXTERN extern
#endif