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

	namespace Rendering {

		class SwapChain;

		class API;



		class ING_API SwapChainManager :
			public Singleton<SwapChainManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			SwapChainManager();
			~SwapChainManager();



			/**
			 *	Init, Init API, Run, Release Methods
			 */
		public:
			virtual bool	Init()		override;
			virtual bool	Run()		override;
			virtual bool	Release()	override;



			/**
			 *	SwapChain Management
			 */
		protected:
			List<SwapChain*> swapChainList;

		public:
			SwapChain*	GetMainSwapChain	() { return swapChainList.GetHead(); }

			void		AddSwapChain		(SwapChain* swapChain);

			void		RemoveSwapChain		(List<SwapChain*>::Node* node);

		};

	}

}