#ifndef POINT_H
#define POINT_H
#include <geo_utils.hpp>
#include <iostream>

/**
 * @brief Class representing a 2D vector \f$\vec{v} = (x,y)\f$ with some basic operators 
*/
struct Vector
{
public:
	/**
	 * @brief Addition of two 2D vectors (i.e. computes \f$\vec{v}_1 + \vec{v}_2 = (x_1 + x_2,y_1 + y_2) \f$) 
	 * @param v rhs
	 * @return Vector sum
	*/
	Vector operator+(const Vector& v) const;

	/**
	 * @brief Difference of two 2D vector (i.e. computes \f$\vec{v}_1 - \vec{v}_2 = (x_1 - x_2,y_1 - y_2) \f$)
	 * @param v rhs
	 * @return Vector Difference
	*/
	Vector operator-(const Vector& v) const;

	/**
	 * @brief Opposite of a 2D vector (i.e. computes \f$-\vec{v} = (-x,-y) \f$)
	 * @return Opposite vector
	*/
	Vector operator-() const;

	/**
	 * @brief Test equality of two 2D vectors (i.e. \f$\vec{v}_1 = \vec{v}_2 \iff (x_1 == x_2 \wedge y_1 == y_2) \f$)
	 * @param v rhs
	 * @return true if lhs == rhs false otherwise
	*/
	bool operator==(const Vector& v) const;

	/**
	 * @brief Test if two 2D vectors are different (i.e. \f$\vec{v}_1 \neq \vec{v}_2 \iff (x_1 \neq x_2 \vee y_1 \neq y_2) \f$)
	 * @param v rhs
	 * @return !(lhs == rhs)
	*/
	bool operator!=(const Vector& v) const;

	/**
	 * @brief Compute normalized vector (i.e. returns \f$ \frac{\vec{v}}{\left\lVert v \right\rVert} \f$
	 * @return normalized vector
	*/
	Vector normalize() const;

	/**
	 * @brief Compute dot product between two vectors (i.e. returns \f$ \vec{v}_1 \cdot \vec{v}_2 = x_1 y_1 + x_2 v_2\f$)
	 * @param v rhs
	 * @return dot product between lhs and rhs
	*/
	float operator*(const Vector& v) const;

	/**
	 * @brief Multiply a vector by a scalar value (i.e. $c \vec{v} = (cx,cy)\f$
	 * @param scalar Scalar value
	 * @param v Vector
	 * @return Input vector multiplied by a given scalar value
	*/
	friend Vector operator*(float scalar, const Vector& v);

	/**
	 * @brief Returns zero vector (i.e. returns \f$ \vec{v} = (0,0) \f$) 
	 * @return Zero vector
	*/
	static Vector Zero() { return Vector{ 0.0f, 0.0f }; }

	/**
	 * @brief Printing a vector in the format (x,y)
	 * @param os Output stream
	 * @param v Vector to be printed
	 * @return Output stream reference
	*/
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
public:
	float x; //!< x coordinate of the vector
	float y; //!< y coordinate of the vector
};

/**
 * @brief Defining a point as a 2D vector
*/
using Point = Vector;

/**
 * @brief Rotate a vector by 90 degrees (i.e. if \f$ \vec{v} = (x,y)\f$ then return \f$ \vec{v'} = (-y,x) \f$)
 * @param v Input vector
 * @return Rotated by 90 degrees input vector
*/
Vector rotate90cw(const Vector& v);

/**
 * @brief Distance between two points (i.e. returns \f$ d(a,b) = \left\lVert a - b \right\rVert = \sqrt{ (a_x - b_x)^2 + (a_y - b_y)^2}\f$
 * @param a First point
 * @param b Second point
 * @return distance
*/
float distance(const Vector& a, const Vector& b);

/**
 * @brief Compute area of the triangle spanned by three points \f$a, b, c\f$ using the determinant
 * @param a First triangle vertex
 * @param b Second triangle vertex
 * @param c Third triangle vertex
 * @return triangle area
*/
float triangleArea(const Vector& a, const Vector& b, const Vector& c);

#endif