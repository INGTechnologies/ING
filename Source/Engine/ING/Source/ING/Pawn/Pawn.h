#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



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

	class ING_API IPawn : public IActor
	{

		ING_REFLECT_CLASS(IPawn, IActor)



		/**
		 *	Constructor
		 */
	protected:
		void			Constructor();



		/**
		 *	Release Methods
		 */
	public:
		virtual void	Release() override;

	};

}