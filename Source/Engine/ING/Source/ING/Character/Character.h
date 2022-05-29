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
 *	Include Pawn
 */
#include <ING/Pawn/Pawn.h>



namespace ING {

	class ING_API ICharacter : public IPawn
	{

		ING_REFLECT_CLASS(ICharacter, IPawn)



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