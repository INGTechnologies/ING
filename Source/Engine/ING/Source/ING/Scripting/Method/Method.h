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



namespace ING {

	namespace Scripting {

		class IContext;

		class IMethodContainer;



		class ING_API IMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IMethod(IContext* context, IMethodContainer* container);
			~IMethod();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IContext*			context;

			IMethodContainer*	container;

		protected:
			String			name;

		public:
			IContext*			GetContext		() { return context; }

			IMethodContainer*	GetContainer	() { return container; }

			const String&	GetName			() { return name; }

		};

	}

}