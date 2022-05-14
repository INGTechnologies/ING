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

	namespace Rendering {

		class Scene;

		class LayerSystem;



		class ING_API SceneSystem
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			SceneSystem();
			~SceneSystem();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			std::unordered_map<String, Scene*>		sceneMap;

			LayerSystem*							layerSystem;

		public:
			std::unordered_map<String, Scene*>&		GetSceneMap () { return sceneMap; }

			LayerSystem*							GetLayerSystem () { return layerSystem; }



			/**
			 *	Methods
			 */
		public:
			void	AddScene	(Scene* scene);
			void	RemoveScene	(Scene* scene);

		};

	}

}