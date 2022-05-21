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

			ShaderProperty(const String& name, unsigned int size) {

				this->name = name;

				this->size = size;

				offset = 0;

			}

			template<typename T>
			ShaderProperty(const String& name) :
				ShaderProperty(name, sizeof(T))
			{}

			ShaderProperty() {}

			String		name;
			unsigned int	size;
			unsigned int	offset;

		};



		struct ShaderView {

			ShaderView(const String& name, const String& type) {

				this->name = name;
				this->type = type;
				index = 0;

			}

			String		name;
			String		type;
			unsigned int	index;

		};



		struct ShaderCBuffer {

			ShaderCBuffer(const String& name) {

				this->name = name;

			}

			String		name;
			unsigned int	index;

		};



		class ING_API IShader {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IShader		(IDevice* device, const String& name);
			IShader		(const String& name);
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
			String					name;

			std::unordered_map<String, IShaderPass*>	passName2PassMap;

			std::vector<ShaderProperty> propertyVector;
			unsigned int				propertyTotalSize;
			std::unordered_map<String, unsigned int> propName2PropIndexMap;

			std::vector<ShaderView>		viewVector;
			std::unordered_map<String, unsigned int> viewName2ViewIndexMap;

			std::vector<ShaderCBuffer>	cbufferVector;
			std::unordered_map<String, unsigned int> cbufferName2CBufferIndexMap;

			std::vector<String>			filterNameVector;

			List<IMaterial*>			materialList;

		protected:
			IDevice* device;

		public:
			String						GetName		() const { return name; }

			const std::unordered_map<String, IShaderPass*>&	GetPassName2PassMap() const { return passName2PassMap; }
			IShaderPass*				GetPass		(const String& name);

			IDevice*					GetDevice	() { return device; }

			const std::vector<ShaderProperty>& GetPropertyVector() { return propertyVector; }
			unsigned int				GetPropertyTotalSize() { return propertyTotalSize; }
			unsigned int				GetPropertyCount() { return propertyVector.size(); }
			unsigned int				GetPropertyIndex(const String& name) { return propName2PropIndexMap[name]; }

			const std::vector<ShaderView>& GetViewVector() { return viewVector; }
			unsigned int				GetViewCount() { return viewVector.size(); }
			unsigned int				GetViewIndex(const String& name) { return viewName2ViewIndexMap[name]; }
			bool						IsHaveView(const String& name) {

				return viewName2ViewIndexMap.find(name) != viewName2ViewIndexMap.end();

			}

			const std::vector<ShaderCBuffer>& GetCBufferVector() { return cbufferVector; }
			unsigned int				GetCBufferCount() { return cbufferVector.size(); }
			unsigned int				GetCBufferIndex(const String& name) { return cbufferName2CBufferIndexMap[name]; }
			bool						IsHaveCBuffer(const String& name) {

				return cbufferName2CBufferIndexMap.find(name) != cbufferName2CBufferIndexMap.end();

			}

			const std::vector<String>&	GetFilterNameVector () { return filterNameVector; }
			void						SetFilterNameVector (const std::vector<String>& filterNameVector);

			const List<IMaterial*>&		GetMaterialList () { return materialList; }



			/**
			 *	Methods
			 */
		public:
			IShaderPass*	AddPass		(const String& name);
			void			RemovePass	(const String& name);

			List<IMaterial*>::Node*	AddMaterial	(IMaterial* material);
			void			RemoveMaterial(IMaterial* material);

			virtual void	Apply		(const String& name);

			virtual void	SetPropertyVector(const std::vector<ShaderProperty>& propertyVector);

			virtual void	SetViewVector(const std::vector<ShaderView>& viewVector);

			virtual void	SetCBufferVector(const std::vector<ShaderCBuffer>& cbufferVector);

		};

	}

}