#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

		class ProjectBuilder;



		class ISolutionGenerator {

			/**
			 *	Constructors And Destructor
			 */
		public:
			ISolutionGenerator  (ProjectBuilder* projectBuilder);
			~ISolutionGenerator ();



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
			ProjectBuilder* GetProjectBuilder () { return projectBuilder; }



			/**
			 *	Methods
			 */
		public:
			virtual void Generate();

		};
		
	}

}