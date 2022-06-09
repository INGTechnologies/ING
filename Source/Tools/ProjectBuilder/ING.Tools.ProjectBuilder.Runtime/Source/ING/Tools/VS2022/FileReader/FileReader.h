#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



/**
 *	Include FileReader
 */
#include <ING/Tools/FileReader/FileReader.h>



namespace ING {

	namespace Tools {

		class ProjectBuilder;



		namespace VS2022 {

			class FileReader : public IFileReader {

				/**
				 *	Constructors And Destructor
				 */
			public:
				FileReader	(ProjectBuilder* projectBuilder);
				~FileReader ();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual WString Read(const WString& path) override;

			};

		}
		
	}

}