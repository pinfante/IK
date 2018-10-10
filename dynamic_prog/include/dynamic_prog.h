#ifndef _DYNAMIC_PROG_H_
#define _DYNAMIC_PROG_H_

#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::vector;

namespace dynamic_prog
{
	//VIDEO PREP HW#1
	vector<vector<int>> maxPath(const vector<vector<int>>& grid);
	vector<int> getPath(const vector<vector<int>>& grid, const vector<vector<int>>& table);

	//VIDEO PREP HW#2
	int coinChange(const vector<int>& coins, int total);

	//LECTURE PROB#1
	int maxPrice(const vector<int>& prices, int len);

	//LECTURE PROB#2
	bool halfgroup(const vector<int>& vals);

	//HW#1
	int editDistance(const string& s1, const string& s2);

	//HW#2


	//HW#3
	int coinPlay(const vector<int>& coins); 
}

template<typename T>
void printGrid(const vector<vector<T>>& grid)
{
	for(const auto& g : grid)
	{
		for(const auto& el : g)
			std::cout << '[' << el << ']';
		std::cout << std::endl;
	}
}

#endif
