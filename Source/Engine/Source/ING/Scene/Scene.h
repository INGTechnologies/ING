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
			const std::vector<std::string>& resourcePaths,
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
		std::unordered_map<std::string, IResource*> resourcePath2ResourceMap;
		std::unordered_map<std::string, ISceneComponent*> componentTypeId2ComponentMap;

	public:
		const std::unordered_map<std::string, IResource*>& GetResourcePath2ResourceMap() { return resourcePath2ResourceMap; }
		const std::unordered_map<std::string, ISceneComponent*>& GetComponentTypeId2ComponentMap() { return componentTypeId2ComponentMap; }



	};

}