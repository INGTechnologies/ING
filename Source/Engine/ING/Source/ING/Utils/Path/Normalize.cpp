
/**
 *	Include Header
 */
#include "Normalize.h"



#include <ING/Utils/Utils.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



namespace ING {

	namespace Utils {

		namespace Path {

			WString Normalize(const WString& pathStr) {

				WString result = L"";

				for (unsigned int i = 0; i < pathStr.length(); ++i) {

					if (result.length() == 0) {

						result += pathStr[i];

						continue;
					}

					if (
						(
							pathStr[i] == L'\\'
							|| pathStr[i] == L'/'
						)
						&&
						(
							result[result.length() - 1] == L'\\'
							|| result[result.length() - 1] == L'/'
						)
					)
					{

						continue;

					}

#ifdef USE_MSVC
					if (pathStr[i] == L'/') {

						result += L'\\';

						continue;

					}
#endif

					result += pathStr[i];

				}

				return result;

			}

		}

	}

}