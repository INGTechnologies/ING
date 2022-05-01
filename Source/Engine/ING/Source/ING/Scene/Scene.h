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



namespace ING {

	class SceneManager;

	class IResource;

	class ISceneComponent;



	class ING_API Scene
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class SceneManager;



		/**
		 *	Constructors And Destructor
		 */
	public:
		Scene();
		Scene(
			const std::vector<String>& resourcePaths,
			const std::vector<ISceneComponent*>& componentVector
		);
		~Scene();



		/**
		 *	Release Methods
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	public:
		std::unordered_map<String, IResource*> resourcePath2ResourceMap;
		std::unordered_map<String, ISceneComponent*> componentTypeId2ComponentMap;

	public:
		const std::unordered_map<String, IResource*>& GetResourcePath2ResourceMap() { return resourcePath2ResourceMap; }
		const std::unordered_map<String, ISceneComponent*>& GetComponentTypeId2ComponentMap() { return componentTypeId2ComponentMap; }



		/**
		 *	Methods
		 */
	public:
		template<class T>
		void AddComponent() {

			if (componentTypeId2ComponentMap.find(typeid(T).name()) != componentTypeId2ComponentMap.end()) return;

			T* component = new T();

			componentTypeId2ComponentMap[typeid(T).name()] = component;

			return component;

		}

		template<class T>
		T* GetComponent() {

			if (componentTypeId2ComponentMap.find(typeid(T).name()) == componentTypeId2ComponentMap.end()) return 0;

			return componentTypeId2ComponentMap[typeid(T).name()];

		}

	};

}