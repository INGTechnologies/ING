
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

			String cwd = std::filesystem::current_path().u8string();
			WString cwd_wstr = std::filesystem::current_path().wstring();

			String GetAbsolutePath(const String& pathStr) {

				auto rootName = GetRootName(pathStr);

				const WString rootName_wstr = ToWString(rootName.first);

				if (Engine::GetInstance()->IsHaveRootPath(rootName_wstr)) {

					return ToString(Engine::GetInstance()->GetRootPath(rootName_wstr)) + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

				}

				return pathStr;

			}

			WString GetAbsolutePath(const WString& pathStr) {

				auto rootName = GetRootName(pathStr);

				if (Engine::GetInstance()->IsHaveRootPath(rootName.first)) {

					return Engine::GetInstance()->GetRootPath(rootName.first) + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

				}

				return pathStr;

			}

		}

	}

}