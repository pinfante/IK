#ifndef __RECURSION_H__
#define __RECURSION_H__

#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

namespace recursion
{
	//VIDEO PREP #1
	int maxPathValue(const vector<vector<int>>& grid);
	int maxPathValue(const vector<vector<int>>& grid, size_t r, size_t c, int val);

	//#1 returns the elements.
	vector<int> maxPath(const vector<vector<int>>& grid);
	void maxPath(const vector<vector<int>>& grid, size_t r, size_t c, size_t step, vector<int>& res);

	//VIDEO PREP #2
	int coinChange(const vector<int>& coins, int amount);

	//LECTURE #1 (ROPE CUTTING)
	int maxPrice(const vector<int>& prices, int len);
	int maxPrice(const vector<int>& prices, int len, unordered_map<int, int>& cache);

	//LECTURE #2 (HALF GROUP)
	bool halfgroup(const vector<int>& vals);
	bool halfgroup(const vector<int>& vals, size_t i, int sum);

	//LECTURE #3 (EDIT DISTANCE) HW#1
	int editDistance(const string& s1, const string& s2);
	int editDistance(const string& s1, size_t sz1, const string& s2, size_t sz2);

	//LECTURE #4 LONGEST COMMON SUBSTRING
	int longestCommonSubsequence(const string& s1, const string& s2);
	int longestCommonSubsequence(const string& s1, size_t i, const string& s2, size_t j);

	//TEST CUTTING ROPE
	long long int max_product_from_cut_pieces(int n);
	long long int max_product_from_cut_pieces(int i, int j, int n);

	int numberOfPaths(const vector<vector<int>>& grid);
	int numberOfPaths(const vector<vector<int>>& grid, size_t i, size_t j);

	//HW #2
//	vector<string> wordBreak(const string& word, vector<string>& dict);
//	vector<string> wordBreak(const string& word, unordered_set<string>& dict, string& wbreak, size_t i, size_j, vector<string>& res);

	



}

#endif
