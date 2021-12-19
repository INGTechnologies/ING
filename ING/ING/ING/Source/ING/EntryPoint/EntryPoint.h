#pragma once

#ifdef ING_EXPORTS
#define ING_API __declspec(dllexport)
#else
#define ING_API __declspec(dllimport)
#endif