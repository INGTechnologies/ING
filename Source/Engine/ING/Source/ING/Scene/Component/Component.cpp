
/**
 *	Include Header
 */
#include "Component.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ISceneComponent::ISceneComponent(const String& typeId) :
		typeId(typeId)
	{



	}

	ISceneComponent::~ISceneComponent()
	{



	}



	/**
	 *	Release Methods
	 */
	void ISceneComponent::Release()
	{

		delete this;

	}
	
}