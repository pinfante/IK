#include "gmock/gmock.h"
#include "graphs.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include "KeysDoors.h"

using std::string;
using namespace testing;
using namespace Graphs;

TEST(TestGraphs, VertexAddEdge)
{
	Vertex<char> v{'a'};
	v.addEdge('b');

	Vertex<char> b{'b'};
	auto it = v.m_edges.find(&b);
	auto end = v.m_edges.end();

	EXPECT_THAT(v.m_value, Eq('a'));
	ASSERT_THAT(it, Ne(end));
	EXPECT_THAT((*it)->m_value, Eq('b'));	
}

TEST(TestGraphs, GraphAdd)
{
	Graph<char> graph;
	graph.add('a','b');
	graph.add('c');

	auto v = graph.find('a');
	ASSERT_THAT(v, NotNull());
	EXPECT_THAT(v->m_value, Eq('a'));

	auto edge = v->findEdge('b');
	EXPECT_THAT(edge->m_value, Eq('b'));
	v = graph.find('c');
	ASSERT_THAT(v, NotNull());
	EXPECT_THAT(v->m_value, Eq('c'));

	auto b = graph.find('b');
	ASSERT_THAT(b, NotNull());
	graph.add('b', 'f');
	graph.add('b', 'g');

	auto g = graph.find('g');
	ASSERT_THAT(g, NotNull());
	EXPECT_THAT(g->m_value, Eq('g'));
}

TEST(TestGraphs, alienDict)
{
	auto alphabet{find_order(vector<string>{"dca", "dbc", "dab", "cba", "cac", "caa", "bb"})};
	EXPECT_THAT(alphabet.size(), Eq(4));
	EXPECT_THAT(alphabet[0], Eq('d'));
	EXPECT_THAT(alphabet[1], Eq('c'));
	EXPECT_THAT(alphabet[2], Eq('b'));
	EXPECT_THAT(alphabet[3], Eq('a'));

	alphabet = find_order(vector<string>{"baa","abcd","abca","cab","cad"});
	EXPECT_THAT(alphabet.size(), Eq(4));
	EXPECT_THAT(alphabet[0], Eq('b'));
	EXPECT_THAT(alphabet[1], Eq('d'));
	EXPECT_THAT(alphabet[2], Eq('a'));
	EXPECT_THAT(alphabet[3], Eq('c'));

	alphabet = find_order(vector<string>{"g","g","g","g","g"});
	EXPECT_THAT(alphabet.size(), Eq(1));
	EXPECT_THAT(alphabet[0], Eq('g'));
} 

TEST(TestGraphs, find_minimum_number_of_moves)
{
	EXPECT_THAT(find_minimum_number_of_moves(5, 5, 0, 0, 4, 3), Eq(3));
	EXPECT_THAT(find_minimum_number_of_moves(10, 10, 0, 4, 9, 8), Eq(5));
	EXPECT_THAT(find_minimum_number_of_moves(2, 7, 0, 5, 1, 1), Eq(-1));
	EXPECT_THAT(find_minimum_number_of_moves(33333, 3, 333, 0, 33332, 2), Eq(16501));
	EXPECT_THAT(find_minimum_number_of_moves(3, 33332, 1, 1599, 1, 0), Eq(801));
}

TEST(TestGraphs, string_transformation)
{
	vector<string> dict{"cat", "hat", "bad"};
	auto ladder{string_transformation(dict,"bat", "had")};
	vector<string> expected{"bat", "bad", "had"};
	ASSERT_THAT(ladder.empty(), Eq(false));
	EXPECT_THAT(ladder.size(), Eq(3));
	EXPECT_THAT(ladder, Eq(expected));
	 
	dict = vector<string>{"a","b","c"};
	ladder = string_transformation(dict, "y", "x");
	expected = {"y", "x"};
	ASSERT_THAT(ladder.empty(), Eq(false));
	EXPECT_THAT(ladder, Eq(expected));

	dict = vector<string>{"cccw","accc","accw"}; 
	ladder = string_transformation(dict, "cccc" ,"cccc");
	expected = {"cccc", "accc", "cccc"};
	ASSERT_THAT(ladder.empty(), Eq(false));
	EXPECT_THAT(ladder, Eq(expected));

	dict = {"a","w","y","q","r","w","q","i","y","y","s"};
	ladder = string_transformation(dict, "b","h");
	expected = {"b", "h"};
	ASSERT_THAT(ladder.empty(), Eq(false));
	EXPECT_THAT(ladder, Eq(expected));
}

TEST(TestGraphs, DISABLED_KeysDoors)
{
	auto expected{vector<Point>{{2,0},{1,0},{1,1},{0,1},{0,2},{0,3},{1,3},{2,3},{2,2}}};
	auto res{find_shortest_path(vector<string>{"...B", ".b#.", "@#+."})};
	EXPECT_THAT(expected, Eq(res));

	expected = vector<Point>{{4,2},{3,2},{2,2},{3,2},{3,1},{3,0},{3,1},{3,2},{3,3},{3,4},{2,4},{1,4},{0,4},{0,3},{0,2},{0,1},{0,0}};
	res = find_shortest_path(vector<string>{"+B...","####.","##b#.","a...A","##@##"});
	EXPECT_THAT(expected, Eq(res));
}

TEST(TestGraphs, build_other_graph)
{
	Node n{1}, n2{2}, n3{3};
	n.neighbors.push_back(&n2);
	n2.neighbors.push_back(&n3);

	auto rn{build_other_graph(&n)};
	EXPECT_THAT(rn->val, Eq(n3.val));
	EXPECT_THAT(rn->neighbors[0]->val, Eq(n2.val));
	EXPECT_THAT(rn->neighbors[0]->neighbors[0]->val, Eq(n.val));
}
