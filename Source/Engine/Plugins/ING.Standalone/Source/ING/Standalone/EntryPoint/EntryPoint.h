#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS(ING_STANDALONE) > 0
#define ING_STANDALONE_API __declspec(dllexport)
#define ING_STANDALONE_PRIVATE_API __declspec(dllexport)
#define ING_STANDALONE_EXTERN
#else
#define ING_STANDALONE_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define ING_STANDALONE_PRIVATE_API __declspec(dllimport)
#else
#define ING_STANDALONE_PRIVATE_API
#endif
#define ING_STANDALONE_EXTERN extern
#endif