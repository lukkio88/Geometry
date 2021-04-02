#ifndef POINT_H
#define POINT_H
#include <geo_utils.hpp>

class Vector
{
public:
	Vector(float x, float y);
	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float y);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector operator-() const;
	Vector normalize() const;
	float operator*(const Vector& v) const;
	friend Vector operator*(float scalar, const Vector& v);
	static Point Zero() { return Point(0.0f, 0.0f); }
private:
	float x;
	float y;
};

using Point = Vector;

Vector rotate90cw(const Vector& v);
float distance(const Vector& a, const Vector& b);
float triangleArea(const Vector& a, const Vector& b, const Vector& c);

#endif