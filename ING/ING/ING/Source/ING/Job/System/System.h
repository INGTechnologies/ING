#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {


	class ING_API JobSystem :
		public Singleton<JobSystem>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		JobSystem();
		~JobSystem();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};


}