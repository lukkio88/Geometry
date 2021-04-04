#ifndef GEO_UTILS_H
#define GEO_UTILS_H
#include <point.hpp>

/**
 * @brief Determinant of 2x2 matrix \f$\begin{pmatrix} a & b \\ c & d \end{pmatrix}\f$
 * @param a 
 * @param b 
 * @param c 
 * @param d 
 * @return 
*/
float determinant(
	float a, float b, 
	float c, float d
);

/**
 * @brief Determinant of a 3x3 matrix \f$\begin{pmatrix} a & b & c \\ d & e & f \\ g & h & i\end{pmatrix}\f$
 * @param a 
 * @param b 
 * @param c 
 * @param d 
 * @param e 
 * @param f 
 * @param g 
 * @param h 
 * @param i 
 * @return 
*/
float determinant(
	float a, float b, float c,
	float d, float e, float f,
	float g, float h, float i
);

#endif