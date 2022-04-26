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

	class IWindow;

	namespace Rendering {

		class IDevice;

		class IRenderTargetView;



		class ING_API ISwapChain :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ISwapChain(IDevice* device, IWindow* window);
			~ISwapChain();



			/**
			 *	Create, InitEvents Release Methods
			 */
		public:
			static  ISwapChain*	Create(IDevice* device, IWindow* window);
			virtual void		InitEvents();
			virtual void		Release();



			/**
			 *	Device
			 */
		private:
			IDevice* device;

		public:
			IDevice* GetDevice() { return device; }



			/**
			 *	Node
			 */
		private:
			List<ISwapChain*>::Node* node;

		public:
			List<ISwapChain*>::Node* GetNode() { return node; }



			/**
			 *	Window
			 */
		private:
			IWindow* window;

		public:
			IWindow* GetWindow() { return window; }



			/**
			 *	Views
			 */
		private:
			IRenderTargetView* renderTargetView;
			
		public:
			IRenderTargetView* GetRenderTargetView() { return renderTargetView; }



			/**
			 *	Methods
			 */
		public:
			virtual void Resize(unsigned int width, unsigned int height);

			virtual void Present();

		};

	}

}