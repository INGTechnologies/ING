#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS(DEMO_PLUGIN_3) > 0
#define DEMO_PLUGIN_3_API __declspec(dllexport)
#define DEMO_PLUGIN_3_PRIVATE_API __declspec(dllexport)
#define DEMO_PLUGIN_3_EXTERN
#else
#define DEMO_PLUGIN_3_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define DEMO_PLUGIN_3_PRIVATE_API __declspec(dllimport)
#else
#define DEMO_PLUGIN_3_PRIVATE_API
#endif
#define DEMO_PLUGIN_3_EXTERN extern
#endif