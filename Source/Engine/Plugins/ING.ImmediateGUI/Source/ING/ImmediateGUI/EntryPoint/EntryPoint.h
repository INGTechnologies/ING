#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS(ING_IMMEDIATEGUI) > 0
#define ING_IMMEDIATEGUI_API __declspec(dllexport)
#define ING_IMMEDIATEGUI_PRIVATE_API __declspec(dllexport)
#define ING_IMMEDIATEGUI_EXTERN
#else
#define ING_IMMEDIATEGUI_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define ING_IMMEDIATEGUI_PRIVATE_API __declspec(dllimport)
#else
#define ING_IMMEDIATEGUI_PRIVATE_API
#endif
#define ING_IMMEDIATEGUI_EXTERN extern
#endif