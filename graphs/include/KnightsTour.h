#ifndef __KNIGHTS_TOUR_H__
#define __KNIGHTS_TOUR_H__

#include "graph.h"
#include <utility>
#include <map>
#include <queue>
#include <unordered_map>
#include "Point.h"

using std::queue;
using std::map;
using std::pair;
using std::unordered_map;

class KnightsTour
{
	public:

		KnightsTour(int rows, int cols, int start_row, int start_col, int end_row, int end_col);

		int findMinimumMoves();

	private:

		int findMinimumMoves(Point& parent);

		void getNeighbors(Point& currPos);

		int numMoves(Point& neighbor);

		void addNeigbor(const Point& parent, const Point& pos);

		unordered_map<Point, Point> m_parents;

		queue<Point> 										 m_neighbors;
		Point 												 m_end; 	
		Point 												 m_startPt; 	
	    Point 												 m_endPt; 
};

#endif
