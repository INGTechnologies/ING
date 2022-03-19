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

		class Layer;

		static const unsigned int MAX_LAYER_COUNT = 64;



		class ING_API LayerManager :
			public Singleton<LayerManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			LayerManager();
			~LayerManager();



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init()		override;
			virtual bool Run()		override;
			virtual bool Release()	override;



			/**
			 *	Properties
			 */
		private:
			std::vector<Layer*>								layerVector;
			std::unordered_map<std::string, bool>			categoryNameMap;

		public:
			const std::vector<Layer*>&						GetLayerVector		() { return layerVector; }
			const std::unordered_map<std::string, bool>&	GetCategoryNameMap	() { return categoryNameMap; }
			void											SetCategoryNameMap	(const std::vector<std::string>& categoryNameVector);



			/**
			 *	Methods
			 */
		public:
			void	SetLayer	(Layer* layer, unsigned int index);
			Layer*	GetLayer	(unsigned int index);
			void	RemoveLayer	(unsigned int index);

		};

	}

}