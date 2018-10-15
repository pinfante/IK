#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>


using namespace std;

class LinkedListNode
{
	public:
		int val;
		LinkedListNode *next;

		LinkedListNode(int node_value) : val{node_value}, next{nullptr}{}
};

namespace llist
{
	void print(LinkedListNode* n);

	LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode* head, LinkedListNode *tail, int val);

	//HW # 2
	LinkedListNode* addNumbers(LinkedListNode* l1, LinkedListNode* l2);

	//HW # 5
	LinkedListNode* zip_given_linked_list(LinkedListNode* head);
	LinkedListNode* zip_given_linked_list(LinkedListNode* curr, LinkedListNode* end);

	//QUIZ # 1
	LinkedListNode* mergeAt(int index, LinkedListNode* head1, LinkedListNode* tail2);
	int find_intersection(LinkedListNode* l1, LinkedListNode* l2);
	pair<int, int> findLengths(LinkedListNode* l1, LinkedListNode* l2);
	pair<int, int> findLengths(LinkedListNode* l1, int size1, LinkedListNode* l2, int size2);

	//QUIZ # 2
	bool isAscending(LinkedListNode* n);
	pair<int, LinkedListNode*> lengthNStarting(LinkedListNode* n);
	long find_median(LinkedListNode* n);

	//HW #6
	LinkedListNode* find_middle_node(LinkedListNode* head);
	LinkedListNode* find_middle_node(LinkedListNode* n, int pos, int& mid);

	//HW #8
	LinkedListNode* swap_nodes(LinkedListNode* head, int k);
	LinkedListNode* swap_nodes(LinkedListNode* l, LinkedListNode* r, int& k);

	//HW #10
	LinkedListNode* mergeSortList(LinkedListNode* head);
	LinkedListNode* mergeList(LinkedListNode* l, LinkedListNode* r);
	LinkedListNode* split(LinkedListNode* head);
	

	//HW #12
	LinkedListNode* reverseList(LinkedListNode* head);
	LinkedListNode* reverseList(LinkedListNode*& head, LinkedListNode* n);
	LinkedListNode* reverse_linked_list_in_groups_of_k(LinkedListNode* head, int k);
	int getLen(LinkedListNode* n);

	//HW #13
	pair<LinkedListNode*, LinkedListNode*> alternateSplit(LinkedListNode* head);
}



