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

		using WString = std::wstring;

		std::wstring ING_API ToWString(const wchar_t* content);

		std::wstring ING_API ToWString(char content);

		std::wstring ING_API ToWString(int content);

		std::wstring ING_API ToWString(unsigned int content);

		std::wstring ING_API ToWString(long content);

		std::wstring ING_API ToWString(unsigned long content);

		std::wstring ING_API ToWString(float content);

		std::wstring ING_API ToWString(double content);

		std::wstring ING_API ToWString(void* content);

		std::wstring ING_API ToWString(size_t content);

		std::wstring ING_API ToWString(const std::string& content);

	}

}