#pragma once

/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#if PLUGIN_EXPORTS($(INGPluginVarName)) > 0
#define $(INGPluginVarName)_API __declspec(dllexport)
#define $(INGPluginVarName)_PRIVATE_API __declspec(dllexport)
#define $(INGPluginVarName)_EXTERN
#else
#define $(INGPluginVarName)_API __declspec(dllimport)
#ifndef IS_PLUGIN
#define $(INGPluginVarName)_PRIVATE_API __declspec(dllimport)
#else
#define $(INGPluginVarName)_PRIVATE_API
#endif
#define $(INGPluginVarName)_EXTERN extern
#endif