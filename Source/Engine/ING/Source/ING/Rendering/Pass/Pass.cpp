
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



/**
 *	Include Rendering Pipeline
 */
#include <ING/Rendering/Pipeline/Pipeline.h>



namespace ING {

	namespace Rendering {

		ING_BEGIN_REFLECTED_CLASS
			(C_Pass, Reflection::C_Object)

			ING_CLASS_CONSTRUCTOR
				(C_Pass, const String&)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_Pass::Constructor(const String& name) {

			this->name = name;

			parent = 0;

		}



		/**
		 *	Release Methods
		 */
		void C_Pass::Release	() {

			if (parent != 0) {

				parent->RemoveChild(this);

			}
			else {

				pipeline->RemovePass(this);

			}

			for (unsigned int i = 0; i < childVector.size();) {

				childVector[i]->Release();

			}

			childVector.clear();

			Reflection::C_Object::Release();

		}



		/**
		 *	Properties
		 */
		void C_Pass::SetParent(C_Pass* newParent) {

			for (auto child : childVector) {

				child->SetParent(newParent);

			}

			parent = newParent;

			SetPipeline(pipeline);

		}

		void C_Pass::SetPipeline(C_Pipeline* pipeline) {

			for (auto child : childVector) {

				child->SetPipeline(pipeline);

			}

			this->pipeline = pipeline;

		}



		/**
		 *	Methods
		 */
		void C_Pass::AddChild(C_Pass* pass) {

			AddChild(pass, childVector.size());

		}

		void C_Pass::AddChild(C_Pass* pass, unsigned int index) {

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

		void C_Pass::RemoveChild(unsigned int index) {

			String childName = GetChild(index)->GetName();

			childVector.erase(childVector.begin() + index);

			unsigned int passCount = childVector.size();

			for (unsigned int i = index + 1; i < passCount; ++i) {

				name2ChildIndex[childVector[i]->GetName()]--;

			}

			name2ChildIndex.erase(childName);

		}

		void C_Pass::RemoveChild(const String& name) {

			RemoveChild(name2ChildIndex[name]);

		}

		void C_Pass::RemoveChild(C_Pass* pass) {

			RemoveChild(pass->GetName());

		}

		bool C_Pass::Render(IDeviceContext* context, C_Camera* camera) {

			for (auto child : childVector) {

				child->Render(context, camera);

			}

			return true;
		}

	}

}