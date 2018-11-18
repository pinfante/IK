#include "KeysDoors.h"
using std::make_pair;

Point KeysDoors::findStartPoint() const
{
	for(int x{0}; x < static_cast<int>(m_grid.size()); ++x)
		for(int y{0}; y < static_cast<int>(m_grid[0].size()); ++y)
			if(m_grid[x][y] == '@')
				return Point{x,y};

	return Point{-1,-1};
}

vector<Point> KeysDoors::dfs()
{
	if(m_start.x == -1 && m_start.y == -1)
		return vector<Point>{};

	auto neighbors{getNeighbors(m_start)};
	for(auto& n : neighbors)
	{
		m_path.insert(make_pair(n, m_start));
		dfs(n);
		revertPath(n);
	}
	
	return m_shortestPath;
}

void KeysDoors::dfs(const Point& pos)
{
	if(isWater(pos) || notShortestPath())
		return;

	if(isEndFound(pos))
	{
		setPath(pos);
		return;		
	}
	const auto& [res, key] = isKey(pos);
	if(res)
		addKey(pos, key);

	else if(isDoor(pos))
	{
		if(!canOpenDoor(pos))
			return;
	}

	auto neighbors{getNeighbors(pos)};
	for(auto& n : neighbors)
	{
		auto it{m_path.find(n)};
		if(it == m_path.end())
		{
			m_path.insert(make_pair(n, pos));
			dfs(n);
			revertPath(n);
		}
	}
}

vector<Point> KeysDoors::getNeighbors(const Point& pos) const
{
	vector<Point> neighbors;

	if(pos.x + 1 < static_cast<int>(m_grid.size()) && m_grid[pos.x + 1][pos.y] != '@' && m_grid[pos.x + 1][pos.y] != '#')
		neighbors.push_back(Point{pos.x + 1, pos.y});

	if(pos.x - 1 >= 0 && m_grid[pos.x - 1][pos.y] != '@' && m_grid[pos.x - 1][pos.y] != '#')
		neighbors.push_back(Point{pos.x - 1, pos.y});

	if(pos.y + 1 < static_cast<int>(m_grid[0].size()) && m_grid[pos.x][pos.y + 1] != '@' && m_grid[pos.x][pos.y + 1] != '#')
		neighbors.push_back(Point{pos.x, pos.y + 1});

	if(pos.y - 1 >= 0 && m_grid[pos.x][pos.y - 1] != '@' && m_grid[pos.x][pos.y - 1] != '#')
		neighbors.push_back(Point{pos.x, pos.y - 1});

	return neighbors;
}

pair<bool,char> KeysDoors::isKey(const Point& pos) const
{
	char key{m_grid[pos.x][pos.y]};

	if(key >= 'a' && key <= 'z')
		return make_pair(true, key);

	return make_pair(false, '#');
}

bool KeysDoors::isWater(const Point& pos) const
{
	return m_grid[pos.x][pos.y] == '#';
}

bool KeysDoors::notShortestPath()const
{
	return !m_shortestPath.empty() && m_path.size() >= m_shortestPath.size();
}

bool KeysDoors::isDoor(const Point& pos) const
{
	char key{m_grid[pos.x][pos.y]};
	return key >= 'A' && key <= 'Z';
}

bool KeysDoors::isEndFound(const Point& pos) const
{
	return m_grid[pos.x][pos.y] == '+';
}

void KeysDoors::setPath(const Point& pos)
{
	vector<Point> path{pos};
	
	auto it{m_path.find(pos)};

	while(it != m_path.end())
	{
		auto& pos{it->second};
		path.push_back(pos);
		if(pos == m_start)
		{
			m_shortestPath = vector<Point>(path.rbegin(), path.rend());
			return;
		}

		it = m_path.find(pos);
	}
}		

void KeysDoors::revertPath(const Point& pos)
{
	const auto& [res, key] = isKey(pos);
	if(res)
		removeKey(pos, key);

	else if(isDoor(pos))
		removeDoor(pos);

	m_path.erase(pos);
}

void KeysDoors::addKey(const Point& pos, char key)
{
	m_point2Key.insert(make_pair(pos, key));

	auto kit{m_keyCount.find(key)};
	if(kit == m_keyCount.end())
		m_keyCount.insert(make_pair(key, 1));
	else
		kit->second++;
}

void KeysDoors::removeKey(const Point& pos, char key)
{
	m_point2Key.erase(pos);

	auto keyIt{m_keyCount.find(key)};
	if(keyIt != m_keyCount.end())
	{
		keyIt->second--;
		if(!keyIt->second)
			m_keyCount.erase(keyIt);
	}		
}

bool KeysDoors::canOpenDoor(const Point& pos)
{
	char key{static_cast<char>(tolower(m_grid[pos.x][pos.y]))};
	
	auto it{m_keyCount.find(key)};
	if(it != m_keyCount.end() && it->second >= 1)
	{
		it->second--;
		return true;
	}

	return false;
}

void KeysDoors::removeDoor(const Point& pos)
{
	char key{static_cast<char>(tolower(m_grid[pos.x][pos.y]))};
	
	auto it{m_keyCount.find(key)};
	if(it != m_keyCount.end())
		it->second++;
}
