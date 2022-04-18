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
 *	Include MethodContainer
 */
#include <ING/Scripting/Method/Container/Container.h>



namespace ING {

	namespace Scripting {

		class IContext;



		namespace CSharp {

			class Context;

			class Assembly;



			class ING_API MethodContainer : public IMethodContainer
			{

			public:
				friend class Context;



				/**
				 *	Constructors And Destructor
				 */
			public:
				MethodContainer(Assembly* assembly, IContext* context);
				~MethodContainer();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				Assembly*			assembly;

			public:
				Assembly*			GetAssembly		()	{ return assembly; }

			};

		}

	}

}