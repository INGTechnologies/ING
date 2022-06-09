#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

		class ProjectBuilder;



		class IFileReader {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IFileReader	(ProjectBuilder* projectBuilder);
			~IFileReader();



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
			virtual WString Read(const WString& path);

		};
		
	}

}