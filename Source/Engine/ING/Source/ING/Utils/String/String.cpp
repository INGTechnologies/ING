
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
		
		String ToString(const char* content) {

			String result = content;

			return result;

		}

		String ToString(char content) {

			String result;

			result += content;

			return result;

		}

		String ToString(int content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		String ToString(unsigned int content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		String ToString(long content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		String ToString(unsigned long content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		String ToString(float content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		String ToString(void* content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		String ToString(size_t content) {

			std::stringstream ss;

			ss << content;

			return ss.str();

		}

		String ToString(const WString& content) {

			String s(content.length(), ' ');

			for (size_t i = 0; i < content.length(); ++i) {

				s[i] = (char)content[i];

			}

			return s;

		}

		bool Replace(String& str, const String& from, const String& to) {
			size_t start_pos = str.find(from);
			if (start_pos == String::npos)
				return false;
			str.replace(start_pos, from.length(), to);
			return true;
		}

		void ReplaceAll(String& str, const String& from, const String& to) {
			if (from.empty())
				return;
			size_t start_pos = 0;
			while ((start_pos = str.find(from, start_pos)) != String::npos) {
				str.replace(start_pos, from.length(), to);
				start_pos += to.length();
			}
		}




		WString ToWString(const wchar_t* content) {

			WString result = content;

			return result;

		}

		WString ToWString(wchar_t content) {

			WString result;

			result += content;

			return result;

		}

		WString ToWString(int content) {

			std::wstringstream ss;

			ss << content;

			WString wstr;

			ss >> wstr;

			return wstr;

		}

		WString ToWString(unsigned int content) {

			std::wstringstream ss;

			ss << content;

			WString wstr;

			ss >> wstr;

			return wstr;

		}

		WString ToWString(long content) {

			std::wstringstream ss;

			ss << content;

			WString wstr;

			ss >> wstr;

			return wstr;

		}

		WString ToWString(unsigned long content) {

			std::wstringstream ss;

			ss << content;

			WString wstr;

			ss >> wstr;

			return wstr;

		}

		WString ToWString(float content) {

			std::wstringstream ss;

			ss << content;

			WString wstr;

			ss >> wstr;

			return wstr;

		}

		WString ToWString(double content) {

			std::wstringstream ss;

			ss << content;

			WString wstr;

			ss >> wstr;

			return wstr;

		}

		WString ToWString(void* content) {

			std::wstringstream ss;

			ss << content;

			WString wstr;

			ss >> wstr;

			return wstr;

		}

		WString ToWString(size_t content) {

			std::wstringstream ss;

			ss << content;

			WString wstr;

			ss >> wstr;

			return wstr;

		}

		WString ToWString(const String& content) {

			WString s(content.length(), ' ');

			for (size_t i = 0; i < content.length(); ++i) {

				s[i] = (wchar_t)content[i];

			}

			return s;

		}

		bool Replace(WString& str, const WString& from, const WString& to) {
			size_t start_pos = str.find(from);
			if (start_pos == WString::npos)
				return false;
			str.replace(start_pos, from.length(), to);
			return true;
		}

		void ReplaceAll(WString& str, const WString& from, const WString& to) {
			if (from.empty())
				return;
			size_t start_pos = 0;
			while ((start_pos = str.find(from, start_pos)) != WString::npos) {
				str.replace(start_pos, from.length(), to);
				start_pos += to.length();
			}
		}

	}

}