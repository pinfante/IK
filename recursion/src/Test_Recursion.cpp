#include "gmock/gmock.h"
#include "recursion.h"
#include "generate_all_expressions.h"
#include "nQueens.h"
#include "diameter_of_a_tree.h"
#include <iostream>

using std::cout;
using std::endl;

using namespace testing;
using namespace recursion;

class Test_Recursion : public Test
{
	public:

};

TEST_F(Test_Recursion, allPermutions)
{
	string s{"abc"};
	auto res{allPermutions(s)};
	ASSERT_THAT(res.size(), Eq(6));
	EXPECT_THAT(res[0], Eq("abc"));
	EXPECT_THAT(res[1], Eq("acb"));
	EXPECT_THAT(res[2], Eq("bac"));
	EXPECT_THAT(res[3], Eq("bca"));
	EXPECT_THAT(res[4], Eq("cba"));
	EXPECT_THAT(res[5], Eq("cab"));

	s = "bcef";
	res = allPermutions(s);
	ASSERT_THAT(res.size(), Eq(24));
	EXPECT_THAT(res[0], Eq("bcef"));
	EXPECT_THAT(res[1], Eq("bcfe"));
	EXPECT_THAT(res[2], Eq("becf"));
	EXPECT_THAT(res[3], Eq("befc"));
	EXPECT_THAT(res[4], Eq("bfec"));
	EXPECT_THAT(res[5], Eq("bfce"));
	EXPECT_THAT(res[6], Eq("cbef"));
	EXPECT_THAT(res[7], Eq("cbfe"));
	EXPECT_THAT(res[8], Eq("cebf"));
	EXPECT_THAT(res[9], Eq("cefb"));
	EXPECT_THAT(res[10], Eq("cfeb"));
	EXPECT_THAT(res[11], Eq("cfbe"));
	EXPECT_THAT(res[12], Eq("ecbf"));
	EXPECT_THAT(res[13], Eq("ecfb"));
	EXPECT_THAT(res[14], Eq("ebcf"));
	EXPECT_THAT(res[15], Eq("ebfc"));
	EXPECT_THAT(res[16], Eq("efbc"));
	EXPECT_THAT(res[17], Eq("efcb"));
	EXPECT_THAT(res[18], Eq("fceb"));
	EXPECT_THAT(res[19], Eq("fcbe"));
	EXPECT_THAT(res[20], Eq("fecb"));
	EXPECT_THAT(res[21], Eq("febc"));
	EXPECT_THAT(res[22], Eq("fbec"));
	EXPECT_THAT(res[23], Eq("fbce"));
}

TEST_F(Test_Recursion, printSubSet)
{
	string str{"tcdo"};
	string s;
	auto res{allSubSet(str)};
	ASSERT_THAT(res.size(), Eq(16));
	EXPECT_THAT(res[0], Eq(""));
	EXPECT_THAT(res[1], Eq("o"));
	EXPECT_THAT(res[2], Eq("d"));
	EXPECT_THAT(res[3], Eq("do"));
	EXPECT_THAT(res[4], Eq("c"));
	EXPECT_THAT(res[5], Eq("co"));
	EXPECT_THAT(res[6], Eq("cd"));
	EXPECT_THAT(res[7], Eq("cdo"));
	EXPECT_THAT(res[8], Eq("t"));
	EXPECT_THAT(res[9], Eq("to"));
	EXPECT_THAT(res[10], Eq("td"));
	EXPECT_THAT(res[11], Eq("tdo"));
	EXPECT_THAT(res[12], Eq("tc"));
	EXPECT_THAT(res[13], Eq("tco"));
	EXPECT_THAT(res[14], Eq("tcd"));
	EXPECT_THAT(res[15], Eq("tcdo"));
}

TEST_F(Test_Recursion, countPaths)
{
	EXPECT_THAT(countPaths(vector<vector<char>>{{0,0,0,0}, {0,0,0,0}, {0,0,0,0}}), Eq(10));
	EXPECT_THAT(countPaths(vector<vector<char>>{{'.','.','.'}, {'.','*','.'}, {'.','.','.'}}), Eq(2));
	EXPECT_THAT(countPaths(vector<vector<char>>{{'.','.','.'}, {'.','.','*'}, {'.','.','.'}}), Eq(3));
}

