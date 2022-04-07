
/**
 *	Include ECS
 */
//#include <ING/ECS/ECS.h>



/**
 *	Include Repository Manager
 */
//#include "Manager/Manager.h"


/*
namespace ING {

	namespace ECS {

		void RepositoryConstructor(Repository* repository) {

			repository->node = 0;

			repository->isActive = true;

			repository->node = RepositoryManager::GetInstance()->AddRepository(repository);

		}

		void RepositoryDestructor(Repository* repository) {



		}

		void RepositoryRelease(Repository* repository) {

			unsigned int componentSystemCount = repository->componentSystemVector.size();

			for (unsigned int i = 0; i < componentSystemCount; ++i) {

				repository->componentSystemVector[i]->Release();

			}

			repository->componentSystemTypeId2ComponentSystemMap.clear();
			repository->componentTypeId2ComponentSystemMap.clear();

			RepositoryManager::GetInstance()->RemoveRepository(repository->node);

			delete repository;

		}

	}

}
*/