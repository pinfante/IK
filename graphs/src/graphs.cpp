#include "graphs.h"
#include <iostream>
#include <utility>
#include <queue>

using std::make_pair;
using std::cout;
using std::endl;
using std::queue;


void Graph::dfs(const vector<Vertex>& graph)
{
	unordered_set<int> visited;
	vector<int> components;

	for(const auto& v : graph)
	{
		if(visited.find(v.value) == visited.end())
			dfs(v, visited, components);		
	} 
}

void Graph::dfs(const Vertex& cur, unordered_set<int>& visited, vector<int>& components)
{
	visited.insert(cur.value);
	components.push_back(cur.value);

	for(const auto& edge : cur.edges)
		dfs(edge, visited, components);
}

void Graph::printComponents(const vector<int>& components)
{
	for(const auto& c : components)
		cout << "[" << c << "]";
	cout << endl;
}


int Graph::bfs(const Vertex& start, const Vertex& target)
{
	vector<int> distance;
	queue<Vertex> que;
	unordered_set<int> visited;

	que.push(start);
	distance.push_back(0);
	visited.insert(start.value);

	while(!que.empty())
	{
		auto& cur{que.front()};
		if(cur.value == target.value)
			distance[cur.value];

		for(auto& nxt : cur.edges)
		{
			if(visited.find(nxt.value) == visited.end())
			{
				que.push(nxt);
				visited.insert(nxt.value);
				distance.push_back(distance[cur.value] + 1);		
			}
		}
	}
	return -1;	
}
