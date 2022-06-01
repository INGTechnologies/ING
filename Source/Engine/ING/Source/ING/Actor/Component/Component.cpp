
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
		(C_ActorComponent, Reflection::C_Object)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(C_ActorComponent, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Properties
		 */
		ING_CLASS_PROPERTY		
			(C_ActorComponent, name)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROPERTY		
			(C_ActorComponent, actor)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		/**
		 *	Property Getters And Setters
		 */
		ING_CLASS_FUNCTION		
			(C_ActorComponent, GetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROCEDURE
			(C_ActorComponent, SetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(C_ActorComponent, GetActor, const C_Actor*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(C_ActorComponent, GetIndex, unsigned int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void C_ActorComponent::Constructor(const String& name)
	{

		this->name = name;

		actor = 0;

	}



	/**
	 *	Properties
	 */
	unsigned int C_ActorComponent::GetIndex() { 
		
		return GetActor()->GetComponentIndex(name); 
	}



	/**
	 *	Release Methods
	 */
	void C_ActorComponent::Release()
	{

		actor->RemoveComponent(this);

		Reflection::C_Object::Release();
	}

}