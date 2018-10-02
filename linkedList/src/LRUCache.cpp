#include "LRUCache.h"
using std::make_pair;

LRUCache::LRUCache(size_t capacity) 
:
m_capacity{capacity}
{
	m_cache.reserve(m_capacity);
}

int LRUCache::getQuery(int key)
{
	auto it = m_cache.find(key);
	if(it == m_cache.end())
		return -1;

	if(it->second != m_entries.begin())
	{
		int value{it->second->second};
		m_entries.erase(it->second);
		m_entries.push_front(make_pair(key, value));
		it->second = m_entries.begin();
	}

	return it->second->second;
}

void LRUCache::setQuery(int key, int value)
{
	auto it = m_cache.find(key);
	if(it != m_cache.end())
	{
		m_entries.erase(it->second);
		m_entries.push_front(make_pair(key, value));
		it->second = m_entries.begin();
		return;
	}

	if(m_entries.size() == m_capacity)
	{
		m_cache.erase(m_entries.back().first);
		m_entries.pop_back();
	}

	m_entries.push_front(make_pair(key,value));
	m_cache.insert(make_pair(key, m_entries.begin()));
}


vector<int> implement_LRU_cache(int capacity, const vector<int>& query_type, const vector<int>& keys, const vector<int>& values)
{
	vector<int> res;
	LRUCache cache(capacity);

	for(size_t i{0}; i < query_type.size(); ++i)
	{
		switch(query_type[i])
		{
			case 0:
				res.push_back(cache.getQuery(keys[i]));
				break;

			case 1:
				cache.setQuery(keys[i], values[i]);
				break;

			default:
				break;
		}
	}

	return res;
}



