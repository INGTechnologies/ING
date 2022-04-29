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

		std::string ING_API ToString(const char* content);

		std::string ING_API ToString(char content);

		std::string ING_API ToString(int content);

		std::string ING_API ToString(unsigned int content);

		std::string ING_API ToString(long content);

		std::string ING_API ToString(unsigned long content);

		std::string ING_API ToString(float content);

		std::string ING_API ToString(void* content);

		std::string ING_API ToString(size_t content);

		std::string ING_API ToString(const std::wstring& content);

	}

}