TEST_F(Test_Recursion, isSumInSubSet)
{
	EXPECT_THAT(isSumInSubSet(vector<int>{1,2,3}, 0), Eq(false));
	EXPECT_THAT(isSumInSubSet(vector<int>{1,2,3}, 10), Eq(false));
	EXPECT_THAT(isSumInSubSet(vector<int>{1,2,3}, 3), Eq(true));
	EXPECT_THAT(isSumInSubSet(vector<int>{1,2,3}, 6), Eq(true));
	EXPECT_THAT(isSumInSubSet(vector<int>{1,2,3,10,20,30}, 66), Eq(true));
	EXPECT_THAT(isSumInSubSet(vector<int>{10,20}, 0), Eq(false));
	EXPECT_THAT(isSumInSubSet(vector<int>{1,2,3,4,5}, 5), Eq(true));
	EXPECT_THAT(isSumInSubSet(vector<int>{1,2,3,10,20,30}, 66), Eq(true));
}

TEST_F(Test_Recursion, KthSumSubSet)
{
	EXPECT_THAT(KthSumSubSet(vector<int>{1,2,3}, 10), Eq(0));
	EXPECT_THAT(KthSumSubSet(vector<int>{1,2,3}, 3), Eq(2));
	EXPECT_THAT(KthSumSubSet(vector<int>{1,2,3}, 6), Eq(1));
	EXPECT_THAT(KthSumSubSet(vector<int>{1,2,3,10,20,30}, 66), Eq(1));
	EXPECT_THAT(KthSumSubSet(vector<int>{1,2,3,4,5}, 5), Eq(3));
	EXPECT_THAT(KthSumSubSet(vector<int>{1,2,3,6,8,10,20,22,30,36,44,54,65}, 66), Eq(23));
}

TEST_F(Test_Recursion, numOfSumInSubSet)
{
	EXPECT_THAT(numOfSumInSubSet(vector<int>{1,2,3}, 1), Eq(1));
	EXPECT_THAT(numOfSumInSubSet(vector<int>{4,9,5}, 9), Eq(2));
	EXPECT_THAT(numOfSumInSubSet(vector<int>{1,2,3}, 3), Eq(2));
	EXPECT_THAT(numOfSumInSubSet(vector<int>{1,2,3,6,5,-6}, 6), Eq(5));
}

TEST_F(Test_Recursion, check_if_sum_possible)
{
	EXPECT_THAT(check_if_sum_possible(vector<long long>{1,0}, 0), Eq(true));
	EXPECT_THAT(check_if_sum_possible(vector<long long>{1,1}, 0), Eq(false));
	EXPECT_THAT(check_if_sum_possible(vector<long long>{1,2,3}, 1), Eq(true));
	EXPECT_THAT(check_if_sum_possible(vector<long long>{4,2,5}, 9), Eq(true));
	EXPECT_THAT(check_if_sum_possible(vector<long long>{1,2,3}, 6), Eq(true));
	EXPECT_THAT(check_if_sum_possible(vector<long long>{1,2,3,6,5}, 16), Eq(true));
	EXPECT_THAT(check_if_sum_possible(vector<long long>{1,2,3,6,5}, 18), Eq(false));
	EXPECT_THAT(check_if_sum_possible(vector<long long>{2,-10,10}, 0), Eq(true));

}

TEST_F(Test_Recursion, find_well_formed_brackets)
{
	auto v{find_well_formed_brackets(2)};
	ASSERT_THAT(v.empty(), Eq(false));
	ASSERT_THAT(v.size(), Eq(2));
	EXPECT_THAT(v[0], Eq("(())"));
	EXPECT_THAT(v[1], Eq("()()"));

	v = find_well_formed_brackets(3);
	ASSERT_THAT(v.empty(), Eq(false));
	ASSERT_THAT(v.size(), Eq(5));
	EXPECT_THAT(v[0], Eq("((()))"));
	EXPECT_THAT(v[1], Eq("(()())"));
	EXPECT_THAT(v[2], Eq("(())()"));
	EXPECT_THAT(v[3], Eq("()(())"));
	EXPECT_THAT(v[4], Eq("()()()"));
}

TEST_F(Test_Recursion, generate_all_subsets)
{
	auto v{generate_all_subsets("xy")};
	ASSERT_THAT(v.empty(), Eq(false));
	EXPECT_THAT(v[0], StrEq(""));
	EXPECT_THAT(v[1], StrEq("y"));
	EXPECT_THAT(v[2], StrEq("x"));
	EXPECT_THAT(v[3], StrEq("xy"));

	v = generate_all_subsets("a");
	ASSERT_THAT(v.size(), Eq(2));
	EXPECT_THAT(v[0], StrEq(""));
	EXPECT_THAT(v[1], StrEq("a"));
}

TEST_F(Test_Recursion, how_many_BSTs)
{
	EXPECT_THAT(how_many_BSTs(0), Eq(1));
	EXPECT_THAT(how_many_BSTs(1), Eq(1));
	EXPECT_THAT(how_many_BSTs(2), Eq(2));
	EXPECT_THAT(how_many_BSTs(3), Eq(5));
	EXPECT_THAT(how_many_BSTs(4), Eq(14));
	EXPECT_THAT(how_many_BSTs(5), Eq(42));
}

