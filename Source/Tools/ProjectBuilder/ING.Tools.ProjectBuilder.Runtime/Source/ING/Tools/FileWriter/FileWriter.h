#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

		class ProjectBuilder;



		class IFileWriter {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IFileWriter	(ProjectBuilder* projectBuilder);
			~IFileWriter();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			ProjectBuilder* projectBuilder;

		public:
			ProjectBuilder* GetProjectBuilder() { return projectBuilder; }



			/**
			 *	Methods
			 */
		public:
			virtual void Write(const WString& path, const WString& content);

		};
		
	}

}