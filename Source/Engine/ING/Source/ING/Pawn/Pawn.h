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

	class ING_API C_Pawn : public C_Actor
	{

		ING_REFLECT_CLASS(C_Pawn, C_Actor)



		/**
		 *	Constructor
		 */
	protected:
		void			Constructor(const String& name);



		/**
		 *	Release Methods
		 */
	public:
		virtual void	Release() override;

	};

}