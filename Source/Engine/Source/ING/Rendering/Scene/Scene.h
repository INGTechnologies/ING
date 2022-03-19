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
			Scene	(std::string name);
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
			std::string					name;

			Mask64						mask;

			std::vector<Layer*>			layerVector;


		public:
			std::string					GetName () { return name; }

			Mask64						GetMask () { return mask; }

			void						SetMask (Mask64 mask);

			const std::vector<Layer*>&	GetLayerVector () { return layerVector; }

		};

	}

}