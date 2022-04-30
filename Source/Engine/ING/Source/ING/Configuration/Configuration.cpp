
/**
 *	Include Header
 */
#include "Configuration.h"



#define MINI_CASE_SENSITIVE

/**
 *	Include mIni
 */
#include "mINI/src/mini/ini.h"

#undef MINI_CASE_SENSITIVE



#include <filesystem>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Configuration::Configuration() {

	}

	Configuration::~Configuration() {

		for (auto& it : ptrMap) {

			delete it.second;

		}

		ptrMap.clear();

	}



	/**
	 *	Methods
	 */
	bool Configuration::LoadFromFile(const String& filePath) {

		String parsedFilePath = Path::GetAbsolutePath(filePath);

		if (!std::filesystem::exists(parsedFilePath)) return false;

		mINI::INIFile configFile(parsedFilePath);

		mINI::INIStructure compiledData;

		configFile.read(compiledData);

		for (const auto& item : compiledData) {

			for (const auto& item2 : item.second) {

				String propName = item.first + "." + item2.first;

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

						this->Add<float>(propName);
						this->Set<float>(propName, value);

					}
					/* If This Is UInt Prop */
					else {

						unsigned int value = std::stoi(item2.second);

						this->Add<unsigned int>(propName);
						this->Set<unsigned int>(propName, value);

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

						this->Add<float>(propName);
						this->Set<float>(propName, value);

					}
					/* If This Is UInt Prop */
					else {

						unsigned int value = std::stoi(item2.second);

						this->Add<unsigned int>(propName);
						this->Set<unsigned int>(propName, value);

					}

				}
				/* If This Is Boolean Prop */
				else if (item2.second[0] == 't' || item2.second[0] == 'f') {

					if (item2.second == "true") {

						this->Add<bool>(propName);
						this->Set<bool>(propName, true);

					}
					else if (item2.second == "false") {

						this->Add<bool>(propName);
						this->Set<bool>(propName, false);

					}

				}
				/* If This Is String Prop */
				else if (item2.second[0] == '"') {

					this->Add<String>(propName);
					this->Set<String>(propName, item2.second.substr(1,item2.second.size() - 2));

				}

			}

		}

		return true;

	}

}