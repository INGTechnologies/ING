
/**
 *	Include Header
 */
#include "Separate.h"



namespace ING {

	ING_BEGIN_REFLECTED_STRUCT
		(S_TransformS, S_Object)

		ING_STRUCT_PROPERTY
			(S_TransformS, localPosition);

		ING_STRUCT_PROPERTY
			(S_TransformS, localScale);

	ING_END_REFLECTED_STRUCT
		()



	/**
	 *	Constructors And Destructor
	 */
	S_TransformS::S_TransformS() {



	}

	S_TransformS::~S_TransformS() {



	}

}