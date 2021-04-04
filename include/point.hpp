#ifndef POINT_H
#define POINT_H
#include <geo_utils.hpp>
#include <iostream>

struct Vector
{
public:
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector operator-() const;
	bool operator==(const Vector& v) const;
	bool operator!=(const Vector& v) const;
	Vector normalize() const;
	float operator*(const Vector& v) const;
	friend Vector operator*(float scalar, const Vector& v);
	static Vector Zero() { return Vector{ 0.0f, 0.0f }; }
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
public:
	float x;
	float y;
};

using Point = Vector;

Vector rotate90cw(const Vector& v);
float distance(const Vector& a, const Vector& b);
float triangleArea(const Vector& a, const Vector& b, const Vector& c);

#endif