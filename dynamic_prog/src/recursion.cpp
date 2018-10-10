#include "recursion.h"
#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <utility>
#include <string_view>

using std::endl;
using std::cout;
using std::make_pair;
using std::max;
using std::min;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> recursion::maxPath(const vector<vector<int>>& grid)
{
	size_t len{grid.size()+grid[0].size()-1};
	vector<int> res(len, 0);
	maxPath(grid, 0, 0, 0, res);
	return res;
}

void recursion::maxPath(const vector<vector<int>>& grid, size_t r, size_t c, size_t step, vector<int>& res)
{
	if(r == grid.size() || c == grid[0].size()) return;

	if(r == grid.size()-1 && c == grid[0].size()-1)
	{
		res[step] = grid[r][c];
		return;
	}

	maxPath(grid, r+1, c, step+1, res);

	if(res[step] < grid[r][c])
		res[step] = grid[r][c];
	
	maxPath(grid, r, c+1, step+1, res);

	if(res[step] < grid[r][c])
		res[step] = grid[r][c];
}
//////////////////////////////////////////////////////////////////////////////////////////////////

int recursion::maxPathValue(const vector<vector<int>>& grid)
{
	return maxPathValue(grid, 0, 0, 0);
}

int recursion::maxPathValue(const vector<vector<int>>& grid, size_t r, size_t c, int val)
{
	if(r == grid.size() || c == grid[0].size()) return 0;

	val += grid[r][c];

	if(r == grid.size()-1 && c == grid[0].size()-1)
		return val;
	
	return max(maxPathValue(grid, r+1, c, val), maxPathValue(grid, r, c+1, val));
}
//////////////////////////////////////////////////////////////////////////////////////////////////

int recursion::coinChange(const vector<int>& coins, int amount)
{
	if(amount == 0)return 0;

	vector<int> res;
	for(auto& coin : coins)
		if(amount - coin >= 0)
			res.push_back(coinChange(coins, amount - coin));

	auto it = min_element(res.begin(), res.end());
	if(it == res.end())
		return 0;
	
	return 1 + *it;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int recursion::maxPrice(const vector<int>& prices, int len)
{
	unordered_map<int, int> cache;
	return maxPrice(prices, len, cache);
}

int recursion::maxPrice(const vector<int>& prices, int len, unordered_map<int, int>& cache)
{
	if(len == 0)return 0;
	if(len < 0)return INT_MIN;
	
	int maxP{0};
	for(size_t i{1}; i <= prices.size(); ++i)
	{
		auto it = cache.find(len);
		if(it != cache.end())
			return it->second;

		maxP = max(prices[i-1] + maxPrice(prices, len-i, cache), maxP);
	}
	cache.insert(make_pair(len, maxP));
	return maxP;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool recursion::halfgroup(const vector<int>& vals)
{
	int sum{std::accumulate(vals.begin(), vals.end(), 0)};
	if(sum % 2)return false;

	return halfgroup(vals, 0, sum/2);
}

bool recursion::halfgroup(const vector<int>& vals, size_t i, int sum)
{
	if(sum == 0)return true;

	if(vals.size() == i)return false;

	bool res{false};

	if(sum - vals[i] >= 0)
		res = halfgroup(vals, i+1, sum - vals[i]);

	return res || halfgroup(vals, i+1, sum);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int recursion::editDistance(const string& s1, const string& s2)
{
	return editDistance(s1, 0, s2, 0);
}

int recursion::editDistance(const string& s1, size_t i, const string& s2, size_t j)
{
	if(i == s1.size() || j == s2.size())
		return max(s1.size() - i, s2.size()-j);

	if(s1[i] == s2[j])
		return editDistance(s1, i+1, s2, j+1);
	else
		return 1 + min(min(editDistance(s1, i+1, s2, j), 
						   editDistance(s1, i, s2, j+1)), 
						   editDistance(s1, i+1, s2, j+1));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int recursion::longestCommonSubsequence(const string& s1, const string& s2)
{
	return longestCommonSubsequence(s1, 0, s2, 0);
}

int recursion::longestCommonSubsequence(const string& s1, size_t i, const string& s2, size_t j)
{
	if(i == s1.size() || j == s2.size()) return 0;

	if(s1[i] == s2[j])
		return 1 + longestCommonSubsequence(s1, i+1, s2, j+1);
	else
		return max(longestCommonSubsequence(s1, i, s2, j+1), longestCommonSubsequence(s1, i+1, s2, j));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long int recursion::max_product_from_cut_pieces(int n)
{
	return max_product_from_cut_pieces(0, 0, n);
}

long long int recursion::max_product_from_cut_pieces(int i, int j, int n)
{
	if(i+j == n)return i*j;
	if(i+j > n)return 0;

	return max(max(max_product_from_cut_pieces(i+1, j, n), 
				   max_product_from_cut_pieces(i, j+1, n)), 
				   max_product_from_cut_pieces(i+1, j+1, n));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int recursion::numberOfPaths(const vector<vector<int>>& grid)
{
	return numberOfPaths(grid, 0, 0);
}

int recursion::numberOfPaths(const vector<vector<int>>& grid, size_t i, size_t j)
{
	if(i == grid.size()-1 && j == grid[0].size()-1)return 1;

	if(i == grid.size() || j == grid[0].size())return 0;

	if(grid[i][j] == 0)return 0;

	return 1 + max(numberOfPaths(grid, i+1, j), numberOfPaths(grid, i, j+1));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
vector<string> wordBreak(const string& word, vector<string>& dict)
{
	vector<string> res;
	if(word.empty())return res;
	
	unordered_set<string> wordSet{dict.begin(), dict.end()};
	string wBreak;

	return wordBreak(word, wordSet, wbreak, 0, 0, res);
}

vector<string> wordBreak(const string& word, unordered_set<string>& dict, string& wbreak, size_t i, size_j, vector<string>& res)
{
	if(i == word.size() || j == word.size())
	{
		res.push_back(wbreak);
		return;
	}

	string_view sv{word[i], word[j]};
	if(dict.find(sv) != dict.end())
	{
		wbreak += " ";
		wbreak += sv;
		return wordBreak(word, dict, wbreak, j, j+1, res);
	}

	return wordBreak(word, dict, wbreak, i, j+1, res);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
