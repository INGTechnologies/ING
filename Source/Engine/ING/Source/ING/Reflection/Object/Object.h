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
 *	Include Object
 */
#include <ING\Object/Object.h>



namespace ING {

	namespace Reflection {

		class Namespace;

		class IType;

		class IClass;

		class IObjectFunction;

		class IObjectProcedure;

		struct ClassMember;

		class Context;



		class ING_API IObject : public ING::IObject
		{

			/**
			 *	Friend Classes
			 */
		public:
			friend class IClass;



			/**
			 *	Constructors And Destructor
			 */
		public:
			IObject	(IClass* _class);
			~IObject();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IClass*		_class;

			std::unordered_map<String, IObjectFunction*> name2Function;
			std::unordered_map<String, IObjectProcedure*> name2Procedure;

		public:
			IClass*		GetClass() { return _class; }

			template<typename T>
			T& GetProperty(const String& name) {

				return *((T*)GetPropertyPointer(name));

			}

			bool		IsHasFunction(const String& name) { return name2Function.find(name) != name2Function.end(); }
			IObjectFunction* GetFunction(const String& name) { 
			
				if (!IsHasFunction(name)) return 0;

				return name2Function[name]; 
			}

			bool		IsHasProcedure(const String& name) { return name2Procedure.find(name) != name2Procedure.end(); }
			IObjectProcedure* GetProcedure(const String& name) {

				if (!IsHasProcedure(name)) return 0;

				return name2Procedure[name];
			}



			/**
			 *	Methods
			 */
		public:
			void*		GetPropertyPointer (const String& name);

		};

	}

}