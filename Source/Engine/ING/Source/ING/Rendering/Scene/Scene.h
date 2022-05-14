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
 *	Include Mask
 */
#include <ING/Mask/Mask.h>



namespace ING {

	namespace Rendering {

		class IDrawbleCategory;

		class IDrawble;

		class Layer;

		class LayerSystem;

		class SceneSystem;



		class ING_API Scene
		{

			/**
			 *	Friend Classes
			 */
		public:
			friend class SceneManager;

			friend class SceneSystem;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Scene	(String name, SceneSystem* system);
			~Scene	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			String						name;

			Mask64						layerMask;

			std::vector<Layer*>			layerVector;

			SceneSystem*				system;


		public:
			String						GetName			() { return name; }

			Mask64						GetLayerMask	() { return layerMask; }

			void						SetLayerMask	(Mask64 layerMask);
			void						ContainLayers	(const std::vector<unsigned int>& indices);

			const std::vector<Layer*>&	GetLayerVector	() { return layerVector; }

			SceneSystem*				GetSystem		() { return system; }

		};

	}

}