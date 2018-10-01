#include "nQueens.h"

vector<vector<string>> recursion::nQueens(int n)
{
	vector<vector<int>> queens;
	vector<int> q(n, -1);
	nQueens(queens, q, 0);
	return createQueensOutput(queens);
}

void recursion::nQueens(vector<vector<int>>& queens, vector<int>& q, int col)
{
	int n{static_cast<int>(q.size())};

	if(col == n)
	{
		queens.push_back(q);
		return;
	}

	for(int row{0}; row < n; ++row)
	{
		q[col] = row;

		if(isValid(q, col))
			nQueens(queens, q, col+1);
	}
}

bool recursion::isValid(const vector<int>& q, int col)
{
	for(int i{0}; i < col; ++i)
	{
		if(q[i] == q[col])
			return false;

		if(col - i == abs(q[col] - q[i]))
			return false;
	}

	return true;
}

vector<vector<string>> recursion::createQueensOutput(const vector<vector<int>>& queens)
{
	vector<vector<string>> res;
	
	for(const auto& board : queens)
	{
		vector<string> outBoard;
		for(size_t i{0}; i < board.size(); i++)
		{
			string row(board.size(), '-');
			row[board[i]] = 'q';
			outBoard.push_back(row);
		}
		res.push_back(outBoard);
	}
	return res;
}
