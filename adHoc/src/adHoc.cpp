#include "adHoc.h"
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cmath>

using std::unordered_map;
using std::stack;
using std::max;

vector<int> AdHoc::getProductArray(const vector<int>& nums)
{
	int size{static_cast<int>(nums.size())};
    vector<int> res(size);
    int t{1};
    
    for(int i{0}; i < size; i++)
    {
        res[i] = t;
        t *= nums[i]; 
    }
    
    t = 1;
    for(int i{size-1}; i >= 0; i--)
    {
        res[i] *= t;
        t *= nums[i];
    }
    
    return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int>> AdHoc::getMergedIntervals(vector<vector<int>>& inputArray)
{
	size_t size{inputArray.size()};

	if(size <= 1)return inputArray;

	std::sort(inputArray.begin(), inputArray.end());

	vector<vector<int>> res;
	vector<int> curr(2);

	curr[0] = inputArray[0][0];
	curr[1] = inputArray[0][1];

	for(size_t i{0}; i < size; i++)
	{
		if(inputArray[i][0] <= curr[1])
			curr[1] = std::max(curr[1], inputArray[i][1]);
		else
		{
			res.push_back(curr);
			curr[0] = inputArray[i][0];
			curr[1] = inputArray[i][1];
		}

		if(i == size-1)
			res.push_back(curr);
	}

	return res;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string AdHoc::isPresent(const vector<vector<int>>& arr, int targ)
{
    const string pres{"present"};
    const string notPres{"not present"};
    
    if(arr.empty()) return notPres;
    
    int row{0};
	int rows{static_cast<int>(arr.size())};
	int col{static_cast<int>(arr[0].size()-1)};
    
    while(row < rows && col >= 0)
    {
        if(arr[row][col] == targ)
            return pres;
        else if(arr[row][col] > targ)
            col--;
        else
            row++;
    }
    
    return notPres;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long int AdHoc::findMaxPossibleArea(const vector<long long int>& heights, int l, int r)
{
	long long maxArea{0};
	stack<int> s;
	int i{0};
	while(i <= r - l)
	{
		if(s.empty() || heights[l + s.top()] <= heights[i + l])
			s.push(i++);
		else
		{
			auto top{s.top()};
			s.pop();	
			auto width{s.empty() ? i : i - s.top() - 1};
			auto area{width * heights[top - l]};
			maxArea = max(maxArea, area);
		}
	}

	while(!s.empty())
	{
		auto top{s.top()};
		s.pop();	
		auto width{s.empty() ? r - l + 1 : r - l - s.top()};
		long long int area{width * heights[top + l]};
		maxArea = max(maxArea, area);
	}

	return maxArea;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> AdHoc::sumZero(const vector<int>& arr)
{
    unordered_map<long, int> sum_index;
    vector<int> ans;
    long curr{0};
	const size_t size{arr.size()};
    
    for (size_t i{0}; i < size; ++i)
    {
        curr += arr[i];
    
        if (curr == 0)
        {
            ans.push_back(0);
            ans.push_back(i);
            return ans;
        } 
        else if (sum_index.find(curr) != sum_index.end()) 
        {
            ans.push_back(sum_index[curr] + 1);
            ans.push_back(i);
            return ans;
        }
        else
            sum_index[curr] = i;
    }
    ans.push_back(-1);
    return ans;
}

bool AdHoc::isPrime(int n)
{
	if(n == 2)return true;

	if(n == 1 || n % 2 == 0) return false;

	size_t lim(ceil(sqrt(n)));
	for(size_t i{3}; i <= lim; i+=2)
		if(n % i == 0)return false;
	
	return true;
}

string AdHoc::detect_primes(const vector<int>& arr)
{
	string res;

	for(auto& v : arr)
		if(isPrime(v))
			res.push_back('1');
		else
			res.push_back('0');

	return res;
}
