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

		std::string ING_API String(const char* content);

		std::string ING_API String(char content);

		std::string ING_API String(int content);

		std::string ING_API String(unsigned int content);

		std::string ING_API String(long content);

		std::string ING_API String(unsigned long content);

		std::string ING_API String(void* content);

	}

}