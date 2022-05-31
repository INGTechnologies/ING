
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
		(C_Actor, Reflection::C_Object)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(C_Actor, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Properties
		 */
		ING_CLASS_PROPERTY		
			(C_Actor, name)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROPERTY		
			(C_Actor, componentVector)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Property Getters And Setters
		 */
		ING_CLASS_FUNCTION		
			(C_Actor, GetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROCEDURE
			(C_Actor, SetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(C_Actor, GetComponentVector, const std::vector<C_ActorComponent*>&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION
			(C_Actor, GetComponentIndex, unsigned int, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION
			(C_Actor, IsHasComponent, bool, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION
			(C_Actor, GetComponent, C_ActorComponent* , unsigned int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION
			(C_Actor, GetComponentByName, C_ActorComponent* , const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Methods
		 */
		ING_CLASS_PROCEDURE
			(C_Actor, AddComponent, C_ActorComponent*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROCEDURE
			(C_Actor, AddComponentByIndex, C_ActorComponent*, unsigned int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);
		
		ING_CLASS_PROCEDURE
			(C_Actor, RemoveComponentByIndex, unsigned int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);
		
		ING_CLASS_PROCEDURE
			(C_Actor, RemoveComponentByName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROCEDURE
			(C_Actor, RemoveComponent, C_ActorComponent*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void C_Actor::Constructor(const String& name)
	{

		this->name = name;

	}



	/**
	 *	Release Methods
	 */
	void C_Actor::Release()
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
	void C_Actor::AddComponent(C_ActorComponent* component) {

		AddComponentByIndex(component, componentVector.size());

	}

	void C_Actor::AddComponentByIndex(C_ActorComponent* component, unsigned int index) {

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

	void C_Actor::RemoveComponentByIndex(unsigned int index) {

		String componentName = GetComponent(index)->GetName();

		GetComponent(index)->actor = 0;

		componentVector.erase(componentVector.begin() + index);

		unsigned int passCount = componentVector.size();

		for (unsigned int i = index; i < passCount; ++i) {

			name2ComponentIndexMap[componentVector[i]->GetName()]--;

		}

		name2ComponentIndexMap.erase(componentName);

	}

	void C_Actor::RemoveComponentByName(const String& componentName) {

		RemoveComponentByIndex(name2ComponentIndexMap[componentName]);

	}

	void C_Actor::RemoveComponent(C_ActorComponent* component) {

		RemoveComponentByName(component->GetName());

	}

}