#include "gmock/gmock.h"
#include "sorting.h"
#include <vector>

using std::vector;

using namespace testing;

class Test_Sorting : public Test
{
	public:

};

TEST_F(Test_Sorting, QuickSort)
{
	vector<int> arr{20,5,3,11,1,25,33,6,2,0,-11,19};
	sorting::quickSort(arr);
	EXPECT_THAT(arr.size(), Eq(12));
	EXPECT_THAT(arr[0], Eq(-11));
	EXPECT_THAT(arr[1], Eq(0));
	EXPECT_THAT(arr[2], Eq(1));
	EXPECT_THAT(arr[3], Eq(2));
	EXPECT_THAT(arr[4], Eq(3));
	EXPECT_THAT(arr[5], Eq(5));
	EXPECT_THAT(arr[6], Eq(6));
	EXPECT_THAT(arr[7], Eq(11));
	EXPECT_THAT(arr[8], Eq(19));
	EXPECT_THAT(arr[9], Eq(20));
	EXPECT_THAT(arr[10], Eq(25));
	EXPECT_THAT(arr[11], Eq(33));
}

TEST_F(Test_Sorting, mergeSort)
{
	vector<int> arr{20,5,3,11,1,25,33,6,2,0,-11,19};
	sorting::mergeSort(arr);
	EXPECT_THAT(arr.size(), Eq(12));
	EXPECT_THAT(arr[0], Eq(-11));
	EXPECT_THAT(arr[1], Eq(0));
	EXPECT_THAT(arr[2], Eq(1));
	EXPECT_THAT(arr[3], Eq(2));
	EXPECT_THAT(arr[4], Eq(3));
	EXPECT_THAT(arr[5], Eq(5));
	EXPECT_THAT(arr[6], Eq(6));
	EXPECT_THAT(arr[7], Eq(11));
	EXPECT_THAT(arr[8], Eq(19));
	EXPECT_THAT(arr[9], Eq(20));
	EXPECT_THAT(arr[10], Eq(25));
	EXPECT_THAT(arr[11], Eq(33));
}

TEST_F(Test_Sorting, emptyArr)
{
	auto v{sorting::mergeArrays({vector<int>{}, vector<int>{}})};
	ASSERT_THAT(v.empty(), Eq(true));
}

TEST_F(Test_Sorting, twoArrSameSize)
{
	auto v{sorting::mergeArrays({vector<int>{1,8,18}, vector<int>{2,5,25}})};
	ASSERT_THAT(v.empty(), Eq(false));
	ASSERT_THAT(v.size(), Eq(6));
	EXPECT_THAT(v[0], Eq(1));
	EXPECT_THAT(v[1], Eq(2));
	EXPECT_THAT(v[2], Eq(5));
	EXPECT_THAT(v[3], Eq(8));
	EXPECT_THAT(v[4], Eq(18));
	EXPECT_THAT(v[5], Eq(25));
}

TEST_F(Test_Sorting, twoArrDiffSize)
{
	auto v{sorting::mergeArrays({vector<int>{1,8,18}, vector<int>{2,5}})};
	ASSERT_THAT(v.empty(), Eq(false));
	ASSERT_THAT(v.size(), Eq(5));
	EXPECT_THAT(v[0], Eq(1));
	EXPECT_THAT(v[1], Eq(2));
	EXPECT_THAT(v[2], Eq(5));
	EXPECT_THAT(v[3], Eq(8));
	EXPECT_THAT(v[4], Eq(18));
}

TEST_F(Test_Sorting, fiveArrsDiffSize)
{
	auto v{sorting::mergeArrays({{vector<int>{1,10,18}}, {vector<int>{4,8,18,22}}, {vector<int>{7,12,29,29,29,29,29,29,54}},
						{vector<int>{3,15,18,54,55}}, {vector<int>{2,25,66,100,111,201,312}}})};

	ASSERT_THAT(v.empty(), Eq(false));
	ASSERT_THAT(v.size(), Eq(28));
	EXPECT_THAT(v[0], Eq(1));
	EXPECT_THAT(v[1], Eq(2));
	EXPECT_THAT(v[2], Eq(3));
	EXPECT_THAT(v[3], Eq(4));
	EXPECT_THAT(v[4], Eq(7));
	EXPECT_THAT(v[5], Eq(8));
	EXPECT_THAT(v[6], Eq(10));
	EXPECT_THAT(v[7], Eq(12));
	EXPECT_THAT(v[8], Eq(15));
	EXPECT_THAT(v[9], Eq(18));
	EXPECT_THAT(v[10], Eq(18));
	EXPECT_THAT(v[11], Eq(18));
	EXPECT_THAT(v[12], Eq(22));
	EXPECT_THAT(v[13], Eq(25));
	EXPECT_THAT(v[14], Eq(29));
	EXPECT_THAT(v[15], Eq(29));
	EXPECT_THAT(v[16], Eq(29));
	EXPECT_THAT(v[17], Eq(29));
	EXPECT_THAT(v[18], Eq(29));
	EXPECT_THAT(v[19], Eq(29));
	EXPECT_THAT(v[20], Eq(54));
	EXPECT_THAT(v[21], Eq(54));
	EXPECT_THAT(v[22], Eq(55));
	EXPECT_THAT(v[23], Eq(66));
	EXPECT_THAT(v[24], Eq(100));
	EXPECT_THAT(v[25], Eq(111));
	EXPECT_THAT(v[26], Eq(201));
	EXPECT_THAT(v[27], Eq(312));
}

TEST_F(Test_Sorting, merger_first_into_second)
{
	auto r{sorting::merger_first_into_second(vector<int>{2,5,8}, vector<int>{1,6,9, 0, 0, 0})};
	ASSERT_THAT(r.empty(), Eq(false));
	ASSERT_THAT(r.size(), Eq(6));
	EXPECT_THAT(r[0], Eq(1));
	EXPECT_THAT(r[1], Eq(2));
	EXPECT_THAT(r[2], Eq(5));
	EXPECT_THAT(r[3], Eq(6));
	EXPECT_THAT(r[4], Eq(8));
	EXPECT_THAT(r[5], Eq(9));
}

TEST_F(Test_Sorting, dutch_flag_sort)
{
	EXPECT_THAT(sorting::dutch_flag_sort("BGBGRGBRR"), StrEq("RRRGGGBBB"));
	EXPECT_THAT(sorting::dutch_flag_sort("GBGBGRGBRRGBGRG"), StrEq("RRRRGGGGGGGBBBB"));
	EXPECT_THAT(sorting::dutch_flag_sort("RB"), StrEq("RB"));
	EXPECT_THAT(sorting::dutch_flag_sort("GBGGRBRG"),StrEq("RRGGGGBB")); 
	EXPECT_THAT(sorting::dutch_flag_sort("GRB"), StrEq("RGB"));
	EXPECT_THAT(sorting::dutch_flag_sort("BGR"), StrEq("RGB"));
	EXPECT_THAT(sorting::dutch_flag_sort("BB"), StrEq("BB"));

}

