#include <iostream>

#include <fstream>

#include <Windows.h>

#include <unordered_map>

#include <filesystem>

#include <sstream>

#define MINI_CASE_SENSITIVE

#include "mINI/src/mini/ini.h"

#undef MINI_CASE_SENSITIVE


bool isNeedBuild;


namespace ING {

	namespace Tools {

		namespace EngineBuilder {

			void CopyEngine(const std::string& outputPath, const std::string& engineBinariesPath) {

				std::string binariesPath = engineBinariesPath;
				std::string newPath = outputPath;

				std::stringstream ss;

				ss << "xcopy ";

				ss << '"';

				ss << binariesPath;

				ss << '"';

				ss << ' ';

				ss << '"';

				ss << newPath;

				ss << '"';

				std::string command = "";
				std::string command3 = "";
				std::string command4 = "";
				std::string command2 = ss.str();

				for (auto i : command2) {

					if (i == '/')
						command3 += "\\";
					else
						command3 += i;

				}

				for (size_t i = 0; i < command3.length(); ++i) {

					if (command3[i] == '\\') {

						while (command3[i + 1] == '\\') { ++i; }

						command4 += "\\";

					}
					else {

						command4 += command3[i];

					}

				}

				for (auto i : command3) {

					if (i == '\\')
						command += "\\\\";
					else
						command += i;

				}

				command += " /s /i /y";

				std::cout << command << std::endl;

				system(command.c_str());

			}

		}

	}

}



int main(int argc, char* argv[]) {

	std::cout << "Start Building Engine" << std::endl;

	if (argc >= 3) {

		char* arg1 = argv[1];
		char* arg2 = argv[2];

		std::string outputPath(arg1);
		std::string engineBinariesPath(arg2);

		ING::Tools::EngineBuilder::CopyEngine(outputPath, engineBinariesPath);

	}

	std::cout << "Engine Built Successfully" << std::endl;

	return 0;
}