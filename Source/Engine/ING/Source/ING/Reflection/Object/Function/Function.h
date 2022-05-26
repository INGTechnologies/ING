#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>SpecifiedObjectFunctionSpecifiedObjectFunction
using namespace ING::Utils;



namespace ING {

	namespace Reflection {

		class Namespace;

		class IType;

		class IClass;

		struct ClassMember;

		class Context;



		template<typename TResult, typename... TArgs>
		class SpecifiedObjectFunction;



		class ING_API IObjectFunction {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			IObjectFunction(void* object);
			~IObjectFunction();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			void* object;

		public:
			void* _GetObject() { return object; }
			void  SetObject(void* object) { this->object = object; }



			/**
			 *	Methods
			 */
		public:
			template<typename TResult, typename... TArgs>
			SpecifiedObjectFunction<TResult, TArgs...>* Specify() {

				return (SpecifiedObjectFunction<TResult, TArgs...>*)this;

			}



			/**
			 *	Methods
			 */
		public:
			void Invoke();

		};



		template<typename TResult, typename... TArgs>
		class SpecifiedObjectFunction : public IObjectFunction {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			SpecifiedObjectFunction(void* object) :
				IObjectFunction(object)
			{



			}

			~SpecifiedObjectFunction() {
			
			
			
			}



			/**
			 *	Methods
			 */
		public:
			virtual TResult Invoke(TArgs... args) {

				return TResult();
				 
			}

		};



		template<class TObject, auto TObjectFunction, typename TResult, typename... TArgs>
		class ObjectFunction : public SpecifiedObjectFunction<TResult, TArgs...> {

			/**
			 *	Constructors And Destructor
			 */
		public:
			ObjectFunction(TObject* object) :
				SpecifiedObjectFunction<TResult, TArgs...>(object)
			{



			}

			~ObjectFunction() {



			}



			/**
			 *	Properties
			 */
		public:
			TObject* _GetObject() { return (TObject*)SpecifiedObjectFunction<TResult, TArgs...>::_GetObject(); }
			void     SetObject(TObject* object) { SpecifiedObjectFunction<TResult, TArgs...>::SetObject(object); }



			/**
			 *	Methods
			 */
		public:
			virtual TResult Invoke(TArgs... args) override;

		};



		template<class TObject, auto TObjectFunction, typename TResult, typename... TArgs>
		TResult ObjectFunction<TObject, TObjectFunction, TResult, TArgs...>::Invoke(TArgs... args) {

			return (_GetObject()->*TObjectFunction)(args...);

		}

	}

}