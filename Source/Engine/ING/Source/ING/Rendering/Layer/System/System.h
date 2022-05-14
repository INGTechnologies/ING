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



		class ING_API LayerSystem
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			LayerSystem	();
			~LayerSystem();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			std::vector<Layer*>					layerVector;
			std::unordered_map<String, bool>	filterNameMap;

		public:
			const std::vector<Layer*>&			GetLayerVector		() { return layerVector; }
			const std::unordered_map<String, bool>&	GetFilterNameMap	() { return filterNameMap; }
			void								SetFilterNameMap	(const std::vector<String>& filterNameVector);



			/**
			 *	Methods
			 */
		public:
			void	SetLayer			(Layer* layer, unsigned int index);
			Layer*	GetLayer			(unsigned int index);
			void	RemoveLayer			(unsigned int index);
			void	RecreateFilters		(const std::vector<String>& filterNameVector);
			bool	IsHaveFilter		(const String& name) { return filterNameMap.find(name) != filterNameMap.end(); }

		};

	}

}