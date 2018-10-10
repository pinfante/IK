#include "gmock/gmock.h"
#include "recursion.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using std::cout;
using std::endl;

using namespace testing;
using namespace recursion;

TEST(Test_Recursion, maxPathValue)
{
	auto grid{vector<vector<int>>{{5,8,9},{12,2,3},{16,23,1}}};
	EXPECT_THAT(maxPathValue(grid), Eq(57));
}

TEST(Test_Recursion, maxPath)
{
	auto grid{vector<vector<int>>{{5,8,9},{12,2,3},{16,23,1}}};
	auto res{maxPath(grid)};
	ASSERT_THAT(res.empty(), Eq(false));
	EXPECT_THAT(res.size(), Eq(5));
	EXPECT_THAT(res[0], Eq(5));
	EXPECT_THAT(res[1], Eq(12));
	EXPECT_THAT(res[2], Eq(16));
	EXPECT_THAT(res[3], Eq(23));
	EXPECT_THAT(res[4], Eq(1));

	auto maxVal{std::accumulate(res.begin(), res.end(), 0)};
	EXPECT_THAT(maxVal, Eq(57));
}

TEST(Test_Recursion, coinChange)
{
	vector<int> coins{2,3,5};
	EXPECT_THAT(coinChange(coins, 8), Eq(2));

	coins = vector<int>{5,10,25};
	EXPECT_THAT(coinChange(coins, 100), Eq(4));
	
	coins = vector<int>{1,5,10,20,25};
	EXPECT_THAT(coinChange(coins, 40), Eq(2));
}

TEST(Test_Recursion, maxPrice)
{
	vector<int>prices{2,3,4};
	EXPECT_THAT(maxPrice(prices, 3), Eq(6));
	EXPECT_THAT(maxPrice(prices, 6), Eq(12));
	prices.push_back(7);
	prices.push_back(9);
	EXPECT_THAT(maxPrice(prices, 10), Eq(20));

}

TEST(Test_Recursion, halfgroup)
{
	EXPECT_THAT(halfgroup(vector<int>{2,4,8,10,12,12}), Eq(true));
	EXPECT_THAT(halfgroup(vector<int>{2,4,8,10,12,13}), Eq(false));
	EXPECT_THAT(halfgroup(vector<int>{1,1,5,10,2,2,13}), Eq(true));
}

TEST(Test_Recursion, editDistance)
{
	EXPECT_THAT(editDistance("boy", "boy"), Eq(0));
	EXPECT_THAT(editDistance("boy", "boyz"), Eq(1));
	EXPECT_THAT(editDistance("boil", "boy"), Eq(2));
	EXPECT_THAT(editDistance("apple", "peach"), Eq(5));
}

TEST(Test_Recursion, longestCommonSubsequence)
{
	EXPECT_THAT(longestCommonSubsequence("", "ABCA"), Eq(0));
	EXPECT_THAT(longestCommonSubsequence("ABC", "ABCA"), Eq(3));
	EXPECT_THAT(longestCommonSubsequence("ABABC", "BABCA"), Eq(4));
	EXPECT_THAT(longestCommonSubsequence("DFGHI", "ABCA"), Eq(0));
	EXPECT_THAT(longestCommonSubsequence("acbaed", "abcadf"), Eq(4));
}

TEST(Test_Recursion, max_product_from_cut_pieces)
{
	EXPECT_THAT(max_product_from_cut_pieces(4), Eq(4));
}

TEST(Test_Recursion, numberOfPaths)
{
	auto grid{vector<vector<int>>{{1,1,1,1},{1,1,1,1},{1,1,1,1}}};
	//EXPECT_THAT(numberOfPaths(grid), Eq(10));
}
