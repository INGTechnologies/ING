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
		enum BindFlag {
			BIND_VERTEX_BUFFER = 0x1L,
			BIND_INDEX_BUFFER = 0x2L,
			BIND_CONSTANT_BUFFER = 0x4L,
			BIND_SHADER_RESOURCE = 0x8L,
			BIND_STREAM_OUTPUT = 0x10L,
			BIND_RENDER_TARGET = 0x20L,
			BIND_DEPTH_STENCIL = 0x40L,
			BIND_UNORDERED_ACCESS = 0x80L,
			BIND_DECODER = 0x200L,
			BIND_VIDEO_ENCODER = 0x400L
		};



		/**
		 *	Operators
		 */
		static inline BindFlag operator|(BindFlag a, BindFlag b) {

			return (BindFlag)((unsigned int)a | (unsigned int)b);

		}
		static inline BindFlag operator&(BindFlag a, BindFlag b) {

			return (BindFlag)((unsigned int)a & (unsigned int)b);

		}

	}

}