#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <boost/functional/hash.hpp>

using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::queue;
using std::make_pair;
using std::cout;
using std::endl;
using std::map;

template<typename T>class Vertex;

template<typename T>
class VertexHash
{
	public:
		std::size_t operator()(const Vertex<T>* v) const
		{
			size_t seed{0};
			boost::hash_combine(seed, boost::hash_value(v->m_value));
			return seed; 
		}
};

template<typename T>
class VertexEqual
{
	public:
		bool operator()(const Vertex<T>* x, const Vertex<T>* y) const
		{
			return x->m_value == y->m_value;
		}
};

template<typename T>
class Vertex
{
	public:
		Vertex(T val) : m_value{val}{}
		Vertex(T val, T edge) : m_value{val}, m_edges{new Vertex<T>{edge}}{}

		Vertex<T>* addEdge(const T& edgeValue);
		void addEdge(Vertex<T>* edge);
		Vertex<T>* findEdge(const T& val);
	
		T m_value;
		unordered_set<Vertex<T>*, VertexHash<T>, VertexEqual<T>> m_edges;
};

template<typename T>
Vertex<T>* Vertex<T>::addEdge(const T& edgeVal)
{
	auto edge = findEdge(edgeVal);
	if(edge)
		return edge;

	auto v{new Vertex<T>{edgeVal}};
	m_edges.insert(v);
	return v;
}

template<typename T>
void Vertex<T>::addEdge(Vertex<T>* edge)
{
	if(m_edges.find(edge) == m_edges.end())
		m_edges.insert(edge);
}

