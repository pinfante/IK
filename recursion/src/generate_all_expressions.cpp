#include "generate_all_expressions.h"
#include<iostream>
#include<stack>
#include<sstream>
#include<algorithm>
#include <boost/algorithm/string.hpp>
#include <numeric>

vector<string> GenExpressions::generateAllExpressions(const string& s, long long int target)
{
	string subStr{s[0]};
	vector<string> expressions;
	generateExpression(s, 1, subStr, expressions);
	return evaluateExpressions(expressions, target);
}

void GenExpressions::generateExpression(const string& s, size_t i, string& expr, vector<string>& expressions)
{
	if(i == s.size())
	{
		expressions.push_back(expr);
		return;
	}

	addExpression(s, i, expr, expressions);
	addExpression(s, i, expr, expressions, '+');
	addExpression(s, i, expr, expressions, '*');
}

void GenExpressions::addExpression(const string& s, size_t i, string& subStr, vector<string>& v)
{
	subStr.push_back(s[i]);
	generateExpression(s, i+1, subStr, v);
	subStr.pop_back();
}

void GenExpressions::addExpression(const string& s, size_t i, string& subStr, vector<string>& v, char op)
{
	subStr += op;
	subStr += s[i];
	generateExpression(s, i+1, subStr, v);
	subStr.pop_back();
	subStr.pop_back();
}

vector<string> GenExpressions::evaluateExpressions(const vector<string>& expressions, int target)
{
	vector<string> res;
	for(const auto& s : expressions)
	{
		auto val{evaluateExpr(s)};
		if(val == target)
			res.push_back(s);
	}
	return res;
}

long long GenExpressions::evaluateExpr(const string& s)
{
	long long res{0};
	vector<string> additions;
	boost::split(additions, s, [](char c){return c == '+';});

	for(auto& add : additions)
	{
		vector<string> multiply;
		boost::split(multiply, add, [](char c){return c == '*';});
		long long m{1};
		for_each(multiply.begin(), multiply.end(), [&m](const string& x1)
		{
			m *= stoll(x1);
		});
		res += m;
	}

	return res;
}
