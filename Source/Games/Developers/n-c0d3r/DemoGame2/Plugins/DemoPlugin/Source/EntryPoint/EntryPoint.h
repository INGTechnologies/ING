#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS(DEMO_PLUGIN) > 0
#define DEMO_PLUGIN_API __declspec(dllexport)
#define DEMO_PLUGIN_PRIVATE_API __declspec(dllexport)
#define DEMO_PLUGIN_EXTERN
#else
#define DEMO_PLUGIN_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define DEMO_PLUGIN_PRIVATE_API __declspec(dllimport)
#else
#define DEMO_PLUGIN_PRIVATE_API
#endif
#define DEMO_PLUGIN_EXTERN extern
#endif