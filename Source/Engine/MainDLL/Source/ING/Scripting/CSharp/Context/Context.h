#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Context
 */
#include <ING/Scripting/Context/Context.h>



/**
 *	Include Mono
 */
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			class ING_API Context : public IContext
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Context(const std::string& name, ILanguage* language);
				~Context();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				MonoDomain* domain;

			public:
				MonoDomain* GetDomain() { return domain; }

			};

		}

	}

}