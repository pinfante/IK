#include "graphs.h"
#include "KnightsTour.h"
#include "WordLadder.h"
#include "KeysDoors.h"
#include <numeric>

using std::make_pair;

string Graphs::find_order(const vector<string>& words)
{
	auto graph{alienDiction2Graph(words)};
	auto orders{graph.top_sort()};
	return std::accumulate(orders.begin(), orders.end(), string{}, [](string& res, const auto v){return res += v->m_value;});
}

Graph<char> Graphs::alienDiction2Graph(const vector<string>& words)
{
	Graph<char> graph;
	
	if(words.empty())
		return graph;

	for(auto it = words.begin()+1; it != words.end(); ++it)
		createEdge(*(it-1), *it, graph);

	if(graph.m_vertices.empty())
		graph.add(words[0][0]);

	return graph;
}

void Graphs::createEdge(const string& w1, const string& w2, Graph<char>& graph)
{
	for(size_t i{0}; i < w1.size() && i < w2.size(); ++i)
	{
		if(w1[i] != w2[i])
		{
			graph.add(w1[i], w2[i]);
			return;
		}
	}
}

int Graphs::find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col)
{
	KnightsTour knight{rows, cols, start_row, start_col, end_row, end_col};
	return knight.findMinimumMoves();
}

vector<Point> Graphs::find_shortest_path(const vector<string>& grid)
{
	KeysDoors keyDoor{grid};
	return keyDoor.dfs();
}

vector<string> Graphs::string_transformation(const vector<string>& words, const string& start, const string& stop)
{
	WordLadder ladder{words, start, stop};
	return ladder.bfs();
}

int Graphs::zombieCluster(const vector<string>& zombies)
{
	vector<bool> visited(zombies.size(), false);
	queue<int> toVisit;

	int nIslands{0}, nextIsland{0};

	while((nextIsland = findNextIslandToVisit(zombies.size(), visited)) != -1)
	{
		toVisit.push(nextIsland);

		while(!toVisit.empty())
		{
			auto i{toVisit.front()};
			toVisit.pop();

			if(visited[i])
				continue;

			for(int j{0}; j < static_cast<int>(zombies.size()); ++i)
			{
				if(zombies[i][j] == '1' && i != j)
					toVisit.push(j);
			}
			visited[i] = true;
		}
		++nIslands;
	}

	return nIslands;
}

int Graphs::findNextIslandToVisit(int n, const vector<bool>& visited)
{
	for(int i{0}; i < n; ++i)
		if(!visited[i])
			return i;
	return -1;
}

void Graphs::build_other_graph(const Node* node, unordered_map<int, Node*>& reversed)
{
	auto revParent{new Node{node->val}};
	reversed.insert(make_pair(revParent->val, revParent));
	
	for(auto n : node->neighbors)
	{
		auto nit{reversed.find(n->val)};
		if(nit == reversed.end())
		{
			build_other_graph(n, reversed);
			nit = reversed.find(n->val);
		}

		nit->second->neighbors.push_back(revParent);
	}
}

Node* Graphs::build_other_graph(Node* node)
{
	if(!node)return nullptr;

	unordered_map<int, Node*> reversed;
	build_other_graph(node, reversed);

	return reversed.begin()->second;
}

bool Graphs::hasCycle(const unordered_map<int, Node*>& graph, int edge, unordered_set<int>& curr, unordered_set<int>& visited)
{
	if(curr.find(edge) != curr.end())
		return true;

	if(visited.find(edge) != visited.end())
		return false;

	visited.insert(edge);

	auto it = graph.find(edge);
	if(it == graph.end())
		return false;

	curr.insert(edge);

	for(auto n : it->second->neighbors)
		if(hasCycle(graph, n->val, curr, visited))
			return true;

	curr.erase(edge);

	return false;
}

bool Graphs::hasCycle(const vector<vector<int>>& edges)
{
	auto graph{makeGraph(edges)};
	unordered_set<int> visited;
	unordered_set<int> curr;

	for(size_t i{0}; i < edges.size(); ++i)
	{
		if(hasCycle(graph, edges[i][0], curr, visited))
			return true;
	}
	return false;	
}

unordered_map<int, Node*> Graphs::makeGraph(const vector<vector<int>>& edges)
{
	unordered_map<int, Node*> graph;
	for(size_t i{0}; i < edges.size(); ++i)
	{
		int vertex{edges[i][0]};
		int edge{edges[i][1]};
		auto it = graph.find(vertex);
		if(it == graph.end())
		{
			auto v{new Node{vertex}};
			v->neighbors.push_back(new Node{edge});
			graph.insert(make_pair(v->val, v));
		}
		else
			it->second->neighbors.push_back(new Node{edge});
	}
	return graph;
}

