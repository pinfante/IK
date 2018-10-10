#include "dynamic_prog.h"
#include <algorithm>
#include <climits>
#include <numeric>
using std::endl;
using std::cout;
using std::max;
using std::min;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int>> dynamic_prog::maxPath(const vector<vector<int>>& grid)
{
	int rows{static_cast<int>(grid.size())}, cols{static_cast<int>(grid[0].size())};
	vector<vector<int>> table(rows+1, vector<int>(cols+1, 0));

	for(int r{rows-1}; r >= 0; --r)
	{
		for(int c{cols-1}; c >= 0; --c)
			table[r][c] = grid[r][c] + max(table[r+1][c], table[r][c+1]);
	}
	
	return table;
}

vector<int> dynamic_prog::getPath(const vector<vector<int>>& grid, const vector<vector<int>>& table)
{
	vector<int> path;

	for(size_t r{0}, c{0}; r != grid.size() && c != grid[0].size(); )
	{
		path.push_back(grid[r][c]);
		table[r+1][c] > table[r][c+1] ? ++r : ++c;
	}

	return path;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int dynamic_prog::coinChange(const vector<int>& coins, int total)
{
	vector<int> table(total+1, INT_MAX-1);
	table[0] = 0;

	for(int amt{1}; amt <= total; ++amt)
	{
		for(size_t j{0}; j < coins.size(); ++j)
		{
			if(amt < coins[j])
				continue;

			table[amt] = std::min(table[amt], table[amt - coins[j]] + 1); 
		}
	}
	return table[total];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int dynamic_prog::maxPrice(const vector<int>& prices, int len)
{
	vector<int> table(len+1, 0);

	for(int l{1}; l <= len; ++l)
	{
		int maxP{0};
		for(int i{1}; i <= l; ++i)
			maxP = max(prices[i-1] + table[l-i], maxP);
		table[l] = maxP;
	}
	return table[len];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool dynamic_prog::halfgroup(const vector<int>& vals)
{
	int sum{std::accumulate(vals.begin(), vals.end(), 0)};
	if(sum % 2)return false;

	sum /=2;

	int len{static_cast<int>(vals.size())};

	vector<vector<bool>> table(len+1, vector<bool>(sum+1, false));
	for(auto& v : table)
		v[0] = true;

	bool res{false};
	for(int i = len-1; i >= 0; --i)
	{
		for(int j{1}; j <= sum; ++j)
		{
			if(j - vals[i-1] >= 0)
				res = table[i+1][j-vals[i-1]];

			table[i][j] = res || table[i+1][j];
		}
	}
	return table[0][sum];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int dynamic_prog::editDistance(const string& s1, const string& s2)
{
	int rows{static_cast<int>(s1.size())};
	int cols{static_cast<int>(s2.size())};
	
	vector<vector<int>> table(rows+1, vector<int>(cols+1, 0));

	for(int i{rows}; i >= 0; --i)
		table[i][cols] = rows - i; 

	for(int j{cols}; j >= 0; --j)
		table[rows][j] = cols - j;

	for(int i{rows-1}; i >= 0; --i)
	{
		for(int j{cols-1}; j >=0; --j)
		{
			if(s1[i] == s2[j]) 
				table[i][j] = table[i+1][j+1];
			else
				table[i][j] = 1 + min(min(table[i][j+1], table[i+1][j]), table[i+1][j+1]);
		}
	}

	return table[0][0];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int dynamic_prog::coinPlay(const vector<int>& coins)
{
	vector<vector<int>> dp{vector(coins.size(), vector(coins.size(), 0))};

	for(size_t k{0}; k < coins.size(); ++k)
	{
		for(size_t i{0}, j{k}; j < coins.size(); ++j, ++i)
		{
			int x{i+2 <= j ? dp[i+2][j] : 0};
			int y{i+1 <= j-1 ? dp[i+1][j-1] : 0};
			int z{i <= j-2 ? dp[i][j-2] : 0};

			dp[i][j] = max(coins[i] + min(x,y), coins[j] + min(y, z));
		}
	}

	return dp[0][coins.size()-1];
}
