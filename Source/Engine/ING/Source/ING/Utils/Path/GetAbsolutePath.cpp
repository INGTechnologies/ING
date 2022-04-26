
/**
 *	Include Header
 */
#include "GetAbsolutePath.h"



#include <ING/Utils/Utils.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



namespace ING {

	namespace Utils {

		namespace Path {

			std::string cwd = std::filesystem::current_path().u8string();
			std::wstring cwd_wstr = std::filesystem::current_path().wstring();

			std::string GetAbsolutePath(const std::string& pathStr) {

				auto rootName = GetRootName(pathStr);

				const std::wstring rootName_wstr = WString(rootName.first);

				if (Engine::GetInstance()->IsHaveRootPath(rootName_wstr)) {

					return String(Engine::GetInstance()->GetAbsolutePathFromRootPath(rootName_wstr)) + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

				}

				return pathStr;

			}

			std::wstring GetAbsolutePath(const std::wstring& pathStr) {

				auto rootName = GetRootName(pathStr);

				if (Engine::GetInstance()->IsHaveRootPath(rootName.first)) {

					return Engine::GetInstance()->GetAbsolutePathFromRootPath(rootName.first) + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

				}

				return pathStr;

			}

		}

	}

}