
/**
 *	Include Header
 */
#include "GetAbsolutePath.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



namespace ING {

	namespace Utils {

		namespace Path {

			std::string cwd = std::filesystem::current_path().u8string();
			std::wstring cwd_wstr = std::filesystem::current_path().wstring();

			std::string GetAbsolutePath(const std::string& pathStr) {

				auto rootName = GetRootName(pathStr);

				if (rootName.first == "CWD") {

					if (pathStr.size() > rootName.second) {

						return cwd + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

					}
					else {

						return cwd;

					}

				}
				else if (rootName.first == "CWD/../") {

					if (pathStr.size() > rootName.second) {

						return cwd + "/../" + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

					}
					else {

						return cwd;

					}

				}
				else if (rootName.first == "Content") {

					if (pathStr.size() > rootName.second) {

						return Application::GetInstance()->GetContentDir() + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

					}
					else {

						return Application::GetInstance()->GetContentDir();

					}

				}
				else if (rootName.first == "Engine") {

					if (pathStr.size() > rootName.second) {

						return cwd + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

					}
					else {

						return cwd;

					}

				}

				return pathStr;

			}

			std::wstring GetAbsolutePath(const std::wstring& pathStr) {

				auto rootName = GetRootName(pathStr);

				if (rootName.first == L"CWD") {

					if (pathStr.size() > rootName.second) {

						return cwd_wstr + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

					}
					else {

						return cwd_wstr;

					}

				}
				else if (rootName.first == L"CWD/../") {

					if (pathStr.size() > rootName.second) {

						return cwd_wstr + L"/../" + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

					}
					else {

						return cwd_wstr + L"/../";

					}

				}
				else if (rootName.first == L"Content") {

					if (pathStr.size() > rootName.second) {

						return Application::GetInstance()->GetContentDir_WSTR() + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

					}
					else {

						return Application::GetInstance()->GetContentDir_WSTR();

					}

				}
				else if (rootName.first == L"Engine") {

					if (pathStr.size() > rootName.second) {

						return cwd_wstr + pathStr.substr(rootName.second, pathStr.size() - rootName.second);

					}
					else {

						return cwd_wstr;

					}

				}

				return pathStr;

			}

		}

	}

}