
/**
 *	Include Header
 */
#include "Matrices.h"



namespace ING {

	ING_BEGIN_REFLECTED_STRUCT
		(TransformM, S_Object)

		ING_STRUCT_PROPERTY
			(TransformM, translationMatrix);

		ING_STRUCT_PROPERTY
			(TransformM, scaleMatrix);

		ING_STRUCT_PROPERTY
			(TransformM, rotationMatrix);

		ING_STRUCT_PROPERTY
			(TransformM, localMatrix);

		ING_STRUCT_PROPERTY
			(TransformM, worldMatrix);

	ING_END_REFLECTED_STRUCT
		()



	/**
	 *	Constructors And Destructor
	 */
	TransformM::TransformM() {



	}

	TransformM::~TransformM() {



	}

}