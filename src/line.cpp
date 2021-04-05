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
	Point directionLhs = direction;
	Point directionRhs = l.direction;
	Point deltaOrigin = l.origin - origin;
	
	//Applying Cramer rule
	float alphaLhs =
		determinant(
			deltaOrigin.x, -directionRhs.x,
			deltaOrigin.y, -directionRhs.y) /
		determinant(
			directionLhs.x, -directionRhs.x,
			directionLhs.y, -directionRhs.y
		);

	return origin + alphaLhs * direction;
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

bool Segment::contains(const Point& point) const
{
	Vector segmentDirection = getDirection();
	float segmentLength = distance(origin, destination);
	Vector orthogonalComplement = rotate90cw(segmentDirection);
	Vector directionVector = point - origin;
	float alpha = directionVector * segmentDirection;

	return (directionVector * orthogonalComplement == 0.0f) && (0.0f <= alpha && alpha <= segmentLength);

}

void Segment::split(Segment& s1, Segment& s2, const Point& p) const
{
	s1.origin = origin;
	s1.destination = p;
	s2.origin = p;
	s2.destination = destination;
}

bool Segment::getX(float y, float& x) const
{
	/*
	from the line equation
	x = ox + alpha*dx
	y = oy + alpha*dy

	x = ox + ((y - oy)/dy)*dx;
	*/
	Vector delta = destination - origin;
	x = origin.x + ((y - origin.y) / delta.y)*delta.x;
	return contains(Point{ x,y });
}

bool Segment::intersect(const Segment& s, Point& p) const
{
	Line lineSpannedLhs{ origin,destination - origin };
	Line lineSpannedRhs{ s.origin, s.destination - s.origin };

	bool parallel = (lineSpannedLhs.origin != lineSpannedRhs.origin) &&
		(fabs(determinant(
			lineSpannedLhs.origin.x, lineSpannedRhs.origin.x,
			lineSpannedLhs.origin.y, lineSpannedRhs.origin.y
		)) < 0.00001f);

	if (!parallel)
	{
		p = lineSpannedLhs.getIntersection(lineSpannedRhs);
		return contains(p) && s.contains(p);
	}
	else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const Segment& s)
{
	os << s.origin << " " << s.destination;
	return os;
}