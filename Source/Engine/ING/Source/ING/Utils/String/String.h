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



		String ING_API ToString(const char* content);

		String ING_API ToString(char content);

		String ING_API ToString(int content);

		String ING_API ToString(unsigned int content);

		String ING_API ToString(long content);

		String ING_API ToString(unsigned long content);

		String ING_API ToString(float content);

		String ING_API ToString(void* content);

		String ING_API ToString(size_t content);

		String ING_API ToString(const WString& content);



		WString ING_API ToWString(const wchar_t* content);

		WString ING_API ToWString(char content);

		WString ING_API ToWString(int content);

		WString ING_API ToWString(unsigned int content);

		WString ING_API ToWString(long content);

		WString ING_API ToWString(unsigned long content);

		WString ING_API ToWString(float content);

		WString ING_API ToWString(double content);

		WString ING_API ToWString(void* content);

		WString ING_API ToWString(size_t content);

		WString ING_API ToWString(const String& content);

	}

}