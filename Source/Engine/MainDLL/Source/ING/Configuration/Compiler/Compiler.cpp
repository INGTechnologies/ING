
/**
 *	Include Header
 */
#include "Compiler.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



#define MINI_CASE_SENSITIVE

/**
 *	Include mIni
 */
#include "mINI/src/mini/ini.h"



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



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

				/* If This Is Positive Number Prop */
				if (item2.second[0] >= 48 && item2.second[0] <= 57) {

					bool isFloat = false;
					for (unsigned int i = 0; i < item2.second.size(); ++i) {

						if (item2.second[i] == 'f') {
							isFloat = true;
							break;
						}

					}

					/* If This Is Float Prop */
					if (isFloat) {

						float value = std::stof(item2.second);

						config->Add<float>(propName);
						config->Set<float>(propName, value);

					}
					/* If This Is UInt Prop */
					else {

						unsigned int value = std::stoi(item2.second);

						config->Add<unsigned int>(propName);
						config->Set<unsigned int>(propName, value);

					}

				}
				/* If This Is Negative Number Prop */
				if (item2.second[0] == '-') {

					bool isFloat = false;
					for (unsigned int i = 1; i < item2.second.size(); ++i) {

						if (item2.second[i] == 'f') {
							isFloat = true;
							break;
						}

					}

					/* If This Is Float Prop */
					if (isFloat) {

						float value = std::stof(item2.second);

						config->Add<float>(propName);
						config->Set<float>(propName, value);

					}
					/* If This Is UInt Prop */
					else {

						unsigned int value = std::stoi(item2.second);

						config->Add<unsigned int>(propName);
						config->Set<unsigned int>(propName, value);

					}

				}
				/* If This Is Boolean Prop */
				else if (item2.second[0] == 't' || item2.second[0] == 'f') {

					if (item2.second == "true") {

						config->Add<bool>(propName);
						config->Set<bool>(propName, true);

					}
					else if (item2.second == "false") {

						config->Add<bool>(propName);
						config->Set<bool>(propName, false);

					}

				}
				/* If This Is String Prop */
				else if (item2.second[0] == '"') {

					config->Add<std::string>(propName);
					config->Set<std::string>(propName, item2.second.substr(1,item2.second.size() - 2));

				}

			}

		}

	}

}