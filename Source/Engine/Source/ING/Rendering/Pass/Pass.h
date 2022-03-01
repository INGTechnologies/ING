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
			IPass(std::string name);
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
			std::string			name;

		public:
			std::string			GetName() { return name; }



			/**
			 *	Methods
			 */
		public:
			virtual void Render(IDeviceContext* context, Camera* camera, void* input, void* output);

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
			Pass	(std::string name);
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
			virtual void Render			(IDeviceContext* context, Camera* camera, void* input, void* output) override;

			virtual void CustomRender	(IDeviceContext* context, Camera* camera, TInput* input, TOutput* output);

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
		Pass<TInput,TOutput>::Pass	(std::string name) : IPass(name) {



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
		void	Pass<TInput, TOutput>::Render(IDeviceContext* context, Camera* camera, void* input, void* output) {

			CustomRender(context, camera, (TInput*)input, (TOutput*)output);

		}

		template<typename TInput, typename TOutput>
		void	Pass<TInput, TOutput>::CustomRender(IDeviceContext* context, Camera* camera, TInput* input, TOutput* output) {



		}

	}

}