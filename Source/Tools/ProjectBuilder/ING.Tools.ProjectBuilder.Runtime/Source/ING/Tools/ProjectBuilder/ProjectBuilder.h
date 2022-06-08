
/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

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

		public:
			const std::vector<WString>& GetArgv () { return argv; }

			const WString&	GetProjectFilePath () { return projectFilePath; }
			const WString&	GetProjectDirectoryPath() { return projectDirectoryPath; }

			const String&	GetConfigurationName () { return configurationName; }



			/**
			 *	Methods
			 */
		public:
			void Build();

		};
		
	}

}