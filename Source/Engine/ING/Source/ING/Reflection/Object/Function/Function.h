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
		class SpecifiedClassFunction;



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
			SpecifiedClassFunction<TResult, TArgs...>* Specify() {

				return (SpecifiedClassFunction<TResult, TArgs...>*)this;

			}



			/**
			 *	Methods
			 */
		public:
			void Invoke();

		};



		template<typename TResult, typename... TArgs>
		class SpecifiedClassFunction : public IObjectFunction {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			SpecifiedClassFunction(void* object) :
				IObjectFunction(object)
			{



			}

			~SpecifiedClassFunction() {
			
			
			
			}



			/**
			 *	Methods
			 */
		public:
			virtual TResult Invoke(TArgs... args) {

				return TResult();
				 
			}

		};



		template<class TObject, auto TClassFunction, typename TResult, typename... TArgs>
		class ClassFunction : public SpecifiedClassFunction<TResult, TArgs...> {

			/**
			 *	Constructors And Destructor
			 */
		public:
			ClassFunction(TObject* object) :
				SpecifiedClassFunction<TResult, TArgs...>(object)
			{



			}

			~ClassFunction() {



			}



			/**
			 *	Properties
			 */
		public:
			TObject* _GetObject() { return (TObject*)SpecifiedClassFunction<TResult, TArgs...>::_GetObject(); }
			void     SetObject(TObject* object) { SpecifiedClassFunction<TResult, TArgs...>::SetObject(object); }



			/**
			 *	Methods
			 */
		public:
			virtual TResult Invoke(TArgs... args) override;

		};



		template<class TObject, auto TClassFunction, typename TResult, typename... TArgs>
		TResult ClassFunction<TObject, TClassFunction, TResult, TArgs...>::Invoke(TArgs... args) {

			return (_GetObject()->*TClassFunction)(args...);

		}

	}

}