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
 *	Include Rendering Material Manager
 */
#include <ING/Rendering/Material/Manager/Manager.h>



/**
 *	Include EventStorage
 */
#include <ING/Event/Storage/Storage.h>



namespace ING {

	namespace Rendering {

		class IDrawableCategory;

		class IDrawble;

		class IShader;

		class IDeviceContext;

		class IDevice;

		class IBuffer;

		class IView;



		struct MaterialProperty {

			String  name;
			void*		 pData;
			unsigned int size;

		};



		struct MaterialView {

			MaterialView () {}

			MaterialView (

				const String& name, 
				const String& type,
				IView* view,
				unsigned int index
			
			) :
				name(name),
				type(type),
				view(view),
				index(index)
			{}

			String name;
			String type;
			IView* view;
			unsigned int index;

		};



		class ING_API IMaterial : 
			public EventStorage,
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IMaterial		(const String& name, IShader* shader);
			~IMaterial		();



			/**
			 *	Release Methods
			 */
		public:
			virtual void	Release();


			/**
			 *	Properties
			 */
		private:
			String			name;

			IShader*		shader;

			void*			propertyPData;
			IBuffer*		propertyBuffer;

			std::vector<MaterialView>					viewVector;
			std::unordered_map<String, unsigned int>	viewName2ViewIndexMap;
			std::unordered_map<String, std::vector<unsigned int>>	viewType2ViewIndexVectorMap;

			List<IMaterial*>::Node* node;

		protected:
			std::vector<IBuffer*> cbufferVector;

		public:
			String			GetName			() { return name; }

			IShader*		GetShader		() { return shader; }

			void			SetShader		(IShader* shader);

			IBuffer*		GetPropertyBuffer(){ return propertyBuffer; }
			void*			GetPropertyPData() { return propertyPData;}

			List<IMaterial*>::Node* GetNode () { return node; }

			const std::vector<IBuffer*>& GetCBufferVector() { return cbufferVector; }
			void			SetCBufferVector(const std::vector<IBuffer*>& cbufferVector);

			const std::vector<MaterialView>& GetViewVector() { return viewVector; }
			unsigned int				GetViewCount() { return viewVector.size(); }
			unsigned int				GetViewIndex(const String& name) { return viewName2ViewIndexMap[name]; }

			std::vector<MaterialView>	GetViewsByType(const String& type);

			virtual unsigned int		GetMinimumCBufferCount() { return 1; }

		private:
			unsigned int	GetPropertyIndex(const String& name);
			unsigned int	GetPropertyOffset(const String& name);



			/**
			 *	Methods
			 */
		public:
			virtual void Apply					(const String& passName);

			virtual void CreatePropertyBuffer	();
			virtual void ReleasePropertyBuffer	();
			template<typename T>
			void		 SetProperty			(const String& name, const T& value, bool updateBuffer) {

				if (shader == 0) return;

				unsigned int offset = GetPropertyOffset(name);

				char* charPData = (char*)propertyPData;

				*((T*)(charPData + offset)) = value;

				if (updateBuffer) {

					UpdatePropertyBuffer();

				}

			}
			template<typename T>
			void		 SetProperty			(const String& name, const T& value) { SetProperty<T>(name, value, true); }
			virtual void UpdatePropertyBuffer	();

			virtual void UpdateViewVector		();

			virtual void UpdateCBufferVector	();

			IBuffer*	 GetCBuffer(const String& name);
			void		 SetCBuffer(const String& name, IBuffer* cbuffer);

			IView*		 GetView				(const String& name);
			void		 SetView				(const String& name, IView* view);

			virtual void UpdateFilterNameVector	();

			virtual void Update					();

		};

	}

}