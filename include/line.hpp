#ifndef LINE_H
#define LINE_H
#include <point.hpp>

class Line
{
public:
	Line(const Point& origin, const Vector& direction);
	Point getOrigin() const;
	Point getDirection() const;
	void setOrigin(const Point& origin);
	void setDirection(const Vector& direction);
	bool contains(const Point& p) const;
	Point getIntersection(const Line& l) const;
private:
	Point mOrigin;
	Vector mDirection;
};

bool doIntersect(const Line& l, const Line& s);

class Segment
{
public:
	Segment(const Point& origin,const Point& destination);
	Point getOrigin() const;
	Point getDestination() const;
	Point getDirection() const;
	void setOrigin(const Point& origin);
	void setDestination(const Point& destination);
	bool contains(const Point& point);
	void split(Segment& s1, Segment& s2, const Point& p);
private:
	Point mOrigin;
	Point mDestination;
};

#endif