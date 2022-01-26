#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class Coder;

	struct CoderOption {

		Coder* coder = nullptr;

		std::wstring key = L"";

	};

}