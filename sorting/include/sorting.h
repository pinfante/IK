#ifndef _SORTING_H_
#define _SORTING_H_

#include <vector>
#include <string>

using std::string;
using std::vector;

namespace sorting
{
	//PREP VIDEO 1
	void quickSort(vector<int>& arr);
	void quickSort(vector<int>& arr, int beg, int end);
	int partition(vector<int>& arr, int beg, int end);

	//PREP VIDEO 2
	void mergeSort(vector<int>& v);
	void mergeSort(vector<int>& v, int beg, int end);
	void merge(vector<int>& v, int beg, int mid, int end);

	//HW PROBLEM 1
	vector<int> mergeArrays(const vector<vector<int>>& arr);
	//HW PROBLEM 2
	vector<int> oddEvenPartition(vector<int> arr);
	//HW PROBLEM 3
	vector <int> topK(vector <int> arr, int k);

	//TEST PROBLEM 1
	vector<int> merger_first_into_second(vector<int>&& arr1, vector<int>&& arr2);
	//TEST PROBLEM 2
	string dutch_flag_sort(string&& balls);
}
#endif
