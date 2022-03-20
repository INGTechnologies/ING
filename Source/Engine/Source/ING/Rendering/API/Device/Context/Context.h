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
 *	Include Color
 */
#include <ING\Color/Color.h>



/**
 *	Include Format
 */
#include <ING\Rendering/API\Format/Format.h>



namespace ING {

	namespace Rendering {

		class IRenderTargetView;

		class IInputLayout;

		class IDevice;

		class IBuffer;



		class ING_API IDeviceContext :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IDeviceContext(IDevice* device);
			~IDeviceContext();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  IDeviceContext*	Create(IDevice* device);
			virtual void			Release();



			/**
			 *	IDevice Context
			 */
		protected:
			IDevice* device;

		public:
			IDevice* GetIDevice() { return device; }



			/**
			 *	Methods
			 */
		public:
			virtual void IASetInputLayout	(IInputLayout* inputLayout);
			virtual void IASetVertexBuffers	(const std::vector<IBuffer*>& buffers);
			virtual void IASetVertexBuffer	(IBuffer* buffer, unsigned int stride, unsigned int offset);
			virtual void IASetIndexBuffer	(IBuffer* buffer, Format format, unsigned int offset);

		};

	}

}