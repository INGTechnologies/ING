#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Reflection {

		class Namespace;

		class IType;

		class IClass;

		struct ClassMember;

		class Context;



		template<typename TResult, typename... TArgs>
		class SpecifiedFunction;



		class ING_API IFunction {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			IFunction();
			~IFunction();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Methods
			 */
		public:
			template<typename TResult, typename... TArgs>
			SpecifiedFunction<TResult, TArgs...>* Specify() {

				return (SpecifiedFunction<TResult, TArgs...>*)this;

			}



			/**
			 *	Methods
			 */
		public:
			void Invoke();

		};



		template<typename TResult, typename... TArgs>
		class SpecifiedFunction : public IFunction {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			SpecifiedFunction() :
				IFunction()
			{



			}

			~SpecifiedFunction() {
			
			
			
			}



			/**
			 *	Methods
			 */
		public:
			virtual TResult Invoke(TArgs... args) {

				return TResult();
				 
			}

		};



		template<auto TFunction, typename TResult, typename... TArgs>
		class Function : public SpecifiedFunction<TResult, TArgs...> {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Function() :
				SpecifiedFunction<TResult, TArgs...>()
			{



			}

			~Function() {



			}



			/**
			 *	Methods
			 */
		public:
			virtual TResult Invoke(TArgs... args) override;

		};



		template<auto TFunction, typename TResult, typename... TArgs>
		TResult Function<TFunction, TResult, TArgs...>::Invoke(TArgs... args) {

			return TFunction(args...);

		}

	}

}