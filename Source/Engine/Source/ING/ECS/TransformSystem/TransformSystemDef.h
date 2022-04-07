#pragma once

/**
 *	Include Header
 */
#include "TransformSystem.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Rendering Buffer
 */
#include <ING/Rendering/API/Resource/Buffer/Buffer.h>



/**
 *	Include Rendering StructuredBuffer
 */
#include <ING/Rendering/API/Resource/StructuredBuffer/StructuredBuffer.h>



namespace ING {

	namespace ECS {

		/**
		 *	Init And Release Methods
		 */
		void TransformSystem::Init() {

			oldArraySize = 0;

			RecreateBuffers();

		}

		void TransformSystem::Release() {

			for (auto indexArray : indexArrayVector) {

				indexArray->Clear();

				delete indexArray;

			}

			for (auto indexBuffer : indexBufferVector) {

				if(indexBuffer != 0)
					indexBuffer->Release();

			}

			indexArrayVector.clear();

			IComponentSystem::Release();

		}



		/**
		 *	Methods
		 */
		void TransformSystem::RecreateBuffers		() {

			RecreateMainBuffer();

			RecreateIndexBuffers();

		}

		void TransformSystem::RecreateMainBuffer	() {

			/* Release Main Buffer */
			if (mainBuffer != nullptr) {

				mainBuffer->Release();

				mainBuffer = nullptr;

			}



			if (array.GetFilledCount() == 0) return;

			

			/* Create Main Buffer */
			mainBuffer = Rendering::IStructuredBuffer::Create(
				{

					array.GetCount(),
					sizeof(ECS::Transform),
					Rendering::USAGE_DEFAULT,
					Rendering::BIND_SHADER_RESOURCE | Rendering::BIND_UNORDERED_ACCESS,
					Rendering::CPU_ACCESS_READ | Rendering::CPU_ACCESS_WRITE

				}, 
				array.GetPData()
			);

			oldArraySize = array.GetCount();

		}

		void TransformSystem::RecreateIndexBuffers() {

			for (unsigned int i = 0; i < indexBufferVector.size(); ++i) {

				if (indexBufferVector[i] != nullptr) {

					indexBufferVector[i]->Release();

					indexBufferVector[i] = 0;

				}

			}

			for (unsigned int i = 0; i < indexBufferVector.size(); ++i) {

				RecreateIndexBuffer(i);

			}

		}

		void TransformSystem::RecreateIndexBuffer(unsigned int level) {

			if (indexBufferVector[level] != nullptr) {

				indexBufferVector[level]->Release();

				indexBufferVector[level] = 0;

			}



			indexBufferVector[level] = Rendering::IStructuredBuffer::Create(
				{

					indexArrayVector[level]->GetCount(),
					sizeof(unsigned int),
					Rendering::USAGE_DEFAULT,
					Rendering::BIND_SHADER_RESOURCE | Rendering::BIND_UNORDERED_ACCESS,
					Rendering::CPU_ACCESS_READ | Rendering::CPU_ACCESS_WRITE

				},
				indexArrayVector[level]->GetPData()
			);

			int a = 5;

		}

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
				array.GetByIndex(parentTransform.tailChildIndex).isTailSPT = false;
				array.GetByIndex(parentTransform.tailChildIndex).nextSPTIndex = childComponentIndex;

				childTransform.isHavePrevSPT = true;
				childTransform.prevSPTIndex = parentTransform.tailChildIndex;

				parentTransform.tailChildIndex = childComponentIndex;

			}
			else {

				parentTransform.headChildIndex = childComponentIndex;
				parentTransform.tailChildIndex = childComponentIndex;

				childTransform.isHeadSPT = true;
				childTransform.isHavePrevSPT = false;

			}
			childTransform.isHaveNextSPT = false;

			parentTransform.isHaveHeadChild = true;
			parentTransform.isHaveTailChild = true;

			childTransform.isTailSPT = true;

			parentTransform.childCount++;

			childTransform.parentPtr = parentPtr;

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

