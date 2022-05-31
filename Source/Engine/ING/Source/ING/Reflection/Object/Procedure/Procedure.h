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



/**
 *	Include RType
 */
#include <ING/Reflection/RType/RType.h>



namespace ING {

	namespace Reflection {

		class Namespace;

		class IType;

		class IClass;

		class C_Object;

		struct ClassMember;

		class Context;



		template<typename... TArgs>
		class SpecifiedObjectProcedure;



		class ING_API IObjectProcedure {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			IObjectProcedure(C_Object* object);
			~IObjectProcedure();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			C_Object* object;

		public:
			C_Object* _GetObject() { return object; }
			void  SetObject(C_Object* object) { this->object = object; }



			/**
			 *	Methods
			 */
		public:
			template<typename... TArgs>
			SpecifiedObjectProcedure<TArgs...>* Specify() {

				return (SpecifiedObjectProcedure<TArgs...>*)this;

			}



			/**
			 *	Methods
			 */
		public:
			void Invoke();

		};



		template<typename... TArgs>
		class SpecifiedObjectProcedure : public IObjectProcedure {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			SpecifiedObjectProcedure(C_Object* object) :
				IObjectProcedure(object)
			{



			}

			~SpecifiedObjectProcedure() {
			
			
			
			}



			/**
			 *	Methods
			 */
		public:
			virtual void Invoke(TArgs... args) = 0;

		};



		template<class TObject, auto TObjectProcedure, typename... TArgs>
		class ObjectProcedure : public SpecifiedObjectProcedure<TArgs...> {

			/**
			 *	Constructors And Destructor
			 */
		public:
			ObjectProcedure(TObject* object) :
				SpecifiedObjectProcedure<TArgs...>(object)
			{



			}

			~ObjectProcedure() {



			}



			/**
			 *	Properties
			 */
		public:
			TObject* _GetObject() { return (TObject*)SpecifiedObjectProcedure<TArgs...>::_GetObject(); }
			void     SetObject(TObject* object) { SpecifiedObjectProcedure<TArgs...>::SetObject(object); }



			/**
			 *	Methods
			 */
		public:
			virtual void Invoke(TArgs... args) override;

		};



		template<class TObject, auto TObjectProcedure, typename... TArgs>
		void ObjectProcedure<TObject, TObjectProcedure, TArgs...>::Invoke(TArgs... args) {

			(_GetObject()->*TObjectProcedure)(args...);

		}

	}

}