#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

		class ProjectBuilder;



		class IProjectGenerator {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IProjectGenerator  (ProjectBuilder* projectBuilder);
			~IProjectGenerator ();



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