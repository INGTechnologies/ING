#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



/**
 *	Include BuildTool
 */
#include <ING/Tools/BuildTool/BuildTool.h>



namespace ING {

	namespace Tools {

		class ProjectBuilder;



		namespace VS2022 {

			class BuildTool : public IBuildTool {

				/**
				 *	Constructors And Destructor
				 */
			public:
				BuildTool	(ProjectBuilder* projectBuilder);
				~BuildTool ();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual void Build() override;

			};

		}
		
	}

}