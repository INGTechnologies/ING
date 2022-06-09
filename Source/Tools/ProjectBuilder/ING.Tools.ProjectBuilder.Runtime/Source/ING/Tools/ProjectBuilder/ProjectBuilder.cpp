
/**
 *	Include Header
 */
#include "ProjectBuilder.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include VS2022 SolutionGenerator
 */
#include <ING/Tools/VS2022/SolutionGenerator/SolutionGenerator.h>



/**
 *	Include VS2022 FileReader
 */
#include <ING/Tools/VS2022/FileReader/FileReader.h>



namespace ING {

	namespace Tools {

		/**
		 *	Constructors And Destructor
		 */
		ProjectBuilder::ProjectBuilder() :
			solutionGenerator(0),
			fileReader(0)
		{



		}

		ProjectBuilder::ProjectBuilder(const std::vector<WString>& argv) :
			ProjectBuilder()
		{

			this->argv = argv;

			if (argv.size() < 3) {

				Release();

				return;
			}



			projectFilePath = argv[1];
			ReplaceAll(projectDirectoryPath, L"\\", L"/");

			projectDirectoryPath = Path::GetDirectoryPath(projectFilePath) + ToWString(L"\\");
			ReplaceAll(projectDirectoryPath, L"\\", L"/");

			configurationName = ToString(argv[2]);

			name2PlaceholderValueMap["INGProjectFile"] = projectFilePath;
			name2PlaceholderValueMap["INGProjectDir"] = projectDirectoryPath;
			name2PlaceholderValueMap["INGConfiguration"] = ToWString(configurationName);



			isNeedGenerateSolution = true;

			if (argv.size() > 3) {

				isNeedGenerateSolution = (argv[3] == ToWString("true"));

			}

			String solutionGeneratorName = "VS2022";

			if (argv.size() > 4) {

				solutionGeneratorName = ToString(argv[4]);

			}

			name2PlaceholderValueMap["SolutionGeneratorName"] = ToWString(solutionGeneratorName);

			if (solutionGeneratorName == "VS2022") {

				solutionGenerator = new VS2022::SolutionGenerator(this);

			}

			if (solutionGeneratorName == "VS2022") {

				fileReader = new VS2022::FileReader(this);

			}



			if (
				fileReader == 0
				|| solutionGenerator == 0
			) {

				Release();

				return;

			}

			projectFileContent = fileReader->Read(projectFilePath);

		}

		ProjectBuilder::~ProjectBuilder() {



		}



		/**
		 *	CreateInstance, Release Methods
		 */
		void	ProjectBuilder::Release() {

			if (solutionGenerator == 0) {

				solutionGenerator->Release();

			}

			if (fileReader == 0) {

				fileReader->Release();

			}

			delete this;
		}



		/**
		 *	Methods
		 */
		void	ProjectBuilder::GenerateSolution() {

			solutionGenerator->Generate();

		}

		void	ProjectBuilder::Build() {

			if (isNeedGenerateSolution) {

				GenerateSolution();

			}

		}
		
	}

}