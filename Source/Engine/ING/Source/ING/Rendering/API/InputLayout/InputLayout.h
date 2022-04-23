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
 *	Include Format
 */
#include <ING\Rendering\API\Format\Format.h>



/**
 *	Include Vector
 */
#include <vector>



namespace ING {

	namespace Rendering {

		enum InputClassification {

			INPUT_PER_VERTEX_DATA,

			INPUT_PER_INSTANCE_DATA

		};



		struct InputLayoutElementDesc {

			std::string					semanticName;
			unsigned int				semanticIndex;
			Format						format;
			unsigned int				inputSlot;
			unsigned int				alignedByteOffset;
			InputClassification			inputSlotClass;
			unsigned int				instanceDataStepRate;

		};



		class  IDevice;

		struct InputLayoutElementDesc;

		class IVertexShader;

		class IShader;



		class ING_API IInputLayout :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IInputLayout	(IDevice* device);
			~IInputLayout	();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Create Methods
			 */
		public:
			static IInputLayout* Create(IDevice* device, const std::vector<InputLayoutElementDesc>& desc, IShader* vshader);
			static IInputLayout* Create(const std::vector<InputLayoutElementDesc>& desc, IShader* vshader);



			/**
			 *	Properties
			 */
		private:
			IDevice* device;

		public:
			IDevice* GetDevice() { return device; }



			/**
			 *	Methods
			 */
		public:
			virtual void Apply();

		};

	}

}