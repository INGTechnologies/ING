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

		enum TypeGroup {

			TYPE_GROUP_NONE = 0x0,

			TYPE_GROUP_C_OBJECT = 0x1,

			TYPE_GROUP_S_OBJECT = 0x2,

			TYPE_GROUP_BOOL = 0x4,

			TYPE_GROUP_INT = 0x8,
			TYPE_GROUP_UINT = 0x10,

			TYPE_GROUP_FLOAT = 0x20,
			TYPE_GROUP_UFLOAT = 0x40,

			TYPE_GROUP_STRING = 0x80,
			TYPE_GROUP_WSTRING = 0x100,

			TYPE_GROUP_VECTOR2 = 0x200,
			TYPE_GROUP_VECTOR3 = 0x400,
			TYPE_GROUP_VECTOR4 = 0x800,

			TYPE_GROUP_ARRAY = 0x1000

		};

	}

}