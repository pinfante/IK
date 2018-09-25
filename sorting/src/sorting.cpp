#include "sorting.h"
#include <queue>
#include <utility>
#include <algorithm>
#include <sstream>
#include <unordered_set>

using std::pair;
using std::swap;
using std::to_string;
using std::ostringstream;
using std::unordered_set;

void sorting::quickSort(vector<int>& arr)
{
	quickSort(arr, 0, static_cast<int>(arr.size())-1);
}

void sorting::quickSort(vector<int>& arr, int beg, int end)
{
	if(beg >= end)return;

	int p{partition(arr, beg, end)};
	quickSort(arr, beg, p-1);
	quickSort(arr, p, end); 
}

int sorting::partition(vector<int>& arr, int beg, int end)
{
	int p = beg + (end-beg)/2;

	while(beg <= end)
	{
		while(arr[beg] < arr[p])++beg;
		while(arr[end] > arr[p])--end;

		if(beg <= end)
			swap(arr[beg++], arr[end--]);
	}

	return beg;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sorting::mergeSort(vector<int>& arr)
{
	mergeSort(arr, 0, arr.size()-1);
}

void sorting::mergeSort(vector<int>& arr, int beg, int end)
{
	if(beg >= end)return;

	int mid = beg + (end-beg)/2;
	mergeSort(arr, beg, mid);
	mergeSort(arr, mid+1, end);
	merge(arr, beg, mid, end);
}

void sorting::merge(vector<int>& arr, int beg, int mid, int end)
{
	vector<int> lv, rv;
	int n1 = mid - beg + 1; 
	int n2 = end - mid;

	for(int i{0}; i < n1; ++i)
		lv.push_back(arr[beg+i]); 

	for(int i{0}; i < n2; ++i)
		rv.push_back(arr[mid+1+i]);

	int i{0}, j{0}, k{beg}, lsize{static_cast<int>(lv.size())}, rsize{static_cast<int>(rv.size())};

	while(i < lsize && j < rsize)
	{
		if(lv[i] <= rv[j]) 
			arr[k++] = lv[i++];
		else arr[k++] = rv[j++];
	}

	while(i < lsize)
		arr[k++] = lv[i++];
	while(j < rsize)
		arr[k++] = rv[j++];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Element
{
	Element(vector<int>::const_iterator beg, vector<int>::const_iterator end) : pos{std::make_pair(beg, end)}{}

	pair<vector<int>::const_iterator, vector<int>::const_iterator> pos;
};

bool operator<(const Element& lhs, const Element& rhs){ return *lhs.pos.first > *rhs.pos.first;} 
 
vector<int> sorting::mergeArrays(const vector<vector<int>>& arr) 
{
    std::priority_queue<Element> q;
	vector<int> results;

	for(auto& v : arr)
	{
		if(v.size())
			q.emplace(Element{v.begin(), v.end()});
	}

	while(!q.empty())
	{
		Element curr = q.top();
		results.push_back(*curr.pos.first);
		q.pop();

		if(++curr.pos.first != curr.pos.second)
			q.push(curr);
	}

	return results;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> sorting::oddEvenPartition(vector<int> arr) 
{
    auto begIt = arr.begin();
    auto endIt = arr.end()-1;
    
    while(begIt < endIt)
    {
        while(begIt < endIt && *begIt % 2 == 0)
            ++begIt;
        while(endIt > begIt && *endIt % 2 != 0)
            --endIt;
            
        if(begIt < endIt)
            std::swap(*begIt, *endIt);
    }
    return arr;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector <int> sorting::topK(vector <int> arr, int k) 
{
	int size{static_cast<int>(arr.size())};
    std::sort(arr.begin(), arr.end(), [](int lhs, int rhs){return lhs > rhs;});
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
    if(size < k)
        return arr;
        
    return vector<int>{arr.begin(), arr.begin()+k};
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> sorting::merger_first_into_second(vector<int>&& arr1, vector<int>&& arr2) 
{
	int i{static_cast<int>(arr1.size()-1)};
	int j = i;
	int k{(i+1)*2 - 1};
	while( i >= 0 && j >= 0 && k >= 0)
	{
		if(arr1[i] > arr2[j])
			arr2[k--] = arr1[i--];
		else
			arr2[k--] = arr2[j--];
	}

	while(i >= 0 && k >= 0)
		arr2[k--] = arr1[i--];

	return arr2;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string sorting::dutch_flag_sort(string&& balls)
{
	int size{static_cast<int>(balls.size())};
    int beg{0}, end{size-1}, i{0};

    while(i < size && i <= end)
    {
		if(balls[i] == 'G')
			++i;
        else if(balls[i] == 'B')
			swap(balls[i], balls[end--]);
        else if(balls[i] == 'R')
			swap(balls[i++], balls[beg++]);
    }
    
	return balls;	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


vector<string> sorting::nutsBolts(vector<int>& nuts, vector<int>& bolts)
{
	nutsBolts(nuts, bolts, 0, nuts.size()-1);
	vector<string> res;

	for(size_t i{0}; i < nuts.size(); ++i)
		res.push_back(to_string(nuts[i]) + " " + to_string(bolts[i]));

	return res;
}

void sorting::nutsBolts(vector<int>& nuts, vector<int>& bolts, int st, int end)
{
	if(st >= end)return;
	
	int nIdx{partitionNutsBolts(nuts, st, end, bolts[st+(end-st)/2])};
	partitionNutsBolts(bolts, st, end, nuts[nIdx]);
	nutsBolts(nuts, bolts, st, nIdx-1);
	nutsBolts(nuts, bolts, nIdx+1, end);
}

int sorting::partitionNutsBolts(vector<int>& v, int st, int end, int pivot)
{
	int i = st;
	int temp1, temp2;
	for (int j = st; j < end; j++)
	{
		if (v[j] < pivot){
			temp1 = v[i];
			v[i] = v[j];
			v[j] = temp1;
			i++;
		} else if(v[j] == pivot){
			temp1 = v[j];
			v[j] = v[end];
			v[end] = temp1;
			j--;
		}
	}
	temp2 = v[i];
	v[i] = v[end];
	v[end] = temp2;

	return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> sorting::findZeroSum(vector<int>& v)
{
	std::sort(v.begin(), v.end());
	vector<string> res;
	size_t n = v.size();

	unordered_set<string> m_entries;

	for(size_t i{0}; i < n-2; ++i)
	{
		size_t l{i+1}, r{n-1};
		while(l < r)
		{
			long sum{v[i]+v[l]+v[r]};
			if(sum == 0)
			{
				vector<int> sortRes{v[i], v[l], v[r]};
				std::sort(sortRes.begin(), sortRes.end());
				ostringstream ss;
				ss << sortRes[0] << ',' << sortRes[1] << "," << sortRes[2];
				auto it = m_entries.find(ss.str());
				if(it == m_entries.end())
				{
					res.push_back(ss.str());
					m_entries.insert(ss.str());
				}
				++l, --r;
			}
			else if(sum < 0)++l;
			else --r;
		}
	}

	return res;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string sorting::sortCharacters(string&& word)
{
	vector<size_t> res(256, 0);
	for(const auto& ch : word)
		res[static_cast<int>(ch)]++;

	ostringstream ss;
	for(size_t i{0}; i < res.size(); ++i)
		if(res[i])
			for(size_t j{0}; j < res[i]; ++j)
				ss << static_cast<char>(i);

	return ss.str();
}
