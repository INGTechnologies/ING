#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include IOStream
 */
#include <iostream>



/**
 *	Include Types
 */
#include <ING/Utils/Types.h>



namespace ING {

	namespace Utils {

		std::wstring ING_API WString(const wchar_t* content);

		std::wstring ING_API WString(char content);

		std::wstring ING_API WString(int content);

		std::wstring ING_API WString(unsigned int content);

		std::wstring ING_API WString(long content);

		std::wstring ING_API WString(unsigned long content);

		std::wstring ING_API WString(float content);

		std::wstring ING_API WString(double content);

		std::wstring ING_API WString(void* content);

		std::wstring ING_API WString(size_t content);

	}

}