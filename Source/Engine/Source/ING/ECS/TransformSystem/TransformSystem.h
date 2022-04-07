#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;


/**
 *	Include Transform
 */
#include <ING/Transform/Transform.h>



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

	namespace Rendering {

		class IBuffer;

	}



	namespace ECS {

		class TransformSystem;



		static const unsigned int GPU_MIN_TRANSFORM_COUNT = 100;



		/**
		 *	Component
		 */
		struct Transform :

			public Component,		
			public ING::TransformS,
			private ING::TransformM

		{

		public:
			friend class TransformSystem;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Transform(Entity* entity, IComponentSystem* system, ComponentId id) :
				Component(entity, system, id)
			{}



			/**
			 *	Properties
			 */
		private:
			/* both GPU, CPU can use */
			unsigned int level;				
			bool		 isHaveNextTransform;
			bool		 isHavePrevTransform;	
			unsigned int nextTransformIndex;	
			unsigned int prevTransformIndex;	
				
			bool		 isHeadSPT;			
			bool		 isTailSPT;				
			bool		 isHaveNextSPT;			
			bool		 isHavePrevSPT;		
			unsigned int nextSPTIndex;		
			unsigned int prevSPTIndex;		

			unsigned int childCount;	
			bool		 isHaveHeadChild;	
			bool		 isHaveTailChild;	
			unsigned int headChildIndex;	
			unsigned int tailChildIndex;	

			unsigned int parentTransformIndex;

			/* only CPU can use */
			ComponentPtr<Transform, TransformSystem> parentPtr; 

		public:
			unsigned int GetLevel () { return level; }



			/**
			 *	Methods
			 */
		public:
			TransformM& GetMatrices() { return (TransformM&)(*this); }

			ComponentPtr<Transform, TransformSystem>	GetParentPtr() { return parentPtr; }
			Transform&	GetParent() { return *parentPtr; }

		};



		/**
		 *	Component Pointer
		 */
		using TransformPtr = ComponentPtr<Transform, TransformSystem>;



		/**
		 *	Component System
		 */
		class ING_API TransformSystem : public ING::ECS::ComponentSystem<Transform, TransformSystem> {
				
		public:
			friend class ING::ECS::Repository; 
				
		protected:
			TransformSystem(ING::ECS::Repository* repository) : ING::ECS::ComponentSystem<Transform, TransformSystem>(repository) {}



		public:
			virtual void Init()		override;
			virtual void Release()	override;



			/**
			 *	Properties
			 */
		private:
			std::vector<size_t>						transformCountVector;
			std::vector<size_t>						oldIndexArraySizeVector;

			std::vector<TransformPtr>				headTransformVector;
			std::vector<size_t>						headTransformIndexVector;
			std::vector<TransformPtr>				tailTransformVector;
			std::vector<size_t>						tailTransformIndexVector;

			Rendering::IBuffer*						mainBuffer;

			std::vector<Rendering::IBuffer*>		indexBufferVector;
			std::vector<SmartArray<unsigned int>*>	indexArrayVector;

			bool									oldArraySize;

		public:
			Rendering::IBuffer*			GetMainBuffer	()						{ return mainBuffer; }

			Rendering::IBuffer*			GetIndexBuffer	(unsigned int index)	{ return indexBufferVector[index]; }

			SmartArray<unsigned int>*	GetIndexArray	(unsigned int index)	{ return indexArrayVector[index]; }



			/**
			 *	Methods
			 */
		public:
			void RecreateBuffers	();
			void RecreateMainBuffer	();
			void RecreateIndexBuffers();
			void RecreateIndexBuffer(unsigned int level);

			void AppendChild		(TransformPtr parentPtr, TransformPtr childPtr);
			void AppendChild		(Entity* parentEntity, Entity* childEntity);

			void RemoveChild		(TransformPtr parentPtr, TransformPtr childPtr);
			void RemoveChild		(Entity* parentEntity, Entity* childEntity);

			void ComputeMatrices	(Transform& transform);

			void IncreaseTransformCount	(unsigned int level, TransformPtr componentPtr);
			void DecreaseTransformCount	(unsigned int level, TransformPtr componentPtr);

			void GPUComputeMatricesForLevel (unsigned int level);
			void CPUComputeMatricesForLevel (unsigned int level);

			void GPUSwapParentIndex	(unsigned int index, unsigned int newIndex);
			void CPUSwapParentIndex	(unsigned int index, unsigned int newIndex);



			/**
			 *	Event Methods
			 */
		public:
			virtual void Awake(TransformPtr componentPtr) override;
			virtual void Start(TransformPtr componentPtr) override;

			virtual void PreUpdate() override;
			virtual void Update() override;
			virtual void LateUpdate() override;

			virtual void PreRender() override;
			virtual void Render() override;
			virtual void LateRender() override;

			virtual void Destroy(TransformPtr componentPtr) override;
			virtual void IAfterDestroy() override;

		};

	}

}