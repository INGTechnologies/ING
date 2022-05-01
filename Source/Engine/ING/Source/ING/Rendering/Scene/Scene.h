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
 *	Include Rendering Scene Manager
 */
#include <ING/Rendering/Scene/Manager/Manager.h>



/**
 *	Include Mask
 */
#include <ING/Mask/Mask.h>



namespace ING {

	namespace Rendering {

		class IDrawbleCategory;

		class IDrawble;

		class Layer;



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
			Scene	(String name);
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
			String					name;

			Mask64						layerMask;

			std::vector<Layer*>			layerVector;


		public:
			String					GetName () { return name; }

			Mask64						GetLayerMask () { return layerMask; }

			void						SetLayerMask (Mask64 layerMask);
			void						ContainLayers(const std::vector<unsigned int>& indices);

			const std::vector<Layer*>&	GetLayerVector () { return layerVector; }

		};

	}

}