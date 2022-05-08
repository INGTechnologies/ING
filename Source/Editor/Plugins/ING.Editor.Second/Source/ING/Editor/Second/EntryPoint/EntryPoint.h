#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS(ING_EDITOR_SECOND) > 0
#define ING_EDITOR_SECOND_API __declspec(dllexport)
#define ING_EDITOR_SECOND_PRIVATE_API __declspec(dllexport)
#define ING_EDITOR_SECOND_EXTERN
#else
#define ING_EDITOR_SECOND_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define ING_EDITOR_SECOND_PRIVATE_API __declspec(dllimport)
#else
#define ING_EDITOR_SECOND_PRIVATE_API
#endif
#define ING_EDITOR_SECOND_EXTERN extern
#endif