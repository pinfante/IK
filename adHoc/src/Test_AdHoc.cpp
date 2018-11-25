#include "gmock/gmock.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include "adHoc.h"

using std::string;
using namespace testing;
using namespace AdHoc;

TEST(TestAddHoc, getProductArray)
{
	auto res{getProductArray(vector<int>{1,2,3,4,5})};
	EXPECT_THAT(res, Eq(vector<int>{120,60,40,30,24}));
}

TEST(TestAddHoc, getMergedIntervals)
{
	auto input{vector<vector<int>>{{1,3,},{5,7},{2,4},{6,8}}};
	auto res{getMergedIntervals(input)};
	ASSERT_THAT(res.size(), Eq(2));
	EXPECT_THAT(res[0], Eq(vector<int>{1,4}));
	EXPECT_THAT(res[1], Eq(vector<int>{5,8}));

	input = vector<vector<int>>{{10,12},{1,2},{1000,100000},{-1000000000,1000000000},{2,5},{7,10},{123,456}};
	res = getMergedIntervals(input);
	ASSERT_THAT(res.size(), Eq(1));
	EXPECT_THAT(res[0], Eq(vector<int>{-1000000000,1000000000}));
}

TEST(TestAddHoc, isPresent)
{
	const auto arr{vector<vector<int>>{{1,2,3,12}, vector<int>{4,5,6,45}, vector<int>{7,8,9,78}}};
	EXPECT_THAT(isPresent(arr, 6), Eq("present"));
}

TEST(TestAddHoc, findMaxPossibleArea)
{
	EXPECT_THAT(16, Eq(findMaxPossibleArea(vector<long long>{2,4,6,5,8}, 0, 4)));
	EXPECT_THAT(5, Eq(findMaxPossibleArea(vector<long long>{2,4,6,5,8}, 3, 3)));
	EXPECT_THAT(12, Eq(findMaxPossibleArea(vector<long long>{6,2,5,4,5,1,6}, 0, 6)));
}

TEST(TestAddHoc, sumZero)
{
	auto res{sumZero(vector<int>{1,2,3,0,-9})};
	ASSERT_THAT(res.size(), Eq(2));
	EXPECT_THAT(res[0], Eq(3));
	EXPECT_THAT(res[1], Eq(3));

	res = sumZero(vector<int>{5,1,2,-3,7,-4});
	EXPECT_THAT(res[0], Eq(1));
	EXPECT_THAT(res[1], Eq(3));

}

TEST(TestAddHoc, detect_primes)
{
	EXPECT_THAT(detect_primes(vector<int>{6,2,5,8}), Eq("0110"));
}
