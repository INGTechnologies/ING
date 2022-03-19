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

		std::string ING_API String(const char* content);

		std::string ING_API String(char content);

		std::string ING_API String(int content);

		std::string ING_API String(unsigned int content);

		std::string ING_API String(long content);

		std::string ING_API String(unsigned long content);

		std::string ING_API String(float content);

		std::string ING_API String(void* content);

		std::string ING_API String(size_t content);

	}

}