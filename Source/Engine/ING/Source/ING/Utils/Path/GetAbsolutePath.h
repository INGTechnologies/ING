#pragma once

#include <ING/EntryPoint/EntryPoint.h>

#include <string>

#include "GetRootName.h"

#include <filesystem>



namespace ING {

	namespace Utils {

		namespace Path {

			ING_API std::string GetAbsolutePath(const std::string& pathStr);

			ING_API std::wstring GetAbsolutePath(const std::wstring& pathStr);

		}

	}

}