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



		struct ShaderProperty {

			ShaderProperty(const std::string& name, unsigned int size) {

				this->name = name;

				this->size = size;

				offset = 0;

			}

			ShaderProperty() {}

			std::string		name;
			unsigned int	size;
			unsigned int	offset;

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

		};

	}

}