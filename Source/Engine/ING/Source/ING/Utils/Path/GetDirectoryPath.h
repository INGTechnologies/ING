#pragma once

#include <ING/EntryPoint/EntryPoint.h>

#include <string>

#include "GetRootName.h"

#include <filesystem>



/**
 *	Include String
 */
#include <ING/Utils/String/String.h>



namespace ING {

	namespace Utils {

		namespace Path {

			ING_API WString GetDirectoryPath(const WString& pathStr);

		}

	}

}