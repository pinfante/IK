#ifndef __TRIE_H__
#define __TRIE_H__

#include<string>
#include<unordered_map>
#include<vector>

using std::vector;
using std::string;
using std::unordered_map;

class TrieNode
{
	TrieNode(bool isWord = false) : m_isWord{isWord}{}
	unordered_map<char, TrieNode*> 	m_ch;
	bool 						  	m_isWord;

	friend class Trie;
};

class Trie
{
	public:

		Trie() : m_root{new TrieNode()}{}

		TrieNode* find(const string& word);

		void insert(const string& word);

		bool isWord(const string& word);

		bool isPatternMatch(const string& pattern);

		vector<string> findWords(const string& prefix);

	private:

		void insert(const string& word, size_t i, TrieNode* node);

		TrieNode* find(const string& word, size_t i, TrieNode* node);

		bool isPatternMatch(const string& pattern, size_t i, TrieNode* node);

		void findWords(TrieNode* node, string word, vector<string>& words);

		TrieNode* m_root;
};

#endif //__TRIE_H__
