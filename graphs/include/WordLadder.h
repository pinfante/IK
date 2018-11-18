#ifndef __WORD_LADDER_H__
#define __WORD_LADDER_H__

#include "graph.h"
#include <vector>
#include <string>
#include <string_view>
#include "graph.h"

using std::vector;
using std::string;
using std::string_view;

class WordLadder
{
	public:

		WordLadder(const vector<string>& words, const string& start, const string& stop);

		vector<string> bfs();

	private:

		bool isDiffByOne(const string& w1, const string& w2) const;

		vector<string> getNeighbors(string word);

		vector<string> findpath(unordered_map<string, string>& parent);

    	unordered_set<string> 	m_dict;
		string 					m_start;
		string					m_target;	
};

#endif
