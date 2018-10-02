#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<vector>
#include<unordered_set>

using std::vector;
using std::unordered_set;

class Vertex
{
	public:
		int value;
		vector<Vertex> edges;
};

namespace Graph
{
	void dfs(const vector<Vertex>& graph);
	void dfs(const Vertex& cur, unordered_set<int>& visited, vector<int>& components);
	void printComponents(const vector<int>& components);

	int bfs(const Vertex& start, const Vertex& target);
}

#endif
