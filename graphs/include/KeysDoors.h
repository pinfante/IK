#ifndef __KEYS_DOORS_H__
#define __KEYS_DOORS_H__

#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "Point.h"

using std::vector;
using std::string;
using std::pair;
using std::queue;
using std::unordered_map;
using std::unordered_set;
/*
'#' = Water.
'.' = Land.
'a' = Key of type 'a'. All lowercase letters are keys.
'A' = Door that opens with key 'a'. All uppercase letters are doors.
'@' = Starting cell.
'+' = Ending cell (goal).
*/

class KeysDoors
{
	public:

		KeysDoors(const vector<string>& grid) : m_grid{grid}, m_start{findStartPoint()}{}

		vector<Point> dfs();

	private:

		void dfs(const Point& pos);

		vector<Point> getNeighbors(const Point& pos) const;

		Point findStartPoint() const;

		bool isEndFound(const Point& pos) const;

		bool isWater(const Point& pos) const;

		bool notShortestPath()const;

		bool isDoor(const Point& pos) const;

		bool canOpenDoor(const Point& pos);

		void removeDoor(const Point& pos);

		pair<bool,char> isKey(const Point& pos) const;

		void addKey(const Point& pos, char key);

		void removeKey(const Point& pos, char key);

		void setPath(const Point& pos);

		void revertPath(const Point& pos);

		vector<string>					m_grid;
		Point							m_start;
		unordered_map<Point, char>  	m_point2Key;
		unordered_map<char, size_t>  	m_keyCount;
		unordered_map<Point, Point> 	m_path;
		vector<Point>					m_shortestPath;
		
};


#endif
