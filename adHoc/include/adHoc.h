#ifndef __AD_HOC_H__
#define __AD_HOC_H__

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace AdHoc
{
	//HW #1
	vector<int> getProductArray(const vector<int>& nums);
	
	//HW #2
	vector<vector<int>> getMergedIntervals(vector<vector<int>>& inputArray);

	//HW #3
	string isPresent(const vector<vector<int>>& arr, int targ);

	//HW #4
	long long int findMaxPossibleArea(const vector<long long int>& heights, int l, int r);
	
	//HW #5
	vector<int> sumZero(const vector<int>& arr);

	//Quiz #1
	string detect_primes(const vector<int>& arr);
	bool isPrime(int n);
	
}


#endif
