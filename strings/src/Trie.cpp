#include "Trie.h"
#include <utility>

using std::make_pair;

TrieNode* Trie::find(const string& word)
{
	return find(word, 0, m_root);
}

TrieNode* Trie::find(const string& word, size_t i, TrieNode* node)
{
	if(i == word.size())
		return node->m_isWord ? node : nullptr;

 	auto it = node->m_ch.find(word[i]);
	if(it == node->m_ch.end())return nullptr;

	return find(word, i+1, it->second); 
}

void Trie::insert(const string& word)
{
	if(word.empty())return;
	insert(word, 0, m_root);
}

void Trie::insert(const string& word, size_t i, TrieNode* node)
{
	if(i == word.size())
	{
		node->m_isWord = true;
		return;
	}

	auto it = node->m_ch.find(word[i]);
	if(it == node->m_ch.end())
	{
		auto ch = node->m_ch.insert(make_pair(word[i], new TrieNode{false}));
		it = ch.first;
	}

	insert(word, i+1, it->second);
}

bool Trie::isWord(const string& word)
{
	return find(word);
}

bool Trie::isPatternMatch(const string& pattern)
{
	return isPatternMatch(pattern, 0, m_root);
}

bool Trie::isPatternMatch(const string& pattern, size_t i, TrieNode* node)
{
	if(pattern.size() == i)return node->m_isWord;

	bool isMatch{false};

	if(pattern[i] == '.')
	{
		for(auto nextNode : node->m_ch)
			isMatch |= isPatternMatch(pattern, i+1, nextNode.second);

		return isMatch;
	}
	else if (pattern[i] == '*')
	{
		for(auto nextNode : node->m_ch)
			isMatch |= isPatternMatch(pattern, i, nextNode.second);

		if(i < pattern.size())
			isMatch |= isPatternMatch(pattern, i+1, node);

		return isMatch;
	}
	else
	{
		auto it = node->m_ch.find(pattern[i]);
		if(it == node->m_ch.end())
		{
			if(i+1 != pattern.size() && pattern[i+1] == '*')
				return isPatternMatch(pattern, i+2, node);
			else
				return false;
		}
		return isPatternMatch(pattern, i+1, it->second);
	}

	return isMatch;
}

vector<string> Trie::findWords(const string& prefix)
{
	vector<string> words;
	auto currNode{m_root};

	for(size_t i{0}; i < prefix.size(); ++i)
	{
		auto it = currNode->m_ch.find(prefix[i]);
		if(it == currNode->m_ch.end()) return words;
		currNode = it->second;
	}

	string word{prefix};
	findWords(currNode, word, words);
	return words;
}

void Trie::findWords(TrieNode* node, string word, vector<string>& words)
{
	if(node->m_isWord)
		words.push_back(word);

	for(auto& nxt : node->m_ch)
	{
		word += nxt.first;
		findWords(nxt.second, word, words);
		word.pop_back();
	} 
}
