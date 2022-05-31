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

	class ING_API C_Character : public C_Pawn
	{

		ING_REFLECT_CLASS(C_Character, C_Pawn)



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