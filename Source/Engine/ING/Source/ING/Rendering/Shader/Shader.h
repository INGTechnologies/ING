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
 *	Include Vector
 */
#include <vector>



namespace ING {

	namespace Rendering {

		class IShaderPass;

		class IMaterial;

		class IDevice;

		class IView;



		struct ShaderProperty {

			ShaderProperty(const std::string& name, unsigned int size) {

				this->name = name;

				this->size = size;

				offset = 0;

			}

			template<typename T>
			ShaderProperty(const std::string& name) :
				ShaderProperty(name, sizeof(T))
			{}

			ShaderProperty() {}

			std::string		name;
			unsigned int	size;
			unsigned int	offset;

		};



		struct ShaderView {

			ShaderView(const std::string& name, const std::string& type) {

				this->name = name;
				this->type = type;
				index = 0;

			}

			std::string		name;
			std::string		type;
			unsigned int	index;

		};



		struct ShaderCBuffer {

			ShaderCBuffer(const std::string& name) {

				this->name = name;

			}

			std::string		name;
			unsigned int	index;

		};



		class ING_API IShader {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IShader		(IDevice* device, const std::string& name);
			IShader		(const std::string& name);
			~IShader	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			std::string					name;

			std::unordered_map<std::string, IShaderPass*>	passName2PassMap;

			std::vector<ShaderProperty> propertyVector;
			unsigned int				propertyTotalSize;
			std::unordered_map<std::string, unsigned int> propName2PropIndexMap;

			std::vector<ShaderView>		viewVector;
			std::unordered_map<std::string, unsigned int> viewName2ViewIndexMap;

			std::vector<ShaderCBuffer>	cbufferVector;
			std::unordered_map<std::string, unsigned int> cbufferName2CBufferIndexMap;

			List<IMaterial*>			materialList;

		protected:
			IDevice* device;

		public:
			std::string					GetName		() const { return name; }

			const std::unordered_map<std::string, IShaderPass*>&	GetPassName2PassMap() const { return passName2PassMap; }
			IShaderPass*				GetPass		(const std::string& name);

			IDevice*					GetDevice	() { return device; }

			const std::vector<ShaderProperty>& GetPropertyVector() { return propertyVector; }
			unsigned int				GetPropertyTotalSize() { return propertyTotalSize; }
			unsigned int				GetPropertyCount() { return propertyVector.size(); }
			unsigned int				GetPropertyIndex(const std::string& name) { return propName2PropIndexMap[name]; }

			const std::vector<ShaderView>& GetViewVector() { return viewVector; }
			unsigned int				GetViewCount() { return viewVector.size(); }
			unsigned int				GetViewIndex(const std::string& name) { return viewName2ViewIndexMap[name]; }
			bool						IsHaveView(const std::string& name) {

				return viewName2ViewIndexMap.find(name) != viewName2ViewIndexMap.end();

			}

			const std::vector<ShaderCBuffer>& GetCBufferVector() { return cbufferVector; }
			unsigned int				GetCBufferCount() { return cbufferVector.size(); }
			unsigned int				GetCBufferIndex(const std::string& name) { return cbufferName2CBufferIndexMap[name]; }
			bool						IsHaveCBuffer(const std::string& name) {

				return cbufferName2CBufferIndexMap.find(name) != cbufferName2CBufferIndexMap.end();

			}



			/**
			 *	Methods
			 */
		public:
			IShaderPass*	AddPass		(const std::string& name);
			void			RemovePass	(const std::string& name);

			List<IMaterial*>::Node*	AddMaterial	(IMaterial* material);
			void			RemoveMaterial(IMaterial* material);

			virtual void	Apply		(const std::string& name);

			virtual void	SetPropertyVector(const std::vector<ShaderProperty>& propertyVector);

			virtual void	SetViewVector(const std::vector<ShaderView>& viewVector);

			virtual void	SetCBufferVector(const std::vector<ShaderCBuffer>& cbufferVector);

		};

	}

}