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

		struct ClassMember;

		class Context;



		class ING_API IObject : public ING::IObject
		{

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

		public:
			IClass*		GetType	() { return _class; }

			bool		IsHasFunction(const String& name) { return name2Function.find(name) != name2Function.end(); }
			IObjectFunction* GetFunction(const String& name) { 
			
				if (!IsHasFunction(name)) return 0;

				return name2Function[name]; 
			}



			/**
			 *	Methods
			 */
		public:
			void*		GetPropertyPointer (const String& name);

			template<typename T>
			T&			GetProperty(const String& name) {
			
				return *((T*)GetPropertyPointer(name));
			
			}

		};

	}

}