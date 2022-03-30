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
		static ECS_COMPONENT(MeshDrawable, MeshDrawableSystem)

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

			const std::vector<std::string>& GetCategoryNameVector	() { return ingMeshDrawable->GetCategoryNameVector(); }
			void							SetCategoryNameVector	(const std::vector<std::string>& categoryNameVector) { ingMeshDrawable->SetCategoryNameVector(categoryNameVector); }
			void							SetCategories			(const std::vector<std::string>& categoryNameVector) { ingMeshDrawable->SetCategories(categoryNameVector); }
			bool							IsHaveCategory			(const std::string& categoryName) { return ingMeshDrawable->IsHaveCategory(categoryName); }

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