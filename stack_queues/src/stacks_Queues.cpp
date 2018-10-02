#include<stack>
#include<string>
#include "stacks_Queues.h"
#include <iostream>
#include <deque>

using std::string;
using std::stack;
using std::cout;
using std::endl;
using std::vector;
using std::deque;

int stacks_Queues::find_max_length_of_matching_parentheses(const string& brackets)
{
	stack<int> stk;
	const int size{static_cast<int>(brackets.size())};
	int maxSub{0};
	stk.push(-1);

	for(int i{0}; i < size; ++i)
	{
		if(brackets[i] == '(')
			stk.push(i);
		else
		{
			stk.pop();

			if(!stk.empty())
				maxSub = std::max(maxSub, i - stk.top());
			else
				stk.push(i);
		}
	}
	return maxSub;
}

//Maximum In Sliding Window
// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
vector<int> stacks_Queues::max_in_sliding_window(const vector<int>& arr, size_t w)
{
    // Create a Double Ended Queue, Qi that will store indexes of array elements
    // The queue will store indexes of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in Qi, i.e., 
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    deque<int> que;
	vector<int> res;
 
    /* Process first k (or first window) elements of array */
    size_t i{0};
    for (; i < w; ++i)
    {
        // For very element, the previous smaller elements are useless so
        // remove them from que
        while (!que.empty() && arr[i] >= arr[que.back()])
            que.pop_back();  // Remove from rear
 
        // Add new element at rear of queue
        que.push_back(i);
    }
 
    // Process rest of the elements, i.e., from arr[w] to arr[n-1]
    for ( ; i < arr.size(); ++i)
    {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        res.push_back(arr[que.front()]);
 
        // Remove the elements which are out of this window
        while ( (!que.empty()) && que.front() <= static_cast<int>(i - w))
            que.pop_front();  // Remove from front of queue
 
        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!que.empty()) && arr[i] >= arr[que.back()])
            que.pop_back();
 
         // Add current element at the rear of que
        que.push_back(i);
    }
 
    // Print the maximum element of last window
	res.push_back(arr[que.front()]);

	return res;
}
