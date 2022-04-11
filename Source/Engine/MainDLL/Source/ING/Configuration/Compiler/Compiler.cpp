
/**
 *	Include Header
 */
#include "Compiler.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include mIni
 */
#include "mINI/src/mini/ini.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ConfigurationCompiler::ConfigurationCompiler() {



	}

	ConfigurationCompiler::~ConfigurationCompiler() {



	}



	/**
	 *	Methods
	 */
	void ConfigurationCompiler::Compile(const std::string& filePath, Configuration* config) {

		mINI::INIFile configFile(filePath);

		mINI::INIStructure compiledData;

		configFile.read(compiledData);

		for (const auto& item : compiledData) {

			for (const auto& item2 : item.second) {

				std::string propName = item.first + "::" + item2.first;

				

			}

		}

	}

}