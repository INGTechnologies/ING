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

		class IType;

		class Context;



		using NamespacePath = std::vector<String>;



		class ING_API Namespace
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Namespace	(const String& name, Context* context);
			~Namespace	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			String			name;

			std::unordered_map<String, Namespace*> name2ChildMap;

			Namespace*		parent;

			bool			isGlobal;

			std::unordered_map<String, IType*> name2TypeMap;

			Context*		context;

		public:
			const String&	GetName		() { return name; }

			const std::unordered_map<String, Namespace*>& GetName2ChildMap() { return name2ChildMap; }
			bool			IsHasChild	(const String& name) { return name2ChildMap.find(name) != name2ChildMap.end(); }
			Namespace*		GetChild	(const String& name) { 

				if (!IsHasChild(name)) return 0;
				
				return name2ChildMap[name]; 
			}

			Namespace*		GetParent	() { return parent; }

			bool			IsGlobal	() { return isGlobal; }

			const std::unordered_map<String, IType*>& GetName2TypeMap() { return name2TypeMap; }
			bool			IsHasType	(const String& name) { return name2TypeMap.find(name) != name2TypeMap.end(); }
			IType*			GetType		(const String& name) { 

				if (!IsHasType(name)) return 0;
				
				return name2TypeMap[name]; 
			}

			Context*		GetContext	() { return context; }

		private:
			void			SetContext	(Context* context);



			/**
			 *	Methods
			 */
		public:
			static NamespacePath FullNameToPath(const String& fullName);

			void			AddChild	(Namespace* _namespace);
			void			RemoveChild	(Namespace* _namespace);
			void			RemoveChild	(const String& name);

			void			AddType		(IType* _type);
			void			RemoveType	(IType* _type);

		};

	}

}