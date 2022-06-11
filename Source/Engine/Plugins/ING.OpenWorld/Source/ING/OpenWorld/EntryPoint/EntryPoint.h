#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS(ING_OPENWORLD) > 0
#define ING_OPENWORLD_API __declspec(dllexport)
#define ING_OPENWORLD_PRIVATE_API __declspec(dllexport)
#define ING_OPENWORLD_EXTERN
#else
#define ING_OPENWORLD_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define ING_OPENWORLD_PRIVATE_API __declspec(dllimport)
#else
#define ING_OPENWORLD_PRIVATE_API
#endif
#define ING_OPENWORLD_EXTERN extern
#endif