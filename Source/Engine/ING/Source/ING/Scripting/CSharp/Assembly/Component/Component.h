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
 *	Include Mono
 */
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>



namespace ING {

	namespace Scripting {

		class IContext;



		namespace CSharp {

			class Context;

			class Assembly;



			class ING_API IAssemblyComponent
			{

			public:
				friend class Assembly;



				/**
				 *	Constructors And Destructor
				 */
			protected:
				IAssemblyComponent	(Assembly* assembly, const std::string& name);
				~IAssemblyComponent	();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release();



				/**
				 *	Properties
				 */
			private:
				Assembly*			assembly;

				std::string			name;

			public:
				Assembly*			GetAssembly		() { return assembly; }

				const std::string&	GetName			() { return name; }



				/**
				 *	Methods
				 */
			public:
				virtual void OnOpen		();
				virtual void OnClose	();

			};

		}

	}

}