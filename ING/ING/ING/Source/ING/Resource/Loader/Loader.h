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



/**
 *	Include Coder Option
 */
#include <ING/Coder/Option/Option.h>



namespace ING {

	class Resource;

	class Coder;



	class ING_API ResourceLoader {

		/**
		 *	Constructors And Destructor
		 */
	public:
		ResourceLoader();
		~ResourceLoader();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();



		/**
		 *	Loade Method
		 */
	public:
		virtual Resource* Load(std::wstring path, CoderOption& coderOption);

	};


}