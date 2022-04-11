#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include String, Map
 */
#include <string>
#include <map>



namespace ING {

	class Configuration;



	class ING_API ConfigurationCompiler
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ConfigurationCompiler();
		~ConfigurationCompiler();



		/**
		 *	Methods
		 */
	public:
		void Compile(const std::string& filePath, Configuration* config);

	};

}