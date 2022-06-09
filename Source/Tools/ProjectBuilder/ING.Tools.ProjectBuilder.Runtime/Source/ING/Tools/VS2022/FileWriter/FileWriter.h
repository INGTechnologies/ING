#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



/**
 *	Include FileWriter
 */
#include <ING/Tools/FileWriter/FileWriter.h>



namespace ING {

	namespace Tools {

		class ProjectBuilder;



		namespace VS2022 {

			class FileWriter : public IFileWriter {

				/**
				 *	Constructors And Destructor
				 */
			public:
				FileWriter	(ProjectBuilder* projectBuilder);
				~FileWriter ();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual void Write(const WString& path, const WString& content) override;

			};

		}
		
	}

}