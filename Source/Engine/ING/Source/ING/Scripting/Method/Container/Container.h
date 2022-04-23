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



		class ING_API IMethodContainer
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IMethodContainer(IContext* context);
			~IMethodContainer();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IContext* context;

		public:
			IContext* GetContext() { return context; }

		};

	}

}