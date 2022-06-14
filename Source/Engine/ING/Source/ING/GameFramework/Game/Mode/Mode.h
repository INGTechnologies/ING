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
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	class C_Game;



	class ING_API C_GameMode : public Reflection::C_Object
	{

		ING_REFLECT_CLASS(C_GameMode, Reflection::C_Object)



		/**
		 *	Constructor
		 */
	protected:
		void			Constructor(C_Game* game);



		/**
		 *	Properties
		 */
	private:
		C_Game*			game;

	public:
		C_Game*			GetGame () { return game; }



		/**
		 *	Release Methods
		 */
	public:
		virtual void	Release() override;



		/**
		 *	Methods
		 */
	public:
		virtual void Play();
		virtual void Stop();

	};

}