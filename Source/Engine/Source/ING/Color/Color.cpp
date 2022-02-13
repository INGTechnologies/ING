
/**
 *	Include Header
 */
#include "Color.h"



static float Min(float a, float b) {
	return a <= b ? a : b;
}

static float Max(float a, float b) {
	return a >= b ? a : b;
}




namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Color::Color() : Color(1,1,1,1) 
	{



	}

	Color::Color(float x, float y, float z, float w) : Vector4(x,y,z,w)
	{



	}

	Color::~Color() 
	{



	}



	/**
	 *	Methods
	 */
	Color Color::RGBToHSL(Color rgb) {
		Color hsl;

		float r = rgb.x;
		float g = rgb.y;
		float b = rgb.z;

		float min = Min(Min(r, g), b);
		float max = Max(Max(r, g), b);
		float delta = max - min;

		hsl.z = (max + min) / 2;

		if (delta == 0)
		{
			hsl.x = 0;
			hsl.y = 0.0f;
		}
		else
		{
			hsl.y = (hsl.z <= 0.5) ? (delta / (max + min)) : (delta / (2 - max - min));

			float hue;

			if (r == max)
			{
				hue = ((g - b) / 6) / delta;
			}
			else if (g == max)
			{
				hue = (1.0f / 3) + ((b - r) / 6) / delta;
			}
			else
			{
				hue = (2.0f / 3) + ((r - g) / 6) / delta;
			}

			if (hue < 0)
				hue += 1;
			if (hue > 1)
				hue -= 1;

			hsl.x = hue;
		}

		hsl.w = rgb.w;

		return hsl;

	}

}