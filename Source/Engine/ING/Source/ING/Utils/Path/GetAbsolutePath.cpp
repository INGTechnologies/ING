
/**
 *	Include Header
 */
#include "GetAbsolutePath.h"



#include "Normalize.h"



#include <ING/Utils/Utils.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



namespace ING {

	namespace Utils {

		namespace Path {

			WString GetAbsolutePath(const WString& pathStr) {

				auto rootName = GetRootName(pathStr);

				if (Engine::GetInstance()->IsHaveRootPath(rootName.first)) {

					return Normalize(Engine::GetInstance()->GetRootPath(rootName.first) + pathStr.substr(rootName.second, pathStr.size() - rootName.second));

				}

				return Normalize(pathStr);

			}

		}

	}

}