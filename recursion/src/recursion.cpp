#include "recursion.h"
#include<iostream>
#include<stack>
#include<sstream>
#include<algorithm>
#include "nQueens.h"
#include "towerOfHanoi.h"
#include "generate_all_expressions.h"

using std::cout;
using std::endl;
using std::make_pair;
using std::stack;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void recursion::allPermutions(string& str, size_t i, vector<string>& res)
{
	if(i == str.size()-1)
		res.push_back(str);
	else
	{
		for(size_t j{i}; j < str.size(); ++j)
		{
			std::swap(str[i], str[j]);
			allPermutions(str, i+1, res);
			std::swap(str[i], str[j]);
		}
	}
}

vector<string> recursion::allPermutions(string& str)
{
	vector<string> res;
	allPermutions(str, 0, res);
	return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> recursion::allSubSet(string& str)
{
	string s;
	vector<string> res;
	allSubSet(str, 0, s, 0, res);
	return res;
}

void recursion::allSubSet(string& str, size_t i, string s, size_t j, vector<string>& res)
{
	if(i == str.size())
	{
		res.push_back(s);
		return;
	}

	allSubSet(str, i+1, s, j, res);
	s += str[i];
	allSubSet(str, i+1, s, j+1, res);	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t recursion::countPaths(const vector<vector<char>>& grid)
{
	return countPaths(grid, 0, 0);
}

size_t recursion::countPaths(const vector<vector<char>>& grid, size_t row, size_t col)
{
	size_t rows{grid.size()};
	size_t cols{grid[0].size()};

	if(row >= rows || col >= cols)
		return 0;

	if(grid[row][col] == '*')
		return 0;

	if(row == rows-1 && col == cols-1)
		return 1;

	return countPaths(grid, row, col+1) + countPaths(grid, row+1, col);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool recursion::isSumInSubSet(const vector<int>& v, int sum)
{
	if(v.empty())
		return false;

	return isSumInSubSet(v, 0, 0, sum);
}

bool recursion::isSumInSubSet(const vector<int>& v, size_t i, int currSum, int sum)
{
	if(i == v.size())
		return false;

	currSum += v[i];

	if(currSum == sum)
		return true;

	return isSumInSubSet(v, i+1, currSum - v[i], sum) || isSumInSubSet(v, i+1, currSum, sum);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int recursion::KthSumSubSet(const vector<int>& v, size_t i, int k)
{
	if(!k)return 1;

	if(i == v.size())
		return 0;

	return KthSumSubSet(v, i+1, k) + KthSumSubSet(v, i+1, k-v[i]);
}

int recursion::KthSumSubSet(const vector<int>& v, int k)
{
	if(v.empty() || !k)
		return 0;
	return KthSumSubSet(v, 0, k);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t recursion::numOfSumInSubSet(const vector<int>& v, int sum)
{
	return numOfSumInSubSet(v, 0, 0, sum);
}

size_t recursion::numOfSumInSubSet(const vector<int>& v, size_t i, int currSum, int sum)
{
	if(i == v.size())
		return 0;

	currSum += v[i];

	if(currSum == sum)
		return 1 + numOfSumInSubSet(v, i+1, currSum - v[i], sum) + numOfSumInSubSet(v, i+1, currSum, sum);
	else
		return numOfSumInSubSet(v, i+1, currSum - v[i], sum) + numOfSumInSubSet(v, i+1, currSum, sum);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> recursion::generate_all_subsets(const string& s)
{
	vector<string> res;
	string subStr;
	return generate_all_subsets(s, subStr, res, 0);
}
vector<string> recursion::generate_all_subsets(const string& s, string subStr, vector<string>& v,  size_t i)
{
	if(i == s.size())
		v.push_back(subStr);
	else
	{
		v = generate_all_subsets(s, subStr, v,  i+1);
		subStr += s[i];
		v = generate_all_subsets(s, subStr, v,  i+1);
	}

	return v;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool recursion::check_if_sum_possible(const vector<long long>& arr, long long k)
{
	if(arr.empty())return false;

	return check_if_sum_possible(arr, 0, k, false);
}

bool recursion::check_if_sum_possible(const vector<long long>& arr, size_t i, long long k, bool usedNum)
{
	if(!k && usedNum)return true;

	if(i == arr.size())return false;

	return check_if_sum_possible(arr, i+1, k, usedNum) || check_if_sum_possible(arr, i+1, k - arr[i], true);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> recursion::find_well_formed_brackets(int k)
{
	vector<string> v;
	string s;
	s.reserve(k*2);
	return find_well_formed_brackets(0, 0, v, s, k);
}
vector<string> recursion::find_well_formed_brackets(int l, int r, vector<string>& v, string& s, int k)
{
	if(l < k)
	{
		s += '(';
		v = find_well_formed_brackets(l+1, r, v, s, k);
		s.pop_back();
	}

	if(r < l)
	{
		s += ')';
		v = find_well_formed_brackets(l, r+1, v, s, k);
		s.pop_back();
	}

	if(l == k && r == k)
		v.push_back(s);

	return v;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<string>> recursion::find_all_arrangements(int n)
{
	return nQueens(n);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long int recursion::how_many_BSTs(int n)
{
	unordered_map<int, long> cache;
	return how_many_BSTs(n, cache);
}
long long int recursion::how_many_BSTs(int n, unordered_map<int, long>& cache)
{
	if(n <= 1)
		return 1;
	else
	{
		size_t count{0};
		for(int i{1}; i <= n; ++i)
		{
			auto index1{n-i};
			auto it = cache.find(index1);
			auto val1{it != cache.end() ? it->second : how_many_BSTs(index1)};

			auto index2{i-1};
			it = cache.find(index2);
			auto val2{it != cache.end() ? it->second : how_many_BSTs(index2)};
			count += val1 * val2;
		}

		return count;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
vector<string> recursion::generate_all_expressions(const string& s, long long int target)
{
	GenExpressions gen;
	return gen.generateAllExpressions(s, target);
}

///////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int>> steps_in_tower_of_hanoi(int no_of_disks)
{
	TowerOfHanoi tower(no_of_disks);
	return tower.getSteps();
}

///////////////////////////////////////////////////////////////////////////////////////////////
void diameter_of_a_tree(string tree, int ans)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////
vector<string> recursion::find_all_possibilities(string& s)
{
	vector<string> v;
	find_all_possibilities(s, 0, v);
	return v; 
}

void recursion::find_all_possibilities(string s, size_t i, vector<string>& v)
{
	if(i == s.size())
		v.push_back(s);
	else
	{
		if(s[i] == '?')
		{
			s[i] = '0';
			find_all_possibilities(s, i+1, v);
			s[i] = '1';
			find_all_possibilities(s, i+1, v);
		}
		else
			find_all_possibilities(s, i+1, v);
	}
}

double recursion::pow(double base, int exp)
{
    if(exp == 0)
        return 1;
    
    auto res{pow(base, exp/2)};
    
    if(exp % 2 == 0)
        return res * res;
    else
    {
        if(exp > 0)
            return base * res * res;
        else
            return res*res/base;
    }
}

