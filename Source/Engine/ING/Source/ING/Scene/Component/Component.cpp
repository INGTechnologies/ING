
/**
 *	Include Header
 */
#include "Component.h"



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ISceneComponent::ISceneComponent(const std::string& typeId) :
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