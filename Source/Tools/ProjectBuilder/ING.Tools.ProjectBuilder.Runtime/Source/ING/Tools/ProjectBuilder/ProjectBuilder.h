
/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

		class ISolutionGenerator;
		class IFileReader;
		class IFileWriter;



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

			bool			isNeedGenerateSolution;

			ISolutionGenerator* solutionGenerator;

			std::unordered_map<String, WString> name2PlaceholderValueMap;

			IFileReader*	fileReader;
			IFileWriter*	fileWriter;

			WString			projectFileContent;

			JSON			projectJSON;

			std::vector<String>	gamePluginNameVector;
			std::vector<JSON>	gamePluginJSONVector;

		public:
			const std::vector<WString>& GetArgv () { return argv; }

			const WString&	GetProjectFilePath () { return projectFilePath; }
			const WString&	GetProjectDirectoryPath() { return projectDirectoryPath; }

			bool			IsNeedGenerateSolution () { return isNeedGenerateSolution; }

			ISolutionGenerator* GetSolutionGenerator () { return solutionGenerator; }

			const std::unordered_map<String, WString>& GetName2PlaceholderValueMap() { return name2PlaceholderValueMap; }

			const WString&	GetPlaceholder(const String& name) { return name2PlaceholderValueMap.find(name)->second; }
			void			SetPlaceholder(const String& name, const WString& value) { name2PlaceholderValueMap[name] = value; }

			IFileReader*	GetFileReader () { return fileReader; }
			IFileWriter*	GetFileWriter () { return fileWriter; }

			const WString&	GetProjectFileContent () { return projectFileContent; }

			const JSON&		GetProjectJSON () { return projectJSON; }

			const std::vector<String>&	GetGamePluginNameVector () { return gamePluginNameVector; }
			const std::vector<JSON>&	GetGamePluginJSONVector () { return gamePluginJSONVector; }



			/**
			 *	Methods
			 */
		public:
			void SetupGamePluginVector();
			void SortGamePluginList();
			void GenerateSolution();
			void Build();

		};
		
	}

}