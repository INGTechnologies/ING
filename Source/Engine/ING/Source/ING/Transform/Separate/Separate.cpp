
/**
 *	Include Header
 */
#include "Separate.h"



namespace ING {

	ING_BEGIN_REFLECTED_STRUCT
		(TransformS, S_Object)

		ING_STRUCT_PROPERTY
			(TransformS, localPosition);

		ING_STRUCT_PROPERTY
			(TransformS, localScale);

	ING_END_REFLECTED_STRUCT
		()



	/**
	 *	Constructors And Destructor
	 */
	TransformS::TransformS() {



	}

	TransformS::~TransformS() {



	}

}