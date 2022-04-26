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



		class ING_API IOuternalMethod : public IMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IOuternalMethod(IContext* context, IMethodContainer* container);
			~IOuternalMethod();



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



			/**
			 *	Methods
			 */
		public:
			virtual void* Execute(void* object, void** params);

		};

	}

}