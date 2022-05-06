#pragma once

#ifdef DEMO_EXPORTS
#define DEMO_API __declspec(dllexport)
#define DEMO_EXTERN
#else
#define DEMO_API __declspec(dllimport)
#define DEMO_EXTERN extern
#endif