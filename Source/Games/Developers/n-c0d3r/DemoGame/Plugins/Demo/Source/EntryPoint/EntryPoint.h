#pragma once



#ifdef IS_PLUGIN
#define PLUGIN_API __declspec(dllexport)
#define PLUGIN_EXTERN
#else
#define PLUGIN_API __declspec(dllimport)
#define PLUGIN_EXTERN extern
#endif



#define PLUGIN_EVENT \
extern "C" PLUGIN_API