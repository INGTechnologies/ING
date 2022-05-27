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

		struct ClassMember;

		class Context;



		template<typename... TArgs>
		class SpecifiedProcedure;



		class ING_API IProcedure {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			IProcedure();
			~IProcedure();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Methods
			 */
		public:
			template<typename... TArgs>
			SpecifiedProcedure<TArgs...>* Specify() {

				return (SpecifiedProcedure<TArgs...>*)this;

			}



			/**
			 *	Methods
			 */
		public:
			void Invoke();

		};



		template<typename... TArgs>
		class SpecifiedProcedure : public IProcedure {

			/**
			 *	Constructors And Destructor
			 */
		protected:
			SpecifiedProcedure() :
				IProcedure()
			{



			}

			~SpecifiedProcedure() {
			
			
			
			}



			/**
			 *	Methods
			 */
		public:
			virtual void Invoke(TArgs... args) = 0;

		};



		template<auto TProcedure, typename... TArgs>
		class Procedure : public SpecifiedProcedure<TArgs...> {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Procedure() :
				SpecifiedProcedure<TArgs...>()
			{



			}

			~Procedure() {



			}



			/**
			 *	Methods
			 */
		public:
			virtual void Invoke(TArgs... args) override;

		};



		template<auto TProcedure, typename... TArgs>
		void Procedure<TProcedure, TArgs...>::Invoke(TArgs... args) {

			TProcedure(args...);

		}

	}

}