#ifndef __POINT_H__
#define __POINT_H__

#include <boost/functional/hash.hpp>

struct Point
{
	Point(int _x, int _y): x{_x}, y{_y}{}

	bool operator==(const Point& rhs)const{return x == rhs.x && y == rhs.y;}

	int x;
	int y;
};

namespace std
{
    template <>
    struct hash<Point>
    {
        size_t operator()(const Point& pos)const
        {
			size_t seed{0};
			boost::hash_combine(seed, boost::hash_value(pos.x));
			boost::hash_combine(seed, boost::hash_value(pos.y));
			return seed;
        }
    };
}

#endif
