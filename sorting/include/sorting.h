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
	//HW #7
	void mergeSort(vector<int>& v);
	void mergeSort(vector<int>& v, int beg, int end);
	void merge(vector<int>& v, int beg, int mid, int end);

	//HW #1
	vector<int> mergeArrays(const vector<vector<int>>& arr);
	//HW #2
	vector<int> oddEvenPartition(vector<int> arr);
	//HW #3
	vector <int> topK(vector <int> arr, int k);

	//QUIZ #1
	vector<int> merger_first_into_second(vector<int>&& arr1, vector<int>&& arr2);
	//QUIZ # 2
	string dutch_flag_sort(string&& balls);

	//HW #4
	vector<string> nutsBolts(vector<int>& nuts, vector<int>& bolts);
	void nutsBolts(vector<int>& nuts, vector<int>& bolts, int st, int end);
	int partitionNutsBolts(vector<int>& v, int st, int end, int pivot);

	//HW #5
	vector<string> findZeroSum(vector<int>& v);

	//HW #8
	string sortCharacters(string&& word);
	
}
#endif
