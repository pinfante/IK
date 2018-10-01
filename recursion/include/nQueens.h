#ifndef _NQUEENS_H_ 
#define _NQUEENS_H_

#include<string>
#include<vector>

using std::string;
using std::vector;

namespace recursion
{
	//HW #3
	vector<vector<string>> nQueens(int n);

	void nQueens(vector<vector<int>>& queens, vector<int>& q, int i);

	bool isValid(const vector<int>& q, int s);

	vector<vector<string>> createQueensOutput(const vector<vector<int>>& queens);
}

#endif //NQUEENS
