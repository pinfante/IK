#include "KnightsTour.h"
#include <iostream>

using std::cout;

KnightsTour::KnightsTour(int rows, int cols, int start_row, int start_col, int end_row, int end_col)
:
m_end{rows, cols},
m_startPt{start_row, start_col},
m_endPt{end_row, end_col}{}

int KnightsTour::findMinimumMoves()
{
	if(m_startPt == m_endPt)
		return 0;

	getNeighbors(m_startPt);

	while(!m_neighbors.empty())
	{
		auto neighbor{m_neighbors.front()};

		if(neighbor == m_endPt)
			return numMoves(neighbor);

		getNeighbors(neighbor);
		
		m_neighbors.pop();
	}
	return -1;
}

int KnightsTour::numMoves(Point& neighbor)
{
	int moves{0};

	auto it = m_parents.find(neighbor);
	while(it != m_parents.end())
	{
		++moves;
		if(it->second == m_startPt)
			break;

		it = m_parents.find(it->second);
	}
	return moves;
}

void KnightsTour::addNeigbor(const Point& parent, const Point& pos)
{
	if(pos == m_startPt)return;

	if(m_parents.find(pos) == m_parents.end())
	{
		m_neighbors.push(pos);
		m_parents.insert(make_pair(pos, parent));
	}
}

void KnightsTour::getNeighbors(Point& neighbor)
{
	auto& [start_row, start_col] = neighbor;
	auto& [rows, cols] = m_end;

	if(start_row + 2 < rows)
	{
		if(start_col + 1 < cols)
			addNeigbor(neighbor, Point{start_row + 2, start_col + 1});
		if(start_col - 1 >= 0 )
			addNeigbor(neighbor, Point{start_row + 2, start_col - 1});
	}
	if(start_row - 2 >= 0)
	{
		if(start_col + 1 < cols)
			addNeigbor(neighbor, Point{start_row - 2, start_col + 1});
		if(start_col - 1 >= 0)
			addNeigbor(neighbor, Point{start_row - 2, start_col - 1});
	}
	if(start_row + 1 < rows)
	{
		if(start_col + 2 < cols)
			addNeigbor(neighbor, Point{start_row + 1, start_col + 2});
		if(start_col - 2 >= 0)
			addNeigbor(neighbor, Point{start_row + 1, start_col - 2});
	}
	if(start_row - 1 >= 0)
	{
		if(start_col + 2 < cols)
			addNeigbor(neighbor, Point{start_row - 1, start_col + 2});
		if(start_col - 2 >= 0)
			addNeigbor(neighbor, Point{start_row - 1, start_col - 2});
	}
}
