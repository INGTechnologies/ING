#pragma once

#ifdef ING_SHADERCOMPILER_LIB_EXPORTS
#define ING_SHADERCOMPILER_API __declspec(dllexport)
#define ING_SHADERCOMPILER_EXTERN
#else
#define ING_SHADERCOMPILER_API __declspec(dllimport)
#define ING_SHADERCOMPILER_EXTERN extern
#endif