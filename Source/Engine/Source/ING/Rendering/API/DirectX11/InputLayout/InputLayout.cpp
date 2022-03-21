
/**
 *	Include Header
 */
#include "InputLayout.h"



/**
 *	Include DirectX11 Vertex Shader
 */
#include <ING/Rendering/API/DirectX11/Shader/VertexShader/VertexShader.h>



/**
 *	Include DirectX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include DirectX11 Rendering Device
 */
#include <ING/Rendering/API/DirectX11/Device/Device.h>



/**
 *	Include DirectX11 Rendering Device Context
 */
#include <ING/Rendering/API/DirectX11/Device/Context/Context.h>



/**
 *	Include DirectX11 Vertex Shader
 */
#include <ING/Rendering/API/DirectX11/Shader/VertexShader/VertexShader.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			InputLayout::InputLayout(IDevice* device, const std::vector<InputLayoutElementDesc>& desc, IVertexShader* vshader) : IInputLayout(device) {

				unsigned int elementCount = desc.size();

				D3D11_INPUT_ELEMENT_DESC* elements = new D3D11_INPUT_ELEMENT_DESC[elementCount];

				for (unsigned int i = 0; i < elementCount; ++i) {

					D3D11_INPUT_CLASSIFICATION inputSlotClass = (D3D11_INPUT_CLASSIFICATION)((unsigned int)desc[i].inputSlotClass);

					elements[i] = {
					
						desc[i].semanticName.c_str(),
						desc[i].semanticIndex,
						DirectX11::Convertor::GetInstance()->Format(desc[i].format),
						desc[i].inputSlot,
						desc[i].alignedByteOffset,
						inputSlotClass,
						desc[i].instanceDataStepRate
					
					};

				}

				HRESULT hr = device->As<DirectX11::Device>()->GetD3D11Device()->CreateInputLayout(
					elements,
					elementCount,
					((VertexShader*)vshader)->GetBlob()->GetBufferPointer(),
					((VertexShader*)vshader)->GetBlob()->GetBufferSize(),
					&d3d11InputLayout
				);

				delete elements;

			}

			InputLayout::~InputLayout() {



			}



			/**
			 *	Release Methods
			 */
			void InputLayout::Release() {

				if (d3d11InputLayout != nullptr)
					d3d11InputLayout->Release();

				IInputLayout::Release();

			}



			/**
			 *	Methods
			 */
			void InputLayout::Apply() {

				GetDevice()->GetContext()->As<DirectX11::DeviceContext>()->IASetInputLayout(this);

			}

		}

	}

}