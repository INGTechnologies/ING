
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

		std::wstring WString(const wchar_t* content) {

			std::wstring result = content;

			return result;

		}

		std::wstring WString(char content) {

			std::wstring result;

			result += content;

			return result;

		}

		std::wstring WString(int content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring WString(unsigned int content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring WString(long content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring WString(unsigned long content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring WString(float content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring WString(double content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring WString(void* content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

		std::wstring WString(size_t content) {

			std::wstringstream ss;

			ss << content;

			std::wstring wstr;

			ss >> wstr;

			return wstr;

		}

	}

}