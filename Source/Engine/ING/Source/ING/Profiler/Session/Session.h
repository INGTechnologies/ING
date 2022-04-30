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
 *	Include Chrono
 */
#include <chrono>



namespace ING {

	class ING_API ProfilerSession
	{
		/**
		 *	Constructors And Destructor
		 */
	public:
		ProfilerSession		(String name, String category);
		~ProfilerSession	();



		/**
		 *	Properties
		 */
	private:
		String							name;

		String							category;

		std::chrono::duration<float>		startTime;

		std::chrono::duration<float>		endTime;

		std::chrono::duration<float>		completeTime;

		List<ProfilerSession*>::Node*		node;

	public:
		const String&					GetName			() { return name; }

		const String&					GetCategory		() { return category; }

		const std::chrono::duration<float>& GetStartTime	() { return startTime; }

		const std::chrono::duration<float>& GetEndTime		() { return endTime; }

		const std::chrono::duration<float>& GetCompleteTime	() { return completeTime; }

		List<ProfilerSession*>::Node*		GetNode			() { return node; }



		/**
		 *	Methods
		 */
	public:
		void	End();
		float	CheckTime();

	};

}