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
 *	Include OuternalMethod
 */
#include <ING/Scripting/Method/OuternalMethod/OuternalMethod.h>



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



			class ING_API OuternalMethod : public IOuternalMethod
			{

			public:
				friend class Context;



				/**
				 *	Constructors And Destructor
				 */
			public:
				OuternalMethod(IContext* context, IMethodContainer* container);
				~OuternalMethod();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				Assembly*	assembly;

				MonoMethod* monoMethod;

			public:
				Assembly*	GetAssembly		()	{ return assembly; }

				MonoMethod* GetMonoMethod	()	{ return monoMethod; }



				/**
				 *	Methods
				 */
			public:
				virtual void* Execute(void* object, void** params) override;

			};

		}

	}

}