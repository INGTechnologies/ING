
/**
 *	Include Header
 */
#include "Actor.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Actor Component
 */
#include <ING/Actor/Component/Component.h>



namespace ING {

	ING_BEGIN_REFLECTED_CLASS
		(IActor, Reflection::IObject)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(IActor, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Properties
		 */
		ING_CLASS_PROPERTY		
			(IActor, name)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROPERTY		
			(IActor, componentVector)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Property Getters And Setters
		 */
		ING_CLASS_FUNCTION		
			(IActor, GetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROCEDURE
			(IActor, SetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(IActor, GetComponentVector, const std::vector<IActorComponent*>&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION
			(IActor, GetComponentIndex, unsigned int, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION
			(IActor, IsHasComponent, bool, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION
			(IActor, GetComponent, IActorComponent* , unsigned int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION
			(IActor, GetComponentByName, IActorComponent* , const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Methods
		 */
		ING_CLASS_PROCEDURE
			(IActor, AddComponent, IActorComponent*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROCEDURE
			(IActor, AddComponentByIndex, IActorComponent*, unsigned int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);
		
		ING_CLASS_PROCEDURE
			(IActor, RemoveComponentByIndex, unsigned int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);
		
		ING_CLASS_PROCEDURE
			(IActor, RemoveComponentByName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROCEDURE
			(IActor, RemoveComponent, IActorComponent*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void IActor::Constructor(const String& name)
	{

		this->name = name;

	}



	/**
	 *	Release Methods
	 */
	void IActor::Release()
	{

		for (unsigned int i = 0; i < componentVector.size();) {

			componentVector[i]->Release();

		}

		componentVector.clear();

		delete this;
	}



	/**
	 *	Methods
	 */
	void IActor::AddComponent(IActorComponent* component) {

		AddComponentByIndex(component, componentVector.size());

	}

	void IActor::AddComponentByIndex(IActorComponent* component, unsigned int index) {

		if (componentVector.size() == index) {

			componentVector.push_back(component);

		}
		else {

			componentVector.insert(componentVector.begin() + index, component);

			unsigned int passCount = componentVector.size();

			for (unsigned int i = index + 1; i < passCount; ++i) {

				name2ComponentIndexMap[componentVector[i]->GetName()]++;

			}

		}

		name2ComponentIndexMap[component->GetName()] = index;

		component->actor = this;

	}

	void IActor::RemoveComponentByIndex(unsigned int index) {

		String componentName = GetComponent(index)->GetName();

		GetComponent(index)->actor = 0;

		componentVector.erase(componentVector.begin() + index);

		unsigned int passCount = componentVector.size();

		for (unsigned int i = index; i < passCount; ++i) {

			name2ComponentIndexMap[componentVector[i]->GetName()]--;

		}

		name2ComponentIndexMap.erase(componentName);

	}

	void IActor::RemoveComponentByName(const String& componentName) {

		RemoveComponentByIndex(name2ComponentIndexMap[componentName]);

	}

	void IActor::RemoveComponent(IActorComponent* component) {

		RemoveComponentByName(component->GetName());

	}

}