template<typename T>
Vertex<T>* Vertex<T>::findEdge(const T& val)
{
	Vertex<T> edge{val};

	auto it = m_edges.find(&edge);
	if(it == m_edges.end())
		return nullptr;

	return *it;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Graph
{
	public:

		using VertexMap = unordered_map<Vertex<T>*, Vertex<T>*, VertexHash<T>, VertexEqual<T>>;
		using VertexSet = unordered_set<Vertex<T>*, VertexHash<T>, VertexEqual<T>>;

		Vertex<T>* find(const T& val);
		Vertex<T>* find(Vertex<T>& v);

		void add(const T& val);
		void add(const T& val, const T& edgeVal);

		void dfs();
		void dfs(const Vertex<T>& cur, unordered_set<T>& visited, vector<T>& components);

		vector<Vertex<T>*> bfs(const T& start, const T& target);
		vector<Vertex<T>*> bfsPath(VertexMap& parents, Vertex<T>* target);

		bool isTargetInEdge(Vertex<T>* curr, Vertex<T>* tVertex) const;
		

		vector<Vertex<T>*> top_sort();

		VertexSet m_vertices;
		
};

template<typename T>
Vertex<T>* Graph<T>::find(const T& val)
{
	auto v{Vertex{val}};
	return find(v);
}

template<typename T>
Vertex<T>* Graph<T>::find(Vertex<T>& v)
{
	auto it = m_vertices.find(&v);
	if(it == m_vertices.end()) return nullptr;

	return *it;
}

template<typename T>
void Graph<T>::add(const T& val)
{
	auto v{Vertex<T>{val}};

	auto it = m_vertices.find(&v);
	if(it == m_vertices.end())
		m_vertices.insert(new Vertex{val});
}

template<typename T>
void Graph<T>::add(const T& val, const T& edgeVal)
{
	auto v = find(val);
	auto edge = find(edgeVal);

	if(!v)
	{
		v = new Vertex<T>{val};
		m_vertices.insert(v);
	}
	if(edge)
		v->addEdge(edge);
	else
		m_vertices.insert(v->addEdge(edgeVal));
		
}

template<typename T>
void Graph<T>::dfs()
{
	unordered_set<T> visited;
	vector<T> components;

	for(const auto& v : m_vertices)
	{
		if(visited.find(v.m_value) == visited.end())
			dfs(v, visited, components);		
	} 
}

template<typename T>
void Graph<T>::dfs(const Vertex<T>& cur, unordered_set<T>& visited, vector<T>& components)
{
	visited.insert(cur.m_value);
	components.push_back(cur.m_value);

	for(const auto& edge : cur.m_edges)
		dfs(edge, visited, components);
}

template<typename T>
bool Graph<T>::isTargetInEdge(Vertex<T>* curr, Vertex<T>* tVertex) const
{
	return curr->m_edges.find(tVertex) != curr->m_edges.end();
}

template<typename T>
vector<Vertex<T>*> Graph<T>::bfs(const T& start, const T& target)
{
	auto stVertex = find(start);
	auto tVertex = find(target);
   
	 if(!stVertex || !tVertex)return vector<Vertex<T>*>{};

	if(stVertex == tVertex && !stVertex->m_edges.empty())
		return vector<Vertex<T>*>{stVertex, *stVertex->m_edges.begin(), stVertex}; 
	
	auto parent{stVertex};
	VertexMap parents{{parent, nullptr}};

	if(isTargetInEdge(parent, tVertex))
	{
		parents.insert(make_pair(tVertex, parent));
		return bfsPath(parents, tVertex);
	}

	for(auto e : parent->m_edges)
		parents.insert(make_pair(e, parent));

	queue<Vertex<T>*> neighbors({parent->m_edges.begin(), parent->m_edges.end()});
	VertexSet visited{parent};
	
	while(!neighbors.empty())
	{
		auto neighbor{neighbors.front()};

		if(visited.find(neighbor) == visited.end())
		{
			visited.insert(neighbor);
			parents.insert(make_pair(neighbor, parent));

			if(neighbor->m_value == target)
				return bfsPath(parents, neighbor);

			for(auto edge : neighbor->m_edges)
			{
				auto eit = parents.find(edge);
				if(eit == parents.end() && edge != stVertex)
				{
					parents.insert(make_pair(edge, neighbor));

					if(isTargetInEdge(edge, tVertex))
					{
						parents.insert(make_pair(tVertex, edge));
						return bfsPath(parents, tVertex);
					}
					neighbors.push(edge);
				}
			}
		}

		parent = neighbor;
		neighbors.pop();
	}
	return vector<Vertex<T>*>{};
}

template<typename T>
vector<Vertex<T>*> Graph<T>::bfsPath(VertexMap& parents, Vertex<T>* target)
{
	auto it = parents.find(target);
	vector<Vertex<T>*> path{target};
		
	while(it != parents.end())
	{
		if(!it->second)
			return vector<Vertex<T>*>{path.rbegin(), path.rend()};

		path.push_back(it->second);
		it = parents.find(it->second);
	}
	
	return vector<Vertex<T>*>{};
}

template<typename T>
vector<Vertex<T>*> Graph<T>::top_sort()
{
	unordered_map<Vertex<T>*, size_t, VertexHash<T>, VertexEqual<T>> degrees;

	for(auto v : m_vertices)
	{
		auto it = degrees.find(v);
		if(it == degrees.end())
			degrees.insert(make_pair(v, 0));

		for(auto e : v->m_edges)
		{
			auto eit = degrees.find(e);
			if(eit == degrees.end())
			{
				auto it = degrees.insert(make_pair(e, 0));
				eit = it.first;
			}
			eit->second++;
		}
	}

	queue<Vertex<T>*> q;

	for(auto& it : degrees)
	{
		if(it.second == 0)
			q.push(it.first);
	}

	vector<Vertex<T>*> order;

	while(!q.empty())
	{
		auto v{q.front()};
		order.push_back(v);

		for(auto& e : v->m_edges)
		{
			auto eit = degrees.find(e);
			eit->second--;

			if(eit->second == 0)
				q.push(e);
		}
		q.pop();
	}

	return order;
}

#endif
