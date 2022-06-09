
/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

		class ISolutionGenerator;
		class IFileReader;



		class ProjectBuilder : public Singleton<ProjectBuilder> {

			/**
			 *	Friend Classes
			 */
		public:
			friend class Singleton<ProjectBuilder>;



			/**
			 *	Constructors And Destructor
			 */
		protected:
			ProjectBuilder	();

		public:
			ProjectBuilder	(const std::vector<WString>& argv);

		public:
			~ProjectBuilder	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void	Release();



			/**
			 *	Properties
			 */
		private:
			std::vector<WString> argv;

			WString			projectFilePath;
			WString			projectDirectoryPath;

			String			configurationName;

			bool			isNeedGenerateSolution;

			ISolutionGenerator* solutionGenerator;

			std::unordered_map<String, WString> name2PlaceholderValueMap;

			IFileReader*	fileReader;

			WString			projectFileContent;

		public:
			const std::vector<WString>& GetArgv () { return argv; }

			const WString&	GetProjectFilePath () { return projectFilePath; }
			const WString&	GetProjectDirectoryPath() { return projectDirectoryPath; }

			const String&	GetConfigurationName () { return configurationName; }

			bool			IsNeedGenerateSolution () { return isNeedGenerateSolution; }

			ISolutionGenerator* GetSolutionGenerator () { return solutionGenerator; }

			const std::unordered_map<String, WString>& GetName2PlaceholderValueMap() { return name2PlaceholderValueMap; }

			IFileReader*	GetFileReader () { return fileReader; }

			const WString&	GetProjectFileContent () { return projectFileContent; }



			/**
			 *	Methods
			 */
		public:
			void GenerateSolution();
			void Build();

		};
		
	}

}