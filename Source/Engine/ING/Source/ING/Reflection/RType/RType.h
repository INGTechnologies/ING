#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Reflection {

		namespace RType{

			template<typename T>
			using Pointer = T*;

			template<class T>
			using Object = T*;

			template<typename T>
			using Struct = T;

			template<typename T>
			using Union = T;

			template<typename T>
			using Enum = T;

			using Void = char;

			template<typename T>
			using Primitive = T;

		}

	}

}