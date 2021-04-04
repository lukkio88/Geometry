#ifndef LINE_H
#define LINE_H
#include <point.hpp>

/**
 * @brief Representing a line \f$ l = (O,\vec{d})\f$ where \f$O\f$ is a 2D point and \f$\vec{d}\f$ is a 2D direction vector. Note the direction isn't necessarily normalized
*/
struct Line
{
public:
	/**
	 * @brief Check if a given line contains a point \f$p\f$. Test is performed by the area spanned by two points of the line and point to be tested
	 * @param p 2D point
	 * @return true if the p belongs to the line false otherwise.
	*/
	bool contains(const Point& p) const;

	/**
	 * @brief Intersection between two lines.
	 * @param l rhs
	 * @return intersection point between lhs and rhs
	*/
	Point getIntersection(const Line& l) const;
public:
	Point origin; //!< origin of the line
	Vector direction; //!< direction (not normalized) of the line
};

/**
 * @brief Test if two lines intersect. Rank-2 condition is used for the test
 * @param l lhs
 * @param s rhs
 * @return true if lhs intersect rhs, false otherwise
*/
bool doIntersect(const Line& l, const Line& s);

/**
 * @brief Representing a segment. The segment is represented as a pair of point origin, destination
*/
struct Segment
{
public:
	/**
	 * @brief Construct direction of the vector as the difference of its end points.
	 * @return Direction vector
	*/
	Vector getDirection() const;

	/**
	 * @brief Test if a point belongs to the segment. Test is done by using a combination of rejection and projection
	 * @param point Point to be tested
	 * @return True if the point belongs to the segment, false otherwise
	*/
	bool contains(const Point& point) const;

	/**
	 * @brief Split a segment into two given a point. (i.e. given \f$S = (P_1,P_2)\f$ and \f$P\f$ returns \f$S_1 = (P_1,P)\f$ and \f$S_2 = (P,P_2)\f$ 
	 * @param s1 First half of the segment
	 * @param s2 Second half of the segment
	 * @param p 
	*/
	void split(Segment& s1, Segment& s2, const Point& p) const;

	/**
	 * @brief Assuming non horizontal segment it returns \f$x\f$ coordinate given the \f$y\f$
	 * @param y Given coordinate
	 * @param x Unknwong coordinate
	 * @return true if valid false otherwise
	*/
	bool getX(float y, float& x) const;

	/**
	 * @brief Printing function
	 * @param os Output stream reference
	 * @param s Segment
	 * @return Outpu stream reference
	*/
	friend std::ostream& operator<<(std::ostream& os, const Segment& s);
public:
	Point origin; //!< Origin of the segment
	Point destination; //!< Destination point of the segment
};

#endif