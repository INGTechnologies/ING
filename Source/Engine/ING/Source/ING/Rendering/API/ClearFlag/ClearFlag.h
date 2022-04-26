#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Define ClearFlags
		 */
		enum ClearFlag {

			CLEAR_DEPTH,
			CLEAR_STENCIL

		};



		/**
		 *	Operators
		 */
		static inline ClearFlag operator|(ClearFlag a, ClearFlag b) {

			return (ClearFlag)((unsigned int)a + (unsigned int)b);

		}

		static inline ClearFlag operator&(ClearFlag a, ClearFlag b) {

			return (ClearFlag)((unsigned int)a & (unsigned int)b);

		}

	}

}