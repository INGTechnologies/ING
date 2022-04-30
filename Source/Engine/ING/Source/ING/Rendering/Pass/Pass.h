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



namespace ING {

	class Camera;



	namespace Rendering {

		class IDeviceContext;



		/**
		 *	Interface Class
		 */
		class ING_API IPass
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IPass(const String& name);
			~IPass();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			String			name;

		public:
			String			GetName() { return name; }



			/**
			 *	Methods
			 */
		public:
			virtual bool Render(IDeviceContext* context, Camera* camera, void* input, void* output);

		};



		/**
		 *	Main Class
		 */
		template<typename TInput, typename TOutput>
		class Pass : public IPass
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Pass	(const String& name);
			~Pass	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Methods
			 */
		public:
			virtual bool Render			(IDeviceContext* context, Camera* camera, void* input, void* output) override;

			virtual bool CustomRender	(IDeviceContext* context, Camera* camera, const TInput& input, TOutput& output);

		};

	}

}



/**
 *	Define Main Class Members
 */
namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		template<typename TInput, typename TOutput>
		Pass<TInput,TOutput>::Pass	(const String& name) : IPass(name) {



		}

		template<typename TInput, typename TOutput>
		Pass<TInput, TOutput>::~Pass	() {



		}



		/**
		 *	Constructors And Destructor
		 */
		template<typename TInput, typename TOutput>
		void	Pass<TInput, TOutput>::Release() {

			IPass::Release();

		}



		/**
		 *	Methods
		 */
		template<typename TInput, typename TOutput>
		bool	Pass<TInput, TOutput>::Render(IDeviceContext* context, Camera* camera, void* input, void* output) {

			return CustomRender(context, camera, *((TInput*)input), *((TOutput*)output));

		}

		template<typename TInput, typename TOutput>
		bool	Pass<TInput, TOutput>::CustomRender(IDeviceContext* context, Camera* camera, const TInput& input, TOutput& output) {



			return true;
		}

	}

}