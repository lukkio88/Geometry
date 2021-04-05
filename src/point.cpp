#include <point.hpp>
#include <cmath>

Vector Vector::operator+(const Vector& v) const
{
	return Vector{x + v.x,y + v.y};
}
Vector Vector::operator-(const Vector& v) const
{
	return (*this) + (-v);
}

Vector Vector::operator-() const
{
	return Vector{-x,-y};
}

bool Vector::operator==(const Vector& v) const
{
	return (x == v.x) && (y == v.y);
}

bool Vector::operator!=(const Vector& v) const
{
	return !(*this == v);
}

Vector Vector::normalize() const
{
	float invNorm = 1.0f/distance(*this, Zero());
	return invNorm * (*this);
}

float Vector::operator*(const Vector& v) const
{
	return x*v.x + y*v.y;
}

Vector operator*(float scalar, const Vector& v)
{
	return Vector{scalar*v.x,scalar*v.y};
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "(" << v.x << " ," << v.y << " )";
	return os;
}

float distance(const Point& a, const Point& b)
{
	Vector difference = b - a;
	return sqrt(difference*difference);
}

Vector rotate90cw(const Vector& v)
{
	return Vector{ -v.y, v.x };
}

float triangleArea(const Point& a, const Point& b, const Point& c)
{
	Point a2b = b - a;
	Point a2c = c - a;
	return 0.5f * determinant(
		a2b.x, a2c.x,
		a2b.y, a2c.y
	);
}