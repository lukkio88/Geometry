#include <line.hpp> 
#include <cmath>

Line::Line(const Point& origin, const Vector& direction) { 
	setOrigin(origin);
	setDirection(direction);
}

Point Line::getOrigin() const
{
	return mOrigin;
}

Point Line::getDirection() const
{
	return mDirection;
}

void Line::setOrigin(const Point& origin)
{
	mOrigin = origin;
}

void Line::setDirection(const Vector& direction)
{
	mDirection = direction;
}

bool Line::contains(const Point& p) const
{
	Point destination = getOrigin() + getDirection();
	return triangleArea(getOrigin(), destination, p) != 0.0;
}

Point Line::getIntersection(const Line& l) const
{
	//this assumes the lines intersect in single point
	Point direction1 = getDirection();
	Point direction2 = l.getDirection();
	Point deltaOrigin = l.getOrigin() - getOrigin();
	Point rejection = direction1 - (direction1 * direction2) * direction2;
	return ((rejection * deltaOrigin) / (rejection * direction1))*direction1;
}

bool doIntersect(const Line& line1, const Line& line2)
{
	Point direction1 = line1.getDirection();
	Point direction2 = line2.getDirection();
	Point zero{ 0.0f,0.0f };

	float area = triangleArea(zero, direction1, direction2);
	if (area == 0.0f)
	{
		Point deltaLinesOrigin = line1.getOrigin() - line2.getOrigin();
		area = triangleArea(zero, direction1, deltaLinesOrigin);
		if (area == 0.0f)
		{
			return true; //lines are the same
		}
		else
		{
			return false; //lines are parallel but no points in common
		}
	}
	else
	{
		return true; //single intersection point
	}	
}

//Segments

Segment::Segment(const Point& origin, const Point& destination)
{
	setOrigin(origin);
	setDestination(destination);
}

Point Segment::getOrigin() const
{
	return mOrigin;
}

Point Segment::getDestination() const
{
	return mDestination;
}

Point Segment::getDirection() const
{
	return (getDestination() - getOrigin()).normalize();
}

void Segment::setOrigin(const Point& origin)
{
	mOrigin = origin;
}

void Segment::setDestination(const Point& destination)
{
	mDestination = destination;
}

bool Segment::contains(const Point& point)
{
	Vector segmentDirection = getDirection();
	float segmentLength = distance(getOrigin(), getDestination());
	Vector orthogonalComplement = rotate90cw(segmentDirection);
	Vector directionVector = point - getOrigin();
	float alpha = directionVector * segmentDirection;

	return (directionVector * orthogonalComplement == 0.0f) && (0.0f <= alpha && alpha <= segmentLength);

}

void Segment::split(Segment& s1, Segment& s2, const Point& p)
{
	s1.setOrigin(getOrigin());
	s1.setDestination(p);
	s2.setOrigin(p);
	s2.setDestination(getDestination());
}