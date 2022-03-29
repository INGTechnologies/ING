#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;


/**
 *	Include MeshDrawable
 */
#include <ING/Rendering/Drawable/MeshDrawable/MeshDrawable.h>



/**
 *	Include ECS Core
 */
#include <ING/ECS/Core/Core.h>



namespace ING {

	namespace ECS {

		class MeshDrawableSystem;



		/**
		 *	Component
		 */
		static ING_API struct MeshDrawable :
			public Component
		{

		public:
			friend class MeshDrawableSystem;



			/**
			 *	Constructors And Destructor
			 */
		public:
			MeshDrawable(Entity* entity) :
				Component(entity)
			{
			
				
			
			}



			/**
			 *	Properties
			 */
		private:
			ING::Rendering::MeshDrawable* ingMeshDrawable;

		public:
			ING::Rendering::MeshDrawable* GetINGMeshDrawable () { return ingMeshDrawable; }

		};



		/**
		 *	Component Pointer
		 */
		using MeshDrawablePtr = ComponentPtr<ECS::MeshDrawable, MeshDrawableSystem>;



		/**
		 *	Component System
		 */
		static ING_API ECS_COMPONENT_SYSTEM(MeshDrawableSystem, MeshDrawable)

		public:
			virtual void Init() override;
			virtual void Release() override;

							

			/**
			 *	Methods
			 */
		public:
			void CopyDataForRendering(MeshDrawable& drawable);



			/**
			 *	Event Methods
			 */
		public:
			virtual void Awake(MeshDrawablePtr componentPtr) override;
			virtual void Start(MeshDrawablePtr componentPtr) override;
			virtual void PreUpdate() override;
			virtual void Update() override;
			virtual void Destroy(MeshDrawablePtr componentPtr) override;

		};

	}

}