				if (childTransform.isHavePrevSPT) {

					array.GetByIndex(childTransform.prevSPTIndex).isTailSPT = true;

				}

			}

			if (childTransform.isHavePrevSPT) {

				array.GetByIndex(childTransform.prevSPTIndex).nextSPTIndex = childTransform.nextSPTIndex;
				array.GetByIndex(childTransform.prevSPTIndex).isHaveNextSPT = childTransform.isHaveNextSPT;

			}
			else {

				parentTransform.headChildIndex = childTransform.nextSPTIndex;

				if (childTransform.isHaveNextSPT) {

					array.GetByIndex(childTransform.nextSPTIndex).isHeadSPT = true;

				}

			}

			childTransform.isHeadSPT = false;
			childTransform.isTailSPT = false;

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

				indexArrayVector.resize(level + 1);
				indexArrayVector[level] = new SmartArray<unsigned int>();

				oldIndexArraySizeVector.resize(level + 1);
				oldIndexArraySizeVector[level] = 1;

				indexBufferVector.resize(level + 1);
				indexBufferVector[level] = 0;
				//RecreateIndexBuffer(level);

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


			indexArrayVector[level]->Add(componentIndex, componentPtr.GetId());

			if (indexArrayVector[level]->GetCount() != oldIndexArraySizeVector[level] || oldIndexArraySizeVector[level] == 1) {

				RecreateIndexBuffer(level);

			}

			oldIndexArraySizeVector[level] = indexArrayVector[level]->GetCount();
		}

		void TransformSystem::DecreaseTransformCount(unsigned int level, TransformPtr componentPtr) {

			Transform& component = *componentPtr;

			transformCountVector[level]--;

			indexArrayVector[level]->Erase(componentPtr.GetId());


			if (transformCountVector[level] == 0) {

				transformCountVector.resize(level);
				headTransformVector.resize(level);
				headTransformIndexVector.resize(level);
				tailTransformVector.resize(level);
				tailTransformIndexVector.resize(level);

				indexArrayVector.resize(level);
				delete (indexArrayVector[level]);

				oldIndexArraySizeVector.resize(level);

				if (indexBufferVector[level] != nullptr) {

					indexBufferVector[level]->Release();
					indexBufferVector[level] = 0;

				}
				indexBufferVector.resize(level);

			}
			else {

				if (indexArrayVector[level]->GetCount() != oldIndexArraySizeVector[level]) {

					RecreateIndexBuffer(level);

				}

				oldIndexArraySizeVector[level] = indexArrayVector[level]->GetCount();

				



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
			component.isHaveNextTransform = false;
			component.isHavePrevTransform = false;
			component.nextTransformIndex = 0;
			component.prevTransformIndex = 0;

			component.isHeadSPT = false;
			component.isTailSPT = false;
			component.isHaveNextSPT = false;
			component.isHavePrevSPT = false;
			component.nextSPTIndex = 0;
			component.prevSPTIndex = 0;

			component.childCount = 0;
			component.isHaveHeadChild = false;
			component.isHaveTailChild = false;
			component.headChildIndex = 0;
			component.tailChildIndex = 0;

			component.parentTransformIndex = 0;

			IncreaseTransformCount(component.level, componentPtr);

			if (array.GetCount() != oldArraySize) {

				RecreateMainBuffer();

			}

		}

		void TransformSystem::Start(TransformPtr componentPtr) {



		}

		void TransformSystem::PreUpdate() {



		}

		void TransformSystem::Update() {



		}

		void TransformSystem::LateUpdate() {



		}

		void TransformSystem::PreRender() {

			unsigned int levelCount = transformCountVector.size();

			for (unsigned int level = 0; level < levelCount; ++level) {

				if (transformCountVector[level] >= GPU_MIN_TRANSFORM_COUNT) {

					GPUComputeMatricesForLevel(level);

				}
				else {

					CPUComputeMatricesForLevel(level);

				}

			}

		}

		void TransformSystem::Render() {



		}

		void TransformSystem::LateRender() {



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

						prevTransform.nextTransformIndex = componentIndex;

					}

					if (lastTransform.isHaveNextSPT) {

						Transform& nextTransform = array.GetByIndex(lastTransform.nextSPTIndex);

						nextTransform.prevSPTIndex = componentIndex;

					}
					if (lastTransform.isHavePrevSPT) {

						Transform& prevTransform = array.GetByIndex(lastTransform.prevSPTIndex);

						prevTransform.nextSPTIndex = componentIndex;

					}

					if (lastTransform.isTailSPT) {

						lastTransform.parentPtr->tailChildIndex = componentIndex;

					}

					if (lastTransform.isHeadSPT) {

						lastTransform.parentPtr->headChildIndex = componentIndex;

					}

					if (lastTransform.isHaveHeadChild) {

						Transform& headChildTransform = array.GetByIndex(lastTransform.headChildIndex);

						headChildTransform.parentTransformIndex = lastTransformIndex;

					}

					if (headTransformIndexVector[lastTransform.level] == array.GetFilledCount() - 1) {

						headTransformIndexVector[lastTransform.level] = componentIndex;

					}

					if (tailTransformIndexVector[lastTransform.level] == array.GetFilledCount() - 1) {

						tailTransformIndexVector[lastTransform.level] = componentIndex;

					}

					indexArrayVector[lastTransform.level]->Get(lastTransform.GetId()) = componentIndex;

				}

			}

		}

		void TransformSystem::IAfterDestroy() {

			if (array.GetCount() != oldArraySize) {

				RecreateMainBuffer();

			}

		}

	}

}