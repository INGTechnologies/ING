
/**
 *	Include Header
 */
#include "GetDirectoryPath.h"



#include <ING/Utils/Utils.h>



namespace ING {

	namespace Utils {

		namespace Path {

			WString GetDirectoryPath(const WString& pathStr) {

				return std::filesystem::path(pathStr).parent_path().wstring();

			}

		}

	}

}