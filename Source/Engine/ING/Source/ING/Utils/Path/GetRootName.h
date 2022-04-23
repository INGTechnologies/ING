#pragma once

#include <string>



namespace ING {

	namespace Utils {

		namespace Path {

			static inline std::pair<std::string, unsigned int> GetRootName(const std::string& pathStr) {

				size_t chCount = pathStr.size();

				if (
					pathStr == "." && chCount == 1
				) {

					return std::make_pair<std::string, unsigned int>("CWD", 1);

				}

				if (
					pathStr == ".."
				) {

					return std::make_pair<std::string, unsigned int>("CWD/../", 2);

				}

				if (
					(pathStr[0] == '.' && pathStr[1] == '/')
				) {

					return std::make_pair<std::string, unsigned int>("CWD", 1);

				}

				if (
					(pathStr[0] == '.' && pathStr[1] == '\\')
				) {

					return std::make_pair<std::string, unsigned int>("CWD", 1);

				}

				if (
					(pathStr[0] == '.' && pathStr[1] == '.' && pathStr[2] == '/')
					) {

					return std::make_pair<std::string, unsigned int>("CWD/../", 2);

				}

				if (
					(pathStr[0] == '.' && pathStr[1] == '.' && pathStr[2] == '\\')
					) {

					return std::make_pair<std::string, unsigned int>("CWD/../", 2);

				}

				for (size_t i = 0; i < chCount; ++i) {

					if (pathStr[i] == ':') {

						return std::make_pair<std::string, unsigned int>(pathStr.substr(0, i), (unsigned int)(i + 1));

					}

				}

				return std::make_pair<std::string, unsigned int>("",0);

			}

			static inline std::pair<std::wstring, unsigned int> GetRootName(const std::wstring& pathStr) {

				size_t chCount = pathStr.size();

				if (
					pathStr == L"." && chCount == 1
					) {

					return std::make_pair<std::wstring, unsigned int>(L"CWD", 1);

				}

				if (
					pathStr == L".."
					) {

					return std::make_pair<std::wstring, unsigned int>(L"CWD/../", 2);

				}

				if (
					(pathStr[0] == L'.' && pathStr[1] == L'/')
					) {

					return std::make_pair<std::wstring, unsigned int>(L"CWD", 1);

				}

				if (
					(pathStr[0] == L'.' && pathStr[1] == L'\\')
					) {

					return std::make_pair<std::wstring, unsigned int>(L"CWD", 1);

				}

				if (
					(pathStr[0] == L'.' && pathStr[1] == L'.' && pathStr[2] == L'/')
					) {

					return std::make_pair<std::wstring, unsigned int>(L"CWD/../", 2);

				}

				if (
					(pathStr[0] == L'.' && pathStr[1] == L'.' && pathStr[2] == L'\\')
					) {

					return std::make_pair<std::wstring, unsigned int>(L"CWD/../", 2);

				}

				for (size_t i = 0; i < chCount; ++i) {

					if (pathStr[i] == L':') {

						return std::make_pair<std::wstring, unsigned int>(pathStr.substr(0, i), (unsigned int)(i + 1));

					}

				}

				return std::make_pair<std::wstring, unsigned int>(L"", 0);

			}

		}

	}

}