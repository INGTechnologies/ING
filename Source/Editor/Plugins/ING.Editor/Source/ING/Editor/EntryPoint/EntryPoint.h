#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS(ING_EDITOR) > 0
#define ING_EDITOR_API __declspec(dllexport)
#define ING_EDITOR_PRIVATE_API __declspec(dllexport)
#define ING_EDITOR_EXTERN
#else
#define ING_EDITOR_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define ING_EDITOR_PRIVATE_API __declspec(dllimport)
#else
#define ING_EDITOR_PRIVATE_API
#endif
#define ING_EDITOR_EXTERN extern
#endif