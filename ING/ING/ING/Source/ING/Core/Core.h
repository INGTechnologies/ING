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



/**
 *	Include Memory
 */
#include <ING/Core/Memory/Memory.h>



namespace ING {

	class ING_API Core :
		public Singleton<Core>,
		public Square,
		public Board<Core>
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