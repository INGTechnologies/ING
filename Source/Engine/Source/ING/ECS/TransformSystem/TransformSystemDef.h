#pragma once

/**
 *	Include Header
 */
#include "TransformSystem.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace ECS {

		/**
		 *	Init And Release Methods
		 */
		void TransformSystem::Init() {



		}

		void TransformSystem::Release() {

			IComponentSystem::Release();

		}



		/**
		 *	Methods
		 */
		void TransformSystem::AppendChild(TransformPtr parentPtr, TransformPtr childPtr) {

#if _DEBUG
			if (

				parentPtr.GetId() == childPtr.GetId()

				|| (
					childPtr->parentTransformIndex == array.Id2Index(parentPtr.GetId())
					&& childPtr->level == parentPtr->level + 1
				)
			) 
			{

				Debug::Error("Cant Append Child");

				return;

			}
#endif

			Transform& parentTransform = *parentPtr;
			Transform& childTransform = *childPtr;

			DecreaseTransformCount(childTransform.level, childPtr);

			unsigned int childComponentIndex = array.Id2Index(childPtr.GetId());

			childTransform.level = parentPtr->level + 1;

			childTransform.parentTransformIndex = array.Id2Index(parentPtr.GetId());

			if (parentTransform.isHaveHeadChild) {

				array.GetByIndex(parentTransform.tailChildIndex).isHaveNextSPT = true;
				array.GetByIndex(parentTransform.tailChildIndex).nextSPTIndex = childComponentIndex;

				childTransform.isHavePrevSPT = true;
				childTransform.prevSPTIndex = parentTransform.tailChildIndex;

				parentTransform.tailChildIndex = childComponentIndex;

			}
			else {

				parentTransform.headChildIndex = childComponentIndex;
				parentTransform.tailChildIndex = childComponentIndex;

				childTransform.isHavePrevSPT = false;

			}
			childTransform.isHaveNextSPT = false;

			parentTransform.isHaveHeadChild = true;
			parentTransform.isHaveTailChild = true;

			parentTransform.childCount++;

			IncreaseTransformCount(childTransform.level, childPtr);

		}

		void TransformSystem::AppendChild(Entity* parentEntity, Entity* childEntity) {

			AppendChild(
				this->GetComponent(parentEntity),
				this->GetComponent(childEntity)
			);

		}

		void TransformSystem::RemoveChild(TransformPtr parentPtr, TransformPtr childPtr) {

#if _DEBUG
			if (

				parentPtr.GetId() == childPtr.GetId()

				|| (
					childPtr->parentTransformIndex != array.Id2Index(parentPtr.GetId())
					|| childPtr->level != parentPtr->level + 1
				)

			)
			{

				Debug::Error("Cant Remove Child");

				return;

			}
#endif

			Transform& parentTransform = *parentPtr;
			Transform& childTransform = *childPtr;

			DecreaseTransformCount(childTransform.level, childPtr);

			childTransform.level--;

			if (childTransform.isHaveNextSPT) {

				array.GetByIndex(childTransform.nextSPTIndex).prevSPTIndex = childTransform.prevSPTIndex;
				array.GetByIndex(childTransform.nextSPTIndex).isHavePrevSPT = childTransform.isHavePrevSPT;

			}
			else {

				parentTransform.tailChildIndex = childTransform.prevSPTIndex;

			}

			if (childTransform.isHavePrevSPT) {

				array.GetByIndex(childTransform.prevSPTIndex).nextSPTIndex = childTransform.nextSPTIndex;
				array.GetByIndex(childTransform.prevSPTIndex).isHaveNextSPT = childTransform.isHaveNextSPT;

			}
			else {

				parentTransform.headChildIndex = childTransform.nextSPTIndex;

			}

			childTransform.isHaveNextSPT = false;
			childTransform.isHavePrevSPT = false;

			parentTransform.childCount--;

			IncreaseTransformCount(childTransform.level, childPtr);

		}

		void TransformSystem::RemoveChild(Entity* parentEntity, Entity* childEntity) {

			RemoveChild(
				this->GetComponent(parentEntity),
				this->GetComponent(childEntity)
			);

		}

		void TransformSystem::ComputeMatrices(Transform& transform) {

			

		}

		void TransformSystem::IncreaseTransformCount(unsigned int level, TransformPtr componentPtr) {

			unsigned int componentIndex = GetArray().Id2Index(componentPtr.GetId());

			Transform& component = *componentPtr;

			if (transformCountVector.size() < level + 1) {

				transformCountVector.resize(level + 1);
				headTransformVector.resize(level + 1);
				headTransformIndexVector.resize(level + 1);
				tailTransformVector.resize(level + 1);
				tailTransformIndexVector.resize(level + 1);

				transformCountVector[level] = 0;

			}

			transformCountVector[level]++;

			if (transformCountVector[level] != 1) {

				tailTransformVector[level]->nextTransformIndex = componentIndex;

				tailTransformVector[level]->isHaveNextTransform = true;

				component.prevTransformIndex = tailTransformIndexVector[level];

				component.isHavePrevTransform = true;

			}
			else {

				headTransformVector[level] = componentPtr;
				headTransformIndexVector[level] = componentIndex;

				component.isHavePrevTransform = false;

			}

			component.isHaveNextTransform = false;

			tailTransformVector[level] = componentPtr;
			tailTransformIndexVector[level] = componentIndex;

		}

		void TransformSystem::DecreaseTransformCount(unsigned int level, TransformPtr componentPtr) {

			Transform& component = *componentPtr;

			transformCountVector[level]--;

			if (transformCountVector[level] == 0) {

				transformCountVector.resize(level);
				headTransformVector.resize(level);
				headTransformIndexVector.resize(level);
				tailTransformVector.resize(level);
				tailTransformIndexVector.resize(level);

			}
			else {

				if (component.isHaveNextTransform) {

					array.GetByIndex(component.nextTransformIndex).prevTransformIndex = component.prevTransformIndex;
					array.GetByIndex(component.nextTransformIndex).isHavePrevTransform = component.isHavePrevTransform;

				}
				else {

					tailTransformIndexVector[level] = component.prevTransformIndex;
					tailTransformVector[level] = IComponentPtr(array.Index2Id(component.prevTransformIndex), this);

				}

				if (component.isHavePrevTransform) {

					array.GetByIndex(component.prevTransformIndex).nextTransformIndex = component.nextTransformIndex;
					array.GetByIndex(component.prevTransformIndex).isHaveNextTransform = component.isHaveNextTransform;

				}
				else {

					headTransformIndexVector[level] = component.nextTransformIndex;
					headTransformVector[level] = IComponentPtr(array.Index2Id(component.nextTransformIndex), this);

				}

			}

		}

		void TransformSystem::GPUComputeMatricesForLevel(unsigned int level) {



		}

		void TransformSystem::CPUComputeMatricesForLevel(unsigned int level) {

			/* Compute Local Matrix */
			



			/* Compute World Matrix */
			if (level == 0) {



			}
			else {



			}

		}

		void TransformSystem::GPUSwapParentIndex(unsigned int index, unsigned int newIndex) {



		}

		void TransformSystem::CPUSwapParentIndex(unsigned int index, unsigned int newIndex) {
		
			Transform& parentTransform = array.GetByIndex(index);

			bool canContinue = parentTransform.isHaveHeadChild;

			while (canContinue) {

				Transform& childTransform = array.GetByIndex(parentTransform.headChildIndex);

				childTransform.parentTransformIndex = newIndex;

				canContinue = childTransform.isHaveNextSPT;

			}
		
		}



		/**
		 *	Event Methods
		 */
		void TransformSystem::Awake(TransformPtr componentPtr) {

			Transform& component = *componentPtr;

			component.level = 0;

			component.isHaveHeadChild = false;
			component.isHaveTailChild = false;

			component.isHaveNextTransform = false;
			component.isHavePrevTransform = false;

			component.isHaveNextSPT = false;
			component.isHavePrevSPT = false;

			component.childCount = 0;

			IncreaseTransformCount(component.level, componentPtr);

		}

		void TransformSystem::Start(TransformPtr componentPtr) {



		}

		void TransformSystem::PreUpdate() {

			unsigned int levelCount = transformCountVector.size();

			for (unsigned int level = 0; level < levelCount; ++level) {

				if (array.GetFilledCount() >= GPU_MIN_TRANSFORM_COUNT) {

					GPUComputeMatricesForLevel(level);

				}
				else {

					CPUComputeMatricesForLevel(level);

				}

			}

		}

		void TransformSystem::Update() {



		}

		void TransformSystem::LateUpdate() {

			//for (auto& transform : *this) {

				//ComputeMatrices(transform);

			//}

		}

		void TransformSystem::Destroy(TransformPtr componentPtr) {

			unsigned int componentIndex = array.Id2Index(componentPtr.GetId());

			if (componentPtr->level != 0) {

				RemoveChild(
					IComponentPtr(
						array.Index2Id(componentPtr->parentTransformIndex),
						this
					), 
					componentPtr
				);

			}

			DecreaseTransformCount(componentPtr->GetLevel(), componentPtr);

			/* Update Indices,... */
			if (array.GetFilledCount() != 1) {

				unsigned int lastTransformIndex = array.GetFilledCount() - 1;

				Transform& lastTransform = array.GetByIndex(array.GetFilledCount() - 1);
				{

					if (lastTransform.isHaveNextTransform) {

						Transform& nextTransform = array.GetByIndex(lastTransform.nextTransformIndex);

						nextTransform.prevTransformIndex = componentIndex;

					}
					if (lastTransform.isHavePrevTransform) {

						Transform& prevTransform = array.GetByIndex(lastTransform.prevTransformIndex);

						prevTransform.prevTransformIndex = componentIndex;

					}

					if (headTransformIndexVector[lastTransform.level] == array.GetFilledCount() - 1) {

						headTransformIndexVector[lastTransform.level] = componentIndex;

					}

					if (tailTransformIndexVector[lastTransform.level] == array.GetFilledCount() - 1) {

						tailTransformIndexVector[lastTransform.level] = componentIndex;

					}

					if (lastTransform.isHaveHeadChild) {

						if (array.GetFilledCount() >= GPU_MIN_TRANSFORM_COUNT)//transformCountVector[level] >= GPU_MIN_TRANSFORM_COUNT) 
						{

							GPUSwapParentIndex(lastTransformIndex, componentIndex);

						}
						else {

							CPUSwapParentIndex(lastTransformIndex, componentIndex);

						}

					}

				}

			}

		}

	}

}