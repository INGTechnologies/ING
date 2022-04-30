
/**
 * Include Header
 */
#include "Pass.h"



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IPass::IPass	(const String& name) : 
			parent(0),
			name(name)
		{



		}

		IPass::~IPass	() {



		}



		/**
		 *	Release Methods
		 */
		void IPass::Release	() {

			for (unsigned int i = 0; i < childVector.size();) {

				RemoveChild(i);

				childVector[i]->Release();

			}

			delete this;

		}



		/**
		 *	Properties
		 */
		void IPass::SetParent(IPass* newParent) {

			for (auto child : childVector) {

				child->SetParent(newParent);

			}

			parent = newParent;

		}

		void IPass::SetPipeline(IPipeline* pipeline) {

			for (auto child : childVector) {

				child->SetPipeline(pipeline);

			}

			this->pipeline = pipeline;

		}



		/**
		 *	Methods
		 */
		void IPass::AddChild(IPass* pass) {

			AddChild(pass, childVector.size());

		}

		void IPass::AddChild(IPass* pass, unsigned int index) {

			if (childVector.size() == index) {

				childVector.push_back(pass);

			}
			else {

				childVector.insert(childVector.begin() + index, pass);

				unsigned int passCount = childVector.size();

				for (unsigned int i = index + 1; i < passCount; ++i) {

					name2ChildIndex[childVector[i]->GetName()]++;

				}

			}

			name2ChildIndex[pass->GetName()] = index;

		}

		void IPass::RemoveChild(unsigned int index) {

			childVector.erase(childVector.begin() + index);

			unsigned int passCount = childVector.size();

			for (unsigned int i = index; i < passCount; ++i) {

				name2ChildIndex[childVector[i]->GetName()]--;

			}

			name2ChildIndex.erase(GetChild(index)->GetName());

		}

		void IPass::RemoveChild(const String& name) {

			RemoveChild(name2ChildIndex[name]);

		}

		void IPass::RemoveChild(IPass* pass) {

			RemoveChild(pass->GetName());

		}

		bool IPass::Render(IDeviceContext* context, Camera* camera) {



			return true;
		}

	}

}