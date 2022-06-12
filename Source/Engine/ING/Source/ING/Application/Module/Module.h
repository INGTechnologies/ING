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



/**
 *	Include ApplicationManager
 */
#include <ING/Application/Manager/Manager.h>



namespace ING {

	class ApplicationReflectionSystem;

	class IApplicationModule;

	class IApplication;



	struct IApplicationModuleTypeLoader {
	
		IApplicationModuleTypeLoader(
			IApplicationModule* module, 
			Reflection::Context* reflectionContext, 
			void (*func)(const IApplicationModuleTypeLoader& loader),
			const String& name
		) {

			this->module = module;
			this->reflectionContext = reflectionContext;
			this->func = func;
			this->name = name;

		}

		IApplicationModuleTypeLoader() {}

		IApplicationModule* module;

		Reflection::Context* reflectionContext;

		void (*func)(const IApplicationModuleTypeLoader& loader);

		String name;

		void Load() {

			func(*this);

		}
	
	};

	template<typename T>
	struct ApplicationModuleTypeLoader : public IApplicationModuleTypeLoader {

		ApplicationModuleTypeLoader(
			IApplicationModule* module,
			Reflection::Context* reflectionContext
		) :
			IApplicationModuleTypeLoader(
				module,
				reflectionContext,
				[](const IApplicationModuleTypeLoader& loader) {

					T::CreateType(loader.reflectionContext);

				},
				IType::TypeInfoToFullName(typeid(T))
			)
		{}

	};



	struct IApplicationTypeModuleUnloader {

		IApplicationTypeModuleUnloader(
			IApplicationModule* module,
			Reflection::Context* reflectionContext,
			void (*func)(const IApplicationTypeModuleUnloader& unloader),
			const String& name
		) {

			this->module = module;
			this->reflectionContext = reflectionContext;
			this->func = func;
			this->name = name;

		}

		IApplicationTypeModuleUnloader() {}

		IApplicationModule* module;

		Reflection::Context* reflectionContext;

		void (*func)(const IApplicationTypeModuleUnloader& unloader);

		String name;

		void Unload() {

			func(*this);

		}

	};

	template<typename T>
	struct ApplicationTypeModuleUnloader : public IApplicationTypeModuleUnloader {

		ApplicationTypeModuleUnloader(
			IApplicationModule* module,
			Reflection::Context* reflectionContext
		) :
			IApplicationTypeModuleUnloader(
				module,
				reflectionContext,
				[](const IApplicationTypeModuleUnloader& unloader) {

					T::ReleaseType(unloader.reflectionContext);

				},
				IType::TypeInfoToFullName(typeid(T))
			)
		{}

	};



	class ING_API IApplicationModule {

	public:
		friend class IApplication;
		friend class IApplicationModuleTypeLoader;
		friend class ApplicationReflectionSystem;



		/**
		 *	Constructor And Destructors
		 */
	public:
		IApplicationModule	(const String& name, IApplication* application);
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

		List<IApplicationModuleTypeLoader>	typeLoaderList;
		List<IApplicationTypeModuleUnloader>	typeUnloaderList;

		std::unordered_map<String, List<IApplicationModuleTypeLoader>::Node*> name2LoaderNodeMap;
		std::unordered_map<String, List<IApplicationTypeModuleUnloader>::Node*> name2UnloaderNodeMap;

		std::unordered_map<String, Reflection::IType*> name2TypeMap;

		std::unordered_map<String, bool>			dependenciesMap;

		bool isLoaded;

	public:
		String& GetName() { return name; }

		IApplication* GetApplication() { return application; }

		const std::unordered_map<String, bool>&		GetDependenciesMap () { return dependenciesMap; }

		bool IsLoaded() { return isLoaded; }



		/**
		 *	Methods
		 */
	private:
		ApplicationReflectionSystem* GetReflectionSystem();

	public:
		void AddDependency(const String& dependencyName);
		void RemoveDependency(const String& dependencyName);

		template<class T>
		void RegisterType(Reflection::Context* context) {

			String typeName = Reflection::IType::TypeInfoToFullName(typeid(T));

			if (name2LoaderNodeMap.find(typeName) != name2LoaderNodeMap.end()) return;

			if (isLoaded) {

				name2TypeMap[typeName] = T::CreateType(context);

			}

			name2LoaderNodeMap[typeName] = typeLoaderList.Add(
				ApplicationModuleTypeLoader<T>(this, context)
			);

			name2UnloaderNodeMap[typeName] = typeUnloaderList.AddAt(
				ApplicationTypeModuleUnloader<T>(this, context),
				typeUnloaderList.GetHeadNode()
			);

		}

		template<class T>
		void UnregisterType() {

			String typeName = Reflection::IType::TypeInfoToFullName(typeid(T));

			if (name2LoaderNodeMap.find(typeName) == name2LoaderNodeMap.end()) return;

			if (!isLoaded) {

				if (

					name2UnloaderNodeMap[typeName]->pValue.reflectionContext == 0
					&& ApplicationManager::GetInstance()->GetModuleInstanceCount(name) > 0
						
				) {

					return;
				}

				T::ReleaseType(name2LoaderNodeMap[typeName]->pValue->reflectionContext);

				name2TypeMap.erase(typeName);

			}

			typeLoaderList.Remove(name2LoaderNodeMap[typeName]);
			typeUnloaderList.Remove(name2UnloaderNodeMap[typeName]);

			name2LoaderNodeMap.erase(typeName);
			name2UnloaderNodeMap.erase(typeName);

		}

		void Load();
		void Unload();
		void Reload();

	};

}