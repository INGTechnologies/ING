
/**
 *	Include Header
 */
#include "Component.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Actor
 */
#include <ING/Actor/Actor.h>



namespace ING {

	ING_BEGIN_REFLECTED_CLASS
		(IActorComponent, Reflection::IObject)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(IActorComponent, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Properties
		 */
		ING_CLASS_PROPERTY		
			(IActorComponent, name)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROPERTY		
			(IActorComponent, actor)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Property Getters And Setters
		 */
		ING_CLASS_FUNCTION		
			(IActorComponent, GetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROCEDURE
			(IActorComponent, SetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(IActorComponent, GetActor, const IActor*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(IActorComponent, GetIndex, unsigned int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void IActorComponent::Constructor(const String& name)
	{

		this->name = name;

		actor = 0;

	}



	/**
	 *	Properties
	 */
	unsigned int IActorComponent::GetIndex() { 
		
		return GetActor()->GetComponentIndex(name); 
	}



	/**
	 *	Release Methods
	 */
	void IActorComponent::Release()
	{

		actor->RemoveComponent(this);

		delete this;
	}

}