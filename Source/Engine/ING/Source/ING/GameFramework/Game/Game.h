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

	class C_GameMode;



	class ING_API C_Game : public Reflection::C_Object
	{

		ING_REFLECT_CLASS(C_Game, Reflection::C_Object)



		/**
		 *	Constructor
		 */
	protected:
		void			Constructor(const String& name);



		/**
		 *	Properties
		 */
	private:
		String			name;

		IClass*			modeClass;
		C_GameMode*		mode;

	public:
		const String&	GetName () { return name; }

		IClass*			GetModeClass () { return modeClass; }
		C_GameMode*		GetMode () { return mode; }



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