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

	class Window;

	namespace Rendering {

		class Device;

		class RenderTargetView;



		class ING_API SwapChain
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			SwapChain(Device* device, Window* window);
			~SwapChain();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  SwapChain*	Create(Device* device, Window* window);
			virtual void		Release();



			/**
			 *	Device
			 */
		private:
			Device* device;

		public:
			Device* GetDevice() { return device; }



			/**
			 *	Node
			 */
		private:
			List<SwapChain*>::Node* node;

		public:
			List<SwapChain*>::Node* GetNode() { return node; }



			/**
			 *	Window
			 */
		private:
			Window* window;

		public:
			Window* GetWindow() { return window; }



			/**
			 *	Views
			 */
		private:
			RenderTargetView* renderTargetView;
			
		public:
			RenderTargetView* GetRenderTargetView() { return renderTargetView; }

		};

	}

}