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
 *	Include Component
 */
#include <ING/ECS/Component/Component.h>



/**
 *	Include Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Include Repository
 */
#include <ING/ECS/Repository/Repository.h>



/**
 *	Include Entity
 */
#include <ING/ECS/Entity/Entity.h>



namespace ING {

	namespace ECS {

		class MeshDrawableSystem;



		/**
		 *	Component
		 */
		struct MeshDrawable :

			public Component

		{

		public:
			friend class MeshDrawableSystem;



			/**
			 *	Constructors And Destructor
			 */
		public:
			MeshDrawable(Entity* entity, IComponentSystem* system, ComponentId id) :
				Component(entity, system, id)
			{}



			/**
			 *	Properties
			 */
		private:
			ING::Rendering::MeshDrawable*	ingMeshDrawable;

		public:
			ING::Rendering::MeshDrawable*	GetINGMeshDrawable		() { return ingMeshDrawable; }

		public:
			ING::Rendering::IMesh*			GetMesh					() { return ingMeshDrawable->GetMesh(); }
			ING::Rendering::IMaterial*		GetMaterial				() { return ingMeshDrawable->GetMaterial(); }

			void							SetMesh					(ING::Rendering::IMesh* mesh) { ingMeshDrawable->SetMesh(mesh); }
			void							SetMaterial				(ING::Rendering::IMaterial* material) { ingMeshDrawable->SetMaterial(material); }

			void							SetTransform			(const TransformM& transformMatrices) { ingMeshDrawable->SetTransform(transformMatrices); }

			void							SetLayer				(unsigned int index) { return ingMeshDrawable->SetLayer(index); }
			ING::Rendering::Layer*			GetLayer				() { return ingMeshDrawable->GetLayer(); }

			const std::vector<std::string>& GetFilterNameVector	() { return ingMeshDrawable->GetFilterNameVector(); }
			void							SetFilterNameVector	(const std::vector<std::string>& categoryNameVector) { ingMeshDrawable->SetFilterNameVector(categoryNameVector); }
			void							SetCategories			(const std::vector<std::string>& categoryNameVector) { ingMeshDrawable->SetCategories(categoryNameVector); }
			bool							IsHaveFilter			(const std::string& categoryName) { return ingMeshDrawable->IsHaveFilter(categoryName); }

			bool							IsActive				() { return ingMeshDrawable->IsActive(); }
			void							SetActive				(bool isActive) { ingMeshDrawable->SetActive(isActive); }

		};



		/**
		 *	Component Pointer
		 */
		using MeshDrawablePtr = ComponentPtr<ECS::MeshDrawable, MeshDrawableSystem>;



		/**
		 *	Component System
		 */
		class ING_API MeshDrawableSystem : public ING::ECS::ComponentSystem<MeshDrawable, MeshDrawableSystem> {

		public:
			friend class ING::ECS::Repository;

		protected:
			MeshDrawableSystem(ING::ECS::Repository* repository) : ING::ECS::ComponentSystem<MeshDrawable, MeshDrawableSystem>(repository) {}



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
			virtual void LateUpdate() override;
			virtual void Destroy(MeshDrawablePtr componentPtr) override;

		};

	}

}