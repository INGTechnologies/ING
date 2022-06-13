#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS(ING_STANDARDRP) > 0
#define ING_STANDARDRP_API __declspec(dllexport)
#define ING_STANDARDRP_PRIVATE_API __declspec(dllexport)
#define ING_STANDARDRP_EXTERN
#else
#define ING_STANDARDRP_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define ING_STANDARDRP_PRIVATE_API __declspec(dllimport)
#else
#define ING_STANDARDRP_PRIVATE_API
#endif
#define ING_STANDARDRP_EXTERN extern
#endif