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

		class ING_API Namespace
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Namespace	(const String& name, bool isGlobal);
			Namespace	(const String& name);
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

		public:
			const String&	GetName		() { return name; }

			const std::unordered_map<String, Namespace*>& GetName2ChildMap() { return name2ChildMap; }

			Namespace*		GetChild	(const String& name) { return name2ChildMap[name]; }

			Namespace*		GetParent	() { return parent; }

			bool			IsGlobal	() { return isGlobal; }



			/**
			 *	Methods
			 */
		public:
			static Namespace* Create(const String& fullName);

			void			AddChild	(Namespace* _namespace);
			void			RemoveChild	(Namespace* _namespace);
			void			RemoveChild	(const String& name);

		};

	}

}