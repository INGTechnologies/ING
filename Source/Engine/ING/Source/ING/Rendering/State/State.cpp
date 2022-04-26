
/**
 *	Include Header
 */
#include "State.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include API
 */
#include <ING/Rendering/API/API.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IState::IState(IDevice* device, const std::string& name) :
			device(0)
		{

			this->name = name;

			this->device = device;

		}

		IState::IState(const std::string& name) : IState(IAPI::GetInstance()->GetDevice(), name)
		{}

		IState::~IState() {



		}



		/**
		 *	Release Methods
		 */
		void IState::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void IState::Apply() {



		}

	}

}