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
 *	Include Rendering Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>



namespace ING {

	namespace Rendering {

		class IDrawableFilter;

		class IDrawble;



		class ING_API Layer
		{

			/**
			 *	Friend Classes
			 */
		public:
			friend class LayerManager;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Layer	(std::string name);
			~Layer	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			std::string			name;

			unsigned int		index;

			std::unordered_map<std::string, IDrawableFilter*> name2DrawableFilterMap;

		public:
			std::string			GetName			() { return name; }

			unsigned int		GetIndex		() { return index; }

			const std::unordered_map<std::string, IDrawableFilter*>& GetName2DrawableFilterMap () { return name2DrawableFilterMap; }

			IDrawableFilter*	GetFilter		(const std::string& name);
			void			    AddFilter		(const std::string& name);
			void			    RemoveFilter	(const std::string& name);

		};

	}

}