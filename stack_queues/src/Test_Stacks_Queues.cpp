#include "gmock/gmock.h"
#include "stacks_Queues.h"
#include <string>
#include <vector>

using std::vector;
using std::string;
using namespace testing;

class Test_stacks_Queues : public Test
{
	public:
};

TEST_F(Test_stacks_Queues, brackets1)
{
	string brackets{"((((())(((()"};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(4));
}

TEST_F(Test_stacks_Queues, brackets2)
{
	string brackets{"()()()"};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(6));
}

TEST_F(Test_stacks_Queues, brackets3)
{
	string brackets{"("};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(0));
}

TEST_F(Test_stacks_Queues, brackets4)
{
	string brackets{")"};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(0));
}

TEST_F(Test_stacks_Queues, brackets5)
{
	string brackets{"()"};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(2));
}

TEST_F(Test_stacks_Queues, brackets6)
{
	string brackets{"(("};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(0));
}

TEST_F(Test_stacks_Queues, brackets7)
{
	string brackets{"))"};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(0));
}

TEST_F(Test_stacks_Queues, brackets8)
{
	string brackets{"((("};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(0));
}

TEST_F(Test_stacks_Queues, brackets9)
{
	string brackets{"()("};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(2));
}

TEST_F(Test_stacks_Queues, brackets10)
{
	string brackets{"())"};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(2));
}


TEST_F(Test_stacks_Queues, brackets20)
{
	string brackets{"()((()))()((()))"};
	EXPECT_THAT(stacks_Queues::find_max_length_of_matching_parentheses(brackets), Eq(16));
}

TEST_F(Test_stacks_Queues, max_in_sliding_window)
{
	auto res{stacks_Queues::max_in_sliding_window(vector<int>{1,3,-1,-3,5,3,6,7}, 3)};
	ASSERT_THAT(res.size(), Eq(6));
	EXPECT_THAT(res[0], 3);
	EXPECT_THAT(res[1], 3);
	EXPECT_THAT(res[2], 5);
	EXPECT_THAT(res[3], 5);
	EXPECT_THAT(res[4], 6);
	EXPECT_THAT(res[5], 7);
}

