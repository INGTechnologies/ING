
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
		
		std::string String(const char* content) {

			std::string result = content;

			return result;

		}

		std::string String(char content) {

			std::string result;

			result += content;

			return result;

		}

		std::string String(int content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string String(unsigned int content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string String(long content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string String(unsigned long content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string String(float content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string String(void* content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string String(size_t content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		std::string String(const std::wstring& content) {

			std::string s(content.length(), ' ');

			for (size_t i = 0; i < content.length(); ++i) {

				s[i] = (char)content[i];

			}

			return s;

		}

	}

}