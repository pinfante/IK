#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <vector>
#include <string>
#include "graph.h"
#include <utility>
#include <map>
#include <queue>
#include "Point.h"
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::queue;
using std::string;
using std::map;
using std::pair;
using std::unordered_map;
using std::unordered_set;

struct Node
{
	Node(int v) : val{v}{}

	int val;
	vector<Node*> neighbors;
};

namespace Graphs
{
	//HW #1
	string find_order(const vector<string>& words);
	Graph<char> alienDiction2Graph(const vector<string>& words);
	void createEdge(const string& w1, const string& w2, Graph<char>& graph);

	//HW #2
	int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col);

	//HW #3
	vector<string> string_transformation(const vector<string>& words, const string& start, const string& stop);


	//HW #4
	vector<Point> find_shortest_path(const vector<string>& grid);

	//HW #5
	int zombieCluster(const vector<string>& zombies);
	int findNextIslandToVisit(int n, const vector<bool>& visited);
	
	//QUIZ #1
	Node* build_other_graph(Node* node);
	void build_other_graph(const Node* node, unordered_map<int, Node*>& reversed);

	//HW #8
	bool hasCycle(const unordered_map<int, Node*>& graph, int edge, unordered_set<int>& curr, unordered_set<int>& visited);
	bool hasCycle(const vector<vector<int>>& edges);
	unordered_map<int, Node*> makeGraph(const vector<vector<int>>& edges);
	
}

#endif
