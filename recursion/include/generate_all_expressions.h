#ifndef _GENERATE_ALL_EXPRESSIONS_H_ 
#define _GENERATE_ALL_EXPRESSIONS_H_

#include<string>
#include<vector>

using std::string;
using std::vector;

class GenExpressions
{
	public:
		vector<string> generateAllExpressions(const string& s, long long target);

		void generateExpression(const string& s, size_t i, string& expr, vector<string>& expressions);

		void addExpression(const string& s, size_t i, string& subStr, vector<string>& v);
		void addExpression(const string& s, size_t i, string& subStr, vector<string>& v, char op);

		vector<string> evaluateExpressions(const vector<string>& expressions, int target);
		long long evaluateExpr(const string& s);
};

#endif //_GENERATE_ALL_EXPRESSIONS_H_
