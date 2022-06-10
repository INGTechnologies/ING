#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

		class ProjectBuilder;



		class IBuildTool {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IBuildTool	(ProjectBuilder* projectBuilder);
			~IBuildTool();



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
			virtual void Build();

		};
		
	}

}