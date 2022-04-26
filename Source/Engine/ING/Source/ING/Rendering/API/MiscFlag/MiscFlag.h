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
		enum MiscFlag {
			MISC_GENERATE_MIPS = 0x1L,
			MISC_SHARED = 0x2L,
			MISC_TEXTURECUBE = 0x4L,
			MISC_DRAWINDIRECT_ARGS = 0x10L,
			MISC_BUFFER_ALLOW_RAW_VIEWS = 0x20L,
			MISC_BUFFER_STRUCTURED = 0x40L,
			MISC_RESOURCE_CLAMP = 0x80L,
			MISC_SHARED_KEYEDMUTEX = 0x100L,
			MISC_GDI_COMPATIBLE = 0x200L,
			MISC_SHARED_NTHANDLE = 0x800L,
			MISC_RESTRICTED_CONTENT = 0x1000L,
			MISC_RESTRICT_SHARED_RESOURCE = 0x2000L,
			MISC_RESTRICT_SHARED_RESOURCE_DRIVER = 0x4000L,
			MISC_GUARDED = 0x8000L,
			MISC_TILE_POOL = 0x20000L,
			MISC_TILED = 0x40000L,
			MISC_HW_PROTECTED = 0x80000L,
			MISC_SHARED_DISPLAYABLE,
			MISC_SHARED_EXCLUSIVE_WRITER
		};



		/**
		 *	Operators
		 */
		static inline MiscFlag operator|(MiscFlag a, MiscFlag b) {

			return (MiscFlag)((unsigned int)a | (unsigned int)b);

		}
		static inline MiscFlag operator&(MiscFlag a, MiscFlag b) {

			return (MiscFlag)((unsigned int)a & (unsigned int)b);

		}

	}

}