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
 *	Include Method
 */
#include <ING/Scripting/Method/Method.h>



namespace ING {

	namespace Scripting {

		class IContext;



		class ING_API IInternalMethod : public IMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IInternalMethod(IContext* context, IMethodContainer* container);
			~IInternalMethod();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			IContext*	context;

		public:
			IContext*	GetContext() { return context; }

		};

	}

}