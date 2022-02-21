#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ECS Component Id
 */
#include <ING/ECS/Component/Id/Id.h>



/**
 *	Include Unordered Map
 */
#include <unordered_map>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		struct Entity;



		/**
		 *	Interface Class
		 */
		class IComponentArray {

			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {

				delete this;

			}

		};



		/**
		 *	Main Class
		 */
		template<typename T>
		class ComponentArray : public IComponentArray
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ComponentArray() {

				sizeInByte	= 0;

				stride		= sizeof(T);

				pData		= nullptr;

				count		= 0;

				size		= 1;

			}

			~ComponentArray() {

				Clear();

			}



			/**
			 *	Properties
			 */
		private:
			unsigned int	stride;

			unsigned int	count;

			unsigned int	size;

			T*				pData;

			unsigned int	sizeInByte;

			std::unordered_map <ComponentId  , unsigned int> id2IndexMap;

			std::unordered_map <unsigned int , ComponentId>	 index2IdMap;

		public:
			unsigned int	GetStride		() { return stride; }

			unsigned int	GetCount		() { return count; }

			unsigned int	GetSize			() { return size; }

			T*				GetPData		() { return pData; }

			unsigned int	GetSizeInByte	() { return sizeInByte; }

			std::unordered_map <ComponentId, unsigned int>& GetId2IndexMap() { return id2IndexMap; }

			std::unordered_map <unsigned int, ComponentId>& GetIndex2IdMap() { return index2IdMap; }



			/**
			 *	Methods
			 */
		public:
			void			AllocateData	();

			void			Add				(T& component, ComponentId id);

			T&				Get				(ComponentId id);

			T*				GetDataPtr		(ComponentId id);

			void			Erase			(ComponentId id);

			void			Clear			();

		};

	}

}