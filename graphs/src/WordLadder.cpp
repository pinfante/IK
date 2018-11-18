#include "WordLadder.h"


WordLadder::WordLadder(const vector<string>& words, const string& start, const string& target) 
: 
m_dict{words.begin(), words.end()},
m_start{start},
m_target{target}
{}

bool WordLadder::isDiffByOne(const string& w1, const string& w2) const
{
	size_t diff{0};
	for(size_t i{0}; i < w1.size(); ++i)
	{
		if(w1[i] != w2[i])
		{
			++diff;
			if(diff > 1)return false;		
		}
	}
	return diff == 1;
}

vector<string> WordLadder::getNeighbors(string word)
{
	vector<string> neighbors;
    
    if(m_dict.size() < 26)
    {
        for(auto& dictWord : m_dict)
        {
            if(isDiffByOne(word, dictWord))
                neighbors.push_back(dictWord);
        }
        
        if(isDiffByOne(word, m_target))
            neighbors.push_back(m_target);
            
        return neighbors;
    }
    
    for(size_t i{0}; i < word.size(); ++i)
    {
        char tmp = word[i];
        for(char j{'a'}; j <= 'z'; ++j)
        {
			if(j == tmp)continue;

			word[i] = j;

			if(word == m_target)
				neighbors.push_back(word);

			else if(m_dict.find(word) != m_dict.end())
				neighbors.push_back(word);
		}
		word[i] = tmp;
    }

	return neighbors;
}

vector<string> WordLadder::findpath(unordered_map<string, string>& parent)
{
    vector<string> path{m_target};


	auto it = parent.find(m_target);
    while(it != parent.end())
	{
		auto& val{it->second};
        path.push_back(val);
		if(val == m_start)
			break;

		it = parent.find(val);
	}
    
    return vector<string> (path.rbegin(), path.rend());
}

vector<string> WordLadder::bfs() 
{
    queue<string> q({m_start});
    unordered_map<string, string> parent;
    
    while(!q.empty())
    {
        auto& word{q.front()};
        vector<string> neighbors{getNeighbors(word)};
        for(auto neighbor : neighbors)
        {
            if(neighbor == m_target)
            {
                parent[neighbor] = word;
                return findpath(parent);
            }
            else if(parent.find(neighbor) == parent.end())
            {
                parent[neighbor] = word;
                q.push(neighbor);
            }
        }
        q.pop();
    }
    
    vector<string> ret;
    ret.push_back("-1");
    return ret;
}

