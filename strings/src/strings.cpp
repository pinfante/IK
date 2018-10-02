#include "strings.h"
#include "Trie.h"
#include<utility>
#include<sstream>
#include<iostream>

using std::cout;
using std::endl;
using std::make_pair;
using std::to_string;

void strings::reverseString(string& s)
{
	reverseString(s, 0, s.size()-1);	
}

void strings::reverseString(string& s, size_t beg, size_t end)
{
	if(beg >= end)return;

	std::swap(s[beg], s[end]);
	reverseString(s, beg+1, end-1);
}

bool strings::isPalindrone(const string& s)
{
	return isPalindrone(s, 0, s.size()-1);
}

bool strings::isPalindrone(const string& s, size_t l, size_t r)
{
	if(l > r)return true;

	if(s[l] != s[r])return false;

	return isPalindrone(s, l+1, r-1);
}

void strings::reverse(string& s, size_t i, size_t j)
{
	for(; i < j; ++i, --j)
		std::swap(s[i], s[j]);
}

int strings::isSubString(const string& s, const string& p)
{
	for(size_t i{0}; i < s.size(); ++i)
	{
		if(s[i] == p[0])
		{
			if(s.size() - i < p.size())return -1;
			for(size_t k{i+1}, j{1}; k < s.size() && j < p.size(); ++k, ++j)
			{
				if(s[k] != p[j]
					)break;
			
				return i;
			}
		}
	}
	return -1;
}

string strings::reverse_ordering_of_words(string& s) 
{
	reverse(s, 0, s.size()-1);

	size_t i{0};

	while(i < s.size() && s[i] == ' ')++i;
	size_t j{i};

	while(j < s.size())
	{
		while(s[j] != ' ' && j < s.size())++j;
		reverse(s, i, j-1);

		i = j;
		while(i < s.size() && s[i] == ' ')++i;
		j = i;
	}	

	return s;
}

bool strings::isAlphaChar(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string strings::move_letters_to_left(string s)
{
	size_t i{0}, j{0};

	while(i < s.size() && j < s.size())
	{
		while(i < s.size() && isAlphaChar(s[i]))++i;
		
		if(!j)
			j=i+1;
		else
			++j;

		while(j < s.size() && !isAlphaChar(s[j]))++j;

		if(j < s.size())
			std::swap(s[i], s[j]);
	}
	return s;	
}

bool strings::isMatch(const string& word, const string& pattern)
{
	Trie trie;
	trie.insert(word);
	return trie.isPatternMatch(pattern);
}

vector<int> strings::KMP(const string& s, const string& pattern)
{
	vector<int> res;
	if(pattern.size() == 1)
	{
		for(size_t i{0}; i < s.size(); ++i)
		{
			if(s[i] == pattern[0])
				res.push_back(i);
		}
		if(res.empty())res.push_back(-1);
		return res;
	}

	auto table{createLpsTable(pattern)};
	size_t i{0},j{0};
	
	while(true)
	{
		if(j == pattern.size())
		{
			res.push_back(i-j);
			j=table[j-1];
		}	

		if(i >= s.size())
			break;

		if(s[i] == pattern[j])
			++i, ++j;

		else if(!j)
			++i;
		else
			j = table[j-1];
	}

	if(res.empty())
		res.push_back(-1);

	return res;
}

vector<int> strings::createLpsTable(const string& pattern)
{
	vector<int> table(pattern.size(), 0);

	if(pattern.size() < 2)return table;
	
	auto size{static_cast<int>(pattern.size())};
	for(int i{1}, j{0}; i < size;)
	{
		if(pattern[i] == pattern[j])
		{
			table[i] = j+1;
			++i, ++j;
		}
		else
		{
			if(j)
				j = table[j-1];
			else
				table[i++] = 0;
		}
	}
	return table;
}	
	
string strings::longestSubStrWith2DistChars(const string& s)
{
	size_t maxSubStr{0}, start{0}, idx{0};
	unordered_map<char, int> hm;

	for(size_t i{0}; i < s.size(); ++i)
	{
		auto it = hm.find(s[i]);
		if(it != hm.end())
			it->second++;
		else
			hm.insert(make_pair(s[i], 1));
	
		if(hm.size() > 2)
		{
			if(i - start > maxSubStr)
			{
				maxSubStr = i - start;
				idx = start;
			}
		}
		while(hm.size() > 2)
		{
			auto it = hm.find(s[start]);
			if(it->second > 1)
				--it->second;
			else
				hm.erase(it);

			++start;				
		}
	}

	if(maxSubStr)
		return s.substr(idx, maxSubStr);
	else if (hm.size() > 1)return s;
	else return {};
}

/*
vector<string> strings::join_words_to_make_a_palindrome(const vector<string>& words)
{
	Trie trie, suffix;
	vector<string> res;

	for(const auto& w : words)
	{
		trie.insert(w);
		suffix.insert(w.reverse());
	}

//	for(const auto& w : words)

	return res;
	
}
*/

/*
vector<string> strings::neuronyms(const string& word)
{
	if(word.size() < 3)return vector<string>{};

	vector<string> words;
	neuronyms(word, words, 0, word.size()-1);	
	return words;
}

void strings::neuronyms(const string& word, vector<string>& words, size_t i, size_t j)
{
	if(j - i == 2)return;

	std::ostringstream ss;
	ss << word.substr(0, i+1) << word.size() - (i + 1 + word.size() - j) << word.substr(j, word.size());
	words.push_back(ss.str());

	neuronyms(word, words, i+1, j);
	neuronyms(word, words, i, j-1);
}
*/

vector<string> strings::neuronyms(const string& word)
{
	if(word.size() < 3)return vector<string>{};

	vector<string> words;
	size_t size{word.size()};
	
    words.emplace_back(word[0] + to_string(size-2) + word[size-1]);
    for(size_t i{size -3}; i >=2; --i)
	{
        for(size_t k{0}; k<=size-2-i; k++)
            words.emplace_back(word.substr(0,k+1) + to_string(i) + word.substr(i+k+1));
    }

	return words;
}

void strings::printAll(string st) 
{
    cout << st[0] << st.size()-2 << st[st.size()-1] << endl;
    for(size_t i=st.size()-3; i>=2; i--)
	{
        for(size_t k=0; k<=st.size()-2-i; k++)
            cout << st.substr(0,k+1) << i << st.substr(i+k+1) << endl;
    }
}
