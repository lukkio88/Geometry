#include <line.hpp> 
#include <cmath>

bool Line::contains(const Point& p) const
{
	Point destination = origin + direction;
	return triangleArea(origin, destination, p) != 0.0;
}

Point Line::getIntersection(const Line& l) const
{
	//this assumes the lines intersect in single point
	Point direction1 = direction;
	Point direction2 = l.direction;
	Point deltaOrigin = l.origin - origin;
	Point rejection = direction1 - (direction1 * direction2) * direction2;
	return ((rejection * deltaOrigin) / (rejection * direction1))*direction1;
}

bool doIntersect(const Line& line1, const Line& line2)
{
	Point direction1 = line1.direction;
	Point direction2 = line2.direction;
	Point zero{ 0.0f,0.0f };

	float area = triangleArea(zero, direction1, direction2);
	if (area == 0.0f)
	{
		Point deltaLinesOrigin = line1.origin - line2.origin;
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
Point Segment::getDirection() const
{
	return (destination - origin).normalize();
}

bool Segment::contains(const Point& point)
{
	Vector segmentDirection = getDirection();
	float segmentLength = distance(origin, destination);
	Vector orthogonalComplement = rotate90cw(segmentDirection);
	Vector directionVector = point - origin;
	float alpha = directionVector * segmentDirection;

	return (directionVector * orthogonalComplement == 0.0f) && (0.0f <= alpha && alpha <= segmentLength);

}

void Segment::split(Segment& s1, Segment& s2, const Point& p)
{
	s1.origin = origin;
	s1.destination = p;
	s2.origin = p;
	s2.destination = destination;
}