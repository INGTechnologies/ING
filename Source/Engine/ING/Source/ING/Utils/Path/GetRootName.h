#pragma once

#include <string>



/**
 *	Include String
 */
#include <ING/Utils/String/String.h>



namespace ING {

	namespace Utils {

		namespace Path {

			static inline std::pair<WString, unsigned int> GetRootName(const WString& pathStr) {

				size_t chCount = pathStr.size();

				if (
					pathStr == L"." && chCount == 1
					) {

					return std::make_pair<WString, unsigned int>(L"CWD", 1);

				}

				if (
					pathStr == L".."
					) {

					return std::make_pair<WString, unsigned int>(L"CWD/../", 2);

				}

				if (
					(pathStr[0] == L'.' && pathStr[1] == L'/')
					) {

					return std::make_pair<WString, unsigned int>(L"CWD", 1);

				}

				if (
					(pathStr[0] == L'.' && pathStr[1] == L'\\')
					) {

					return std::make_pair<WString, unsigned int>(L"CWD", 1);

				}

				if (
					(pathStr[0] == L'.' && pathStr[1] == L'.' && pathStr[2] == L'/')
					) {

					return std::make_pair<WString, unsigned int>(L"CWD/../", 2);

				}

				if (
					(pathStr[0] == L'.' && pathStr[1] == L'.' && pathStr[2] == L'\\')
					) {

					return std::make_pair<WString, unsigned int>(L"CWD/../", 2);

				}

				for (size_t i = 0; i < chCount; ++i) {

					if (pathStr[i] == L':') {

						return std::make_pair<WString, unsigned int>(pathStr.substr(0, i), (unsigned int)(i + 1));

					}

				}

				return std::make_pair<WString, unsigned int>(L"", 0);

			}

		}

	}

}