TEST_F(Test_Recursion, generateExpression)
{
	string s{"123"};
	string expr{s[0]};
	vector<string> expressions;
	vector<string> expected{"123", "12+3", "12*3", "1+23", "1+2+3", "1+2*3", "1*23", "1*2+3", "1*2*3"};
	
	GenExpressions gexpr;
	gexpr.generateExpression(s, 1, expr, expressions);
	EXPECT_THAT(expressions, Eq(expected));
}

TEST_F(Test_Recursion, generate_all_expressions)
{
	vector<string> v;
	string s{"123"};
	auto res{generate_all_expressions(s, 5)};
	ASSERT_THAT(res.size(), Eq(1));
	EXPECT_THAT(res[0], Eq("1*2+3"));
	res = generate_all_expressions(s, 15);
	ASSERT_THAT(res.size(), Eq(1));
	EXPECT_THAT(res[0], Eq("12+3"));

	s = "410896";
	res = generate_all_expressions(s, 416);
	EXPECT_THAT(res.size(), Eq(1));
	EXPECT_THAT(res[0], Eq("4*10*8+96"));

//	s = "6666666666666";	
//	res = generate_all_expressions(s, 6);
//	EXPECT_THAT(res.size(), Eq(0));
//
//	s = "8758115277303";
//	res = generate_all_expressions(s, 87);
//	EXPECT_THAT(res.size(), Eq(387));
//
//	s = "8765942351445";
//	res = generate_all_expressions(s, 8765);
//	EXPECT_THAT(res.size(), Eq(4));
//	EXPECT_THAT(res[0], Eq("87+6594+23+514*4+5"));
//	EXPECT_THAT(res[1], Eq("8+7+6*5*9+423*5*1*4+4*5"));
//	EXPECT_THAT(res[2], Eq("8+7*6*5*9*4+23*51+4+4*5"));
//	EXPECT_THAT(res[3], Eq("8*7+6*59*4*2*3+51*4+4+5"));
}

TEST_F(Test_Recursion, evaluateExpr)
{
	GenExpressions gexpr;
	EXPECT_THAT(gexpr.evaluateExpr("1+2+3"), Eq(6));
	EXPECT_THAT(gexpr.evaluateExpr("1+2*3"), Eq(7));
	EXPECT_THAT(gexpr.evaluateExpr("1*2*3"), Eq(6));
	EXPECT_THAT(gexpr.evaluateExpr("12+3"), Eq(15));
	EXPECT_THAT(gexpr.evaluateExpr("123"), Eq(123));
	EXPECT_THAT(gexpr.evaluateExpr("123*6+4*2+3"), Eq(749));
}

TEST_F(Test_Recursion, createQueensOutput)
{
	vector<vector<int>> queens{{2,0,3,1}, {1,3,0,2}};
	auto res{createQueensOutput(queens)};
	vector<vector<string>> expected{{"--q-","q---","---q","-q--"}, {"-q--","---q","q---","--q-"}};
	EXPECT_THAT(res, Eq(expected));
}

TEST_F(Test_Recursion, find_all_arrangements)
{
	vector<vector<string>> expected{{"-q--","---q","q---","--q-"},{"--q-","q---","---q","-q--"}};
	EXPECT_THAT(find_all_arrangements(4), Eq(expected));
}

TEST_F(Test_Recursion, find_all_possibilities)
{
	string s{"10?"};
	EXPECT_THAT(find_all_possibilities(s), Eq(vector<string>{"100", "101"}));
	s = "1?0?";
	EXPECT_THAT(find_all_possibilities(s), Eq(vector<string>{"1000", "1001", "1100", "1101"})); 
}

TEST_F(Test_Recursion, pow)
{
	EXPECT_THAT(pow(10.0, 3), DoubleEq(1000.0));
	EXPECT_DOUBLE_EQ(0.010973936899862825, pow(4.5, -3));
} 

TEST_F(Test_Recursion, diamterOfTree)
{
	EXPECT_THAT(TreeDiameter{"{0,3,{1,2,{5,0},{7,0}},{1,2,{6,0},{5,0}},{1,2,{10,0},{9,0}}}"}.diamterOfTree(), Eq(19));
	EXPECT_THAT(TreeDiameter{"{0,3,{5,2,{8,0},{7,0}},{5,2,{9,0},{8,0}},{5,2,{10,0},{9,0}}"}.diamterOfTree(), Eq(29));
}



