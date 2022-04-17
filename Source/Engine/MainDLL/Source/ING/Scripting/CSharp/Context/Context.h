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

		class ILanguage;



		namespace CSharp {

			class Language;

			class Assembly;

			class Class;



			class ING_API Context : public IContext
			{

			public:
				friend class Language;



				/**
				 *	Constructors And Destructor
				 */
			protected:
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



				/**
				 *	Methods
				 */
			public:
				Assembly*	LoadAssembly	(const std::string& path);

				Class*		GetClass		(Assembly* assembly, const std::string& name, const std::string& _namespace);

				virtual IOuternalMethod* GetOuternalMethod(IMethodContainer* container, const std::string& name) override;

			};

		}

	}

}