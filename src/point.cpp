#include <point.hpp>
#include <cmath>

Vector::Vector(float x, float y) :x(x), y(y) { ; }


float Vector::getX() const
{
	return x;
}

float Vector::getY() const
{
	return y;
}

void Vector::setX(float x)
{
	this->x = x;
}

void Vector::setY(float y)
{
	this->y = y;
}


Vector Vector::operator+(const Vector& v) const
{
	return Vector{getX() + v.getX(),getY() + v.getY()};
}
Vector Vector::operator-(const Vector& v) const
{
	return (*this) + (-v);
}

Vector Vector::operator-() const
{
	return Vector{-getX(),-getY()};
}

Vector Vector::normalize() const
{
	float invNorm = 1.0f/distance(*this, Zero());
	return invNorm * (*this);
}

float Vector::operator*(const Vector& v) const
{
	return getX()*v.getX() + getY()*v.getY();
}

Vector operator*(float scalar, const Vector& v)
{
	return Vector{scalar*v.getX(),scalar*v.getY()};
}

float distance(const Point& a, const Point& b)
{
	Vector difference = b - a;
	return sqrt(difference*difference);
}

Vector rotate90cw(const Vector& v)
{
	return Vector(-v.getY(), v.getX());
}

float triangleArea(const Point& a, const Point& b, const Point& c)
{
	Point a2b = b - a;
	Point a2c = c - a;
	return 0.5f * determinant(
		a2b.getX(), a2c.getX(),
		a2b.getY(), a2c.getY()
	);
}