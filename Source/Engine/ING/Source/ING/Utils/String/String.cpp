
/**
 *	Include Header
 */
#include "String.h"



/**
 *	Include SStream
 */
#include <sstream>



namespace ING {

	namespace Utils {
		
		std::string ToString(const char* content) {

			std::string result = content;

			return result;

		}

		std::string ToString(char content) {

			std::string result;

			result += content;

			return result;

		}

		std::string ToString(int content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string ToString(unsigned int content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string ToString(long content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string ToString(unsigned long content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string ToString(float content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string ToString(void* content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string ToString(size_t content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string ToString(const std::wstring& content) {

			std::string s(content.length(), ' ');

			for (size_t i = 0; i < content.length(); ++i) {

				s[i] = (char)content[i];

			}

			return s;

		}

	}

}