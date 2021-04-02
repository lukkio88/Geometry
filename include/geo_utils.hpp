#ifndef GEO_UTILS_H
#define GEO_UTILS_H
#include <point.hpp>

/*
Input represents matrices in row major order
*/
float determinant(
	float a, float b, 
	float c, float d
);

float determinant(
	float a, float b, float c,
	float d, float e, float f,
	float g, float h, float i
);

#endif