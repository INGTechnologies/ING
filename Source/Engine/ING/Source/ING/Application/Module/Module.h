#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Id
 */
#include <ING/Object/Id.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



/**
 *	Include ApplicationReflectionSystem
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



namespace ING {

	class ApplicationReflectionSystem;

	class IApplicationModule;

	class IApplication;

	typedef void (*ApplicationModuleTypeRegister) (IApplicationModule* module, ApplicationReflectionSystem* reflectionSystem);
	typedef void (*ApplicationModuleTypeUnregister) (IApplicationModule* module, ApplicationReflectionSystem* reflectionSystem);



	class ING_API IApplicationModule {

	public:
		friend class IApplication;



		/**
		 *	Constructor And Destructors
		 */
	public:
		IApplicationModule	(const String& name);
		~IApplicationModule	();



		/**
		 *	Release Methods
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		String	name;

		IApplication* application;

		List<ApplicationModuleTypeRegister>		   typeRegisterList;
		List<ApplicationModuleTypeUnregister>	   typeUnregisterList;

		bool canRegisterTypes;
		bool canUnregisterTypes;

		std::unordered_map<String, List<ApplicationModuleTypeRegister>::Node*> name2RegisterNodeMap;
		std::unordered_map<String, List<ApplicationModuleTypeUnregister>::Node*> name2UnregisterNodeMap;

		std::unordered_map<String, Reflection::IType*> name2TypeMap;

		std::unordered_map<String, bool>			dependenciesMap;

	public:
		String& GetName() { return name; }

		IApplication* GetApplication() { return application; }

		const List<ApplicationModuleTypeRegister>& GetTypeRegisterList() { return typeRegisterList; }
		const List<ApplicationModuleTypeUnregister>& GetTypeUnregisterList() { return typeUnregisterList; }

		const std::unordered_map<String, bool>&		GetDependenciesMap () { return dependenciesMap; }



		/**
		 *	Methods
		 */
	private:
		ApplicationReflectionSystem* GetReflectionSystem();

	public:
		void AddDependencies(const String& dependencyName);
		void RemoveDependencies(const String& dependencyName);

		void RegisterTypes();
		void UnregisterTypes();

		template<class T>
		void L_RegisterType() {

			String typeName = Reflection::IType::TypeInfoToFullName(typeid(T));

			if(application != 0)
				if (GetReflectionSystem()->IsTypesRegistered()) {

					name2TypeMap[typeName] = T::CreateType(0);

					return;

				}

			if (!canRegisterTypes) {

				Debug::Error(ToString("Cant L_Register Type, Module: ") + name);

				return;

			}

			name2RegisterNodeMap[typeName] = typeRegisterList.Add([](IApplicationModule* module, ApplicationReflectionSystem* reflectionSystem) {

				reflectionSystem->L_RegisterType<T>();

			});

			name2UnregisterNodeMap[typeName] = typeUnregisterList.Add([](IApplicationModule* module, ApplicationReflectionSystem* reflectionSystem) {

				reflectionSystem->L_UnregisterType<T>();

			});

		}

		template<class T>
		void L_UnregisterType() {

			String typeName = Reflection::IType::TypeInfoToFullName(typeid(T));

			if (application != 0)
				if (GetReflectionSystem()->IsTypesRegistered()) {

					T::ReleaseType(0);

					name2TypeMap.erase(typeName);

					return;

				}

			if (!canUnregisterTypes) {

				Debug::Error(ToString("Cant L_Unregister Type, Module: ") + name);

				return;

			}

			typeRegisterList.Remove(name2RegisterNodeMap[typeName]);

			name2RegisterNodeMap.erase(typeName);

			typeUnregisterList.Remove(name2UnregisterNodeMap[typeName]);

			name2UnregisterNodeMap.erase(typeName);

		}

		template<class T>
		void RegisterType() {

			String typeName = Reflection::IType::TypeInfoToFullName(typeid(T));

			if (application != 0)
				if (GetReflectionSystem()->IsTypesRegistered()) {

					name2TypeMap[typeName] = T::CreateType(GetReflectionSystem()->GetContext());

					return;

				}

			if (!canRegisterTypes) {

				Debug::Error(ToString("Cant G_Register Type, Module: ") + name);

				return;

			}

			name2RegisterNodeMap[typeName] = typeRegisterList.Add([](IApplicationModule* module, ApplicationReflectionSystem* reflectionSystem) {

				reflectionSystem->RegisterType<T>();

				});

			name2UnregisterNodeMap[typeName] = typeUnregisterList.Add([](IApplicationModule* module, ApplicationReflectionSystem* reflectionSystem) {

				reflectionSystem->RegisterType<T>();

				});

		}

		template<class T>
		void UnregisterType() {

			String typeName = Reflection::IType::TypeInfoToFullName(typeid(T));

			if (application != 0)
				if (GetReflectionSystem()->IsTypesRegistered()) {

					T::ReleaseType(GetReflectionSystem()->GetContext());

					name2TypeMap.erase(typeName);

					return;

				}

			if (!canUnregisterTypes) {

				Debug::Error(ToString("Cant G_Unregister Type, Module: ") + name);

				return;

			}

			typeRegisterList.Remove(name2RegisterNodeMap[typeName]);

			name2RegisterNodeMap.erase(typeName);

			typeUnregisterList.Remove(name2UnregisterNodeMap[typeName]);

			name2UnregisterNodeMap.erase(typeName);

		}

	};

}