
/**
 *	Include Header
 */
#include "Scene.h"



/**
 *	Include Component
 */
#include "Component/Component.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Scene::Scene()
	{



	}

	Scene::Scene(
		const std::vector<String>& resourcePaths,
		const std::vector<ISceneComponent*>& componentVector
	) :
		Scene()
	{

		for (auto component : componentVector) {

			componentTypeId2ComponentMap[component->GetTypeId()] = component;

		}

	}

	Scene::~Scene()
	{



	}



	/**
	 *	Release Methods
	 */
	void Scene::Release()
	{

		resourcePath2ResourceMap.clear();
		componentTypeId2ComponentMap.clear();

		delete this;

	}
	
}