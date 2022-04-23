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



/**
 *	Include Chrono
 */
#include <chrono>



namespace ING {

	class Thread;

	class ING_API Time :
		public Singleton<Time>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		Time();
		~Time();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	Start, End Methods
		 */
	public:
		void StartFrame();
		void EndFrame();



		/**
		 *	Properties
		 */
	private:
		std::chrono::duration<float> frameStart;
		std::chrono::duration<float> frameEnd;
		float deltaTime;

	public:
		static float GetDeltaTime();

		static float GetFPS();

	};


}