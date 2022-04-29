
/**
 *	Include Header
 */
#include "WString.h"



 /**
  *	Include SStream
  */
#include <sstream>



namespace ING {

	namespace Utils {

		std::wstring ToWString(const wchar_t* content) {

			std::wstring result = content;

			return result;

		}

		std::wstring ToWString(char content) {

			std::wstring result;

			result += content;

			return result;

		}

		std::wstring ToWString(int content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring ToWString(unsigned int content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring ToWString(long content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring ToWString(unsigned long content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring ToWString(float content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring ToWString(double content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring ToWString(void* content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring ToWString(size_t content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring ToWString(const std::string& content) {

			std::wstring s(content.length(), ' ');

			for (size_t i = 0; i < content.length(); ++i) {

				s[i] = (wchar_t)content[i];

			}

			return s;

		}

	}

}