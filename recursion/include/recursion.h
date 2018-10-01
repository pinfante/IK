#ifndef _RECURSION_H_ 
#define _RECURSION_H_

#include<string>
#include<vector>
#include<unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

namespace recursion
{
	//PREP #1
	vector<string> allPermutions(string& str);
	void allPermutions(string& str, size_t i, vector<string>& res);

	//PREP #2
	vector<string> allSubSet(string& str);
	void allSubSet(string& str, size_t i, string s, size_t j, vector<string>& res);

	//PREP #3
	size_t countPaths(const vector<vector<char>>& grid);
	size_t countPaths(const vector<vector<char>>& grid, size_t row, size_t col);

	//PREP #4
	bool isSumInSubSet(const vector<int>& v, int sum);
	bool isSumInSubSet(const vector<int>& v, size_t i, int curr, int sum);

/////////////////////////////////////////////////////////////////////////////////////////
	//LECTURE #1
	//return #of path that sum to k : assuming values of v and k > 0
	int KthSumSubSet(const vector<int>& v, int k);
	int KthSumSubSet(const vector<int>& v, size_t i, int k);

	//values of v can be negative numbers.
	//with repeating numbers.

	//PROBLEM 3
	//bool isRegexMatch(const string& pattern, const string& str){return false;}
	//bool isRegexMatch(const string& pattern, int p, const string& str, int s){return false;}

	size_t numOfSumInSubSet(const vector<int>& v, int sum);
	size_t numOfSumInSubSet(const vector<int>& v, size_t i, int currSum, int sum);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//QUIZ 1
	bool check_if_sum_possible(const vector<long long>& arr, long long k);
	bool check_if_sum_possible(const vector<long long>& arr, size_t i, long long k, bool usedNum);

	//QUIZ 2
	vector<string> find_well_formed_brackets(int n);
	vector<string> find_well_formed_brackets(int left, int right, vector<string>& v, string& s, int k);
/////////////////////////////////////////////////////////////////////////////////////////////////////////

	//HW #1
	vector<string> generate_all_expressions(const string& s, long long int target);

	//HW #2
	vector<string> generate_all_subsets(const string& s);
	vector<string> generate_all_subsets(const string& s, string subStr, vector<string>& v,  size_t i);

	//HW #3
	//nQueens
	vector<vector<string>> find_all_arrangements(int n);

	//HW #4
	long long int how_many_BSTs(int n);
	long long int how_many_BSTs(int n, unordered_map<int, long>& cache);

	//HW #6
	vector<vector<int>> steps_in_tower_of_hanoi(int no_of_disks);

	//HW #7
	void diameter_of_a_tree(string tree, int ans);

	//HW #8
	vector<string> find_all_possibilities(string& s);
	void find_all_possibilities(string s, size_t i, vector<string>& v);

	//HW #9
	double pow(double base, int exp);

		
}

#endif
