#include <geo_utils.hpp>

float determinant(
	float a, float b, 
	float c, float d)
{
	return a * d - c * b;
}

float determinant(
	float a, float b, float c,
	float d, float e, float f,
	float g, float h, float i
)
{
	return a * determinant(e, f, h, i) - d * determinant(b, c, h, i) + g * determinant(b, c, e, f);
}