#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Define BindFlags
		 */
		enum CPUAccessFlag {
			CPU_ACCESS_WRITE = 0x10000L,
			CPU_ACCESS_READ = 0x20000L
		};



		/**
		 *	Operators
		 */
		static inline CPUAccessFlag operator|(CPUAccessFlag a, CPUAccessFlag b) {

			return (CPUAccessFlag)((unsigned int)a | (unsigned int)b);

		}
		static inline CPUAccessFlag operator&(CPUAccessFlag a, CPUAccessFlag b) {

			return (CPUAccessFlag)((unsigned int)a & (unsigned int)b);

		}

	}

}