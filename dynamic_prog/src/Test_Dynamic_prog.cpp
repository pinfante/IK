#include "gmock/gmock.h"
#include "dynamic_prog.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using std::cout;
using std::endl;
using namespace dynamic_prog;

using namespace testing;

TEST(Test_Dynamic_prog, maxPath)
{
	auto grid{vector<vector<int>>{{5,8,9},{12,2,3},{16,23,1}}};
	auto table{maxPath(grid)};
	EXPECT_THAT(table[0][0], Eq(57));

	auto path{getPath(grid, table)};
	ASSERT_THAT(path.empty(), Eq(false));
	EXPECT_THAT(path.size(), Eq(5));
	EXPECT_THAT(path[0], Eq(5));
	EXPECT_THAT(path[1], Eq(12));
	EXPECT_THAT(path[2], Eq(16));
	EXPECT_THAT(path[3], Eq(23));
	EXPECT_THAT(path[4], Eq(1));

	grid.push_back(vector<int>{10,33,66});
	grid.push_back(vector<int>{13,5,1});
	table = maxPath(grid);
	EXPECT_THAT(table[0][0], Eq(156));
}

TEST(Test_Dynamic_prog, CoinChange)
{
	vector<int> coins{2,3,5};
	EXPECT_THAT(coinChange(coins, 8), Eq(2));

	coins = vector<int>{1,5,10,25};
	EXPECT_THAT(coinChange(coins, 15), Eq(2));

	coins = vector<int>{1,5,10,20,25};
	EXPECT_THAT(coinChange(coins, 40), Eq(2));
}

TEST(Test_Dynamic_prog, MaxPrice)
{
	vector<int> prices{2,3,4,9,10};
	EXPECT_THAT(maxPrice(prices, 1), Eq(2));
	EXPECT_THAT(maxPrice(prices, 3), Eq(6));
	EXPECT_THAT(maxPrice(prices, 4), Eq(9));
	EXPECT_THAT(maxPrice(prices, 5), Eq(11));
}

TEST(Test_Dynamic_prog, Halfgroup)
{
	EXPECT_THAT(halfgroup(vector<int>{1,2,3}), Eq(true));
	EXPECT_THAT(halfgroup(vector<int>{2,4,8,10,12,12}), Eq(true));
	EXPECT_THAT(halfgroup(vector<int>{2,4,8,10,12,13}), Eq(false));
	EXPECT_THAT(halfgroup(vector<int>{1,1,5,10,2,2,13}), Eq(true));
}

TEST(Test_Dynamic_prog, EditDistance)
{
	EXPECT_THAT(editDistance("boy", "boy"), Eq(0));
	EXPECT_THAT(editDistance("boy", "boyz"), Eq(1));
	EXPECT_THAT(editDistance("boil", "boy"), Eq(2));
	EXPECT_THAT(editDistance("apple", "peach"), Eq(5));
	
}

TEST(Test_Dynamic_prog, CoinPlay)
{
	EXPECT_THAT(coinPlay(vector{8,15,3,7}), Eq(22));
	EXPECT_THAT(coinPlay(vector{6,9,1,2,16,8}), Eq(23));
//	EXPECT_THAT(coinPlay(vector{149,154,63,242,12,72,65}), Eq(294));
}
