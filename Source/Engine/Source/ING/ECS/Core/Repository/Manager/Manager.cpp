
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include ECS
 */
#include <ING/ECS/ECS.h>



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		RepositoryManager::RepositoryManager() {

			Debug::Log("Start Creating RepositoryManager");

			Debug::Log("RepositoryManager Created");

		}

		RepositoryManager::~RepositoryManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool RepositoryManager::Init() {

			Debug::Log("Start Initializing RepositoryManager");

			Debug::Log("RepositoryManager Initialized");

			return true;
		}

		bool RepositoryManager::Run() {

			Debug::Log("Start Running RepositoryManager");

			return true;
		}

		bool RepositoryManager::Release() {

			Debug::Log("Start Releasing RepositoryManager");

			for (auto item = repositoryList.begin(); item != repositoryList.end();) {
				
				List<Repository*>::Iterable nextItem = item.node->next;

				Repository* repository = *((Repository**)(item.node->pValue));

				repository->Release();

				item = nextItem;
			}

			repositoryList.Clear();

			Debug::Log("Finished Releasing RepositoryManager");

			return Square::Release();
		}



		/**
		 *	Methods
		 */
		List<Repository*>::Node*	RepositoryManager::AddRepository		(Repository* repository) {

			return repositoryList.Add(repository);

		}

		void						RepositoryManager::RemoveRepository	(List<Repository*>::Node* node) {

			repositoryList.Remove(node);

		}



		/**
		 *	Event Methods
		 */
		void						RepositoryManager::PreUpdate() {

			for (Repository* repository : repositoryList) {

				if (!repository->IsActive()) continue;

				repository->PreUpdate();

			}

		}

		void						RepositoryManager::Update() {

			for (Repository* repository : repositoryList) {

				if (!repository->IsActive()) continue;

				repository->Update();

			}

		}

		void						RepositoryManager::LateUpdate() {

			for (Repository* repository : repositoryList) {

				if (!repository->IsActive()) continue;

				repository->LateUpdate();

			}

		}

		void						RepositoryManager::PreRender() {

			for (Repository* repository : repositoryList) {

				if (!repository->IsActive()) continue;

				repository->PreRender();

			}

		}

		void						RepositoryManager::Render() {

			for (Repository* repository : repositoryList) {

				if (!repository->IsActive()) continue;

				repository->Render();

			}

		}

		void						RepositoryManager::LateRender() {

			for (Repository* repository : repositoryList) {

				if (!repository->IsActive()) continue;

				repository->LateRender();

			}

		}

	}

}