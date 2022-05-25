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



		class IClassFunction {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			IClassFunction(void* object) :
				object(object)
			{



			}

			~IClassFunction() {



			}



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {

				delete this;

			}



			/**
			 *	Properties
			 */
		private:
			void* object;

		public:
			void* GetObject() { return object; }
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
		class SpecifiedClassFunction : public IClassFunction {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			SpecifiedClassFunction(void* object) :
				IClassFunction(object)
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
			TObject* GetObject() { return (TObject*)SpecifiedClassFunction<TResult, TArgs...>::GetObject(); }
			void     SetObject(TObject* object) { SpecifiedClassFunction<TResult, TArgs...>::SetObject(object); }



			/**
			 *	Methods
			 */
		public:
			virtual TResult Invoke(TArgs... args) override;

		};



		void IClassFunction::Invoke() {

			return Specify<void>()->Invoke();

		}



		template<class TObject, auto TClassFunction, typename TResult, typename... TArgs>
		TResult ClassFunction<TObject, TClassFunction, TResult, TArgs...>::Invoke(TArgs... args) {

			return (GetObject()->*TClassFunction)(args...);

		}

	}

}