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
 *	Include InternalMethod
 */
#include <ING/Scripting/Method/InternalMethod/InternalMethod.h>



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



			class ING_API InternalMethod : public IInternalMethod
			{

			public:
				friend class Context;



				/**
				 *	Constructors And Destructor
				 */
			public:
				InternalMethod(IContext* context, IMethodContainer* container);
				~InternalMethod();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				Assembly* assembly;

			public:
				Assembly* GetAssembly() { return assembly; }

			};

		}

	}

}