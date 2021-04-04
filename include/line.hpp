#ifndef LINE_H
#define LINE_H
#include <point.hpp>

struct Line
{
public:
	bool contains(const Point& p) const;
	Point getIntersection(const Line& l) const;
public:
	Point origin;
	Vector direction;
};

bool doIntersect(const Line& l, const Line& s);

struct Segment
{
public:
	Point getDirection() const;
	bool contains(const Point& point) const;
	void split(Segment& s1, Segment& s2, const Point& p) const;
	bool getX(float y, float& x) const;
	friend std::ostream& operator<<(std::ostream& os, const Segment& s);
public:
	Point origin;
	Point destination;
};

#endif