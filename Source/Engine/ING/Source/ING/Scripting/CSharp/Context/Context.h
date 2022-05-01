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

			class IAssemblyComponentCreator;



			class ING_API Context : public IContext
			{

			public:
				friend class Language;



				/**
				 *	Constructors And Destructor
				 */
			protected:
				Context(const String& name, ILanguage* language, bool isMainContext);
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

				Assembly* assembly;

			public:
				MonoDomain* GetDomain() { return domain; }

				Assembly* GetAssembly() { return assembly; }



				/**
				 *	Methods
				 */
			private:
				bool		CreateDomain	();
				bool		UnloadDomain	();

			public:
				Assembly*	LoadAssembly	(const WString& path, const String& name);
				Assembly*	LoadAssembly	(const WString& path, const String& name, const std::vector<String>& componentNameVector);

				bool		OpenAssembly	();

				void		RemoveAssembly	();

				Class*		GetClass		(Assembly* assembly, const String& name, const String& _namespace);

				virtual IOuternalMethod* GetOuternalMethod(IMethodContainer* container, const String& name) override;

				virtual void Load() override;
				virtual void Unload() override;
				virtual void Reload() override;

			};

		}

	}

}