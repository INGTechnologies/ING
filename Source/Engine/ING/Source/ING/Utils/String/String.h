#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include IOStream
 */
#include <iostream>



namespace ING {

	namespace Utils {

		using String = std::string;

		using WString = std::wstring;



		String	ING_API ToString(const char* content);

		String	ING_API ToString(char content);

		String	ING_API ToString(int content);

		String	ING_API ToString(unsigned int content);

		String	ING_API ToString(long content);

		String	ING_API ToString(unsigned long content);

		String	ING_API ToString(float content);

		String	ING_API ToString(void* content);

		String	ING_API ToString(size_t content);

		String	ING_API ToString(const WString& content);

		bool	ING_API Replace(String& str, const String& from, const String& to);

		void	ING_API ReplaceAll(String& str, const String& from, const String& to);



		WString ING_API ToWString(const wchar_t* content);

		WString ING_API ToWString(wchar_t content);

		WString ING_API ToWString(int content);

		WString ING_API ToWString(unsigned int content);

		WString ING_API ToWString(long content);

		WString ING_API ToWString(unsigned long content);

		WString ING_API ToWString(float content);

		WString ING_API ToWString(double content);

		WString ING_API ToWString(void* content);

		WString ING_API ToWString(size_t content);

		WString ING_API ToWString(const String& content);

		bool	ING_API Replace(WString& str, const WString& from, const WString& to);

		void	ING_API ReplaceAll(WString& str, const WString& from, const WString& to);

	}

}