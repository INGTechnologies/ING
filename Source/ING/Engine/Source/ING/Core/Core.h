#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class ING_API Core :
		public Board<Core>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		Core();
		~Core();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};



	/**
	 *	Define Macros
	 */


}