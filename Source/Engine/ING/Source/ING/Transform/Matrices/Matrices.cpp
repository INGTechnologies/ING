
/**
 *	Include Header
 */
#include "Matrices.h"



namespace ING {

	ING_BEGIN_REFLECTED_STRUCT
		(S_TransformM, S_Object)

		ING_STRUCT_PROPERTY
			(S_TransformM, translationMatrix);

		ING_STRUCT_PROPERTY
			(S_TransformM, scaleMatrix);

		ING_STRUCT_PROPERTY
			(S_TransformM, rotationMatrix);

		ING_STRUCT_PROPERTY
			(S_TransformM, localMatrix);

		ING_STRUCT_PROPERTY
			(S_TransformM, worldMatrix);

	ING_END_REFLECTED_STRUCT
		()



	/**
	 *	Constructors And Destructor
	 */
	S_TransformM::S_TransformM() {



	}

	S_TransformM::~S_TransformM() {



	}

}