#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include<vector>
#include<string>
#include<utility>

using std::pair;
using std::string;
using std::vector;

class Node
{
	public:
		Node(int v) : val{v}, left{nullptr}, right{nullptr}{}

		int val;
		Node* left;
		Node* right;
};

namespace BinaryTree
{
	//PREP VIDEO
	Node* insert(Node* root, int n);

	void remove(Node* root, int n);

	Node* find(Node* root, int n);

	Node* findMax(Node* root);

	int numOfChildren(Node* root);
/////////////////////////////////////////////////////////////////////////////////////

	//HW#1
	bool isBST(Node* root);
/////////////////////////////////////////////////////////////////////////////////////

	//HW#2
	void printAllPaths(Node* root);
	void printAllPaths(Node* root, vector<int>& s);
/////////////////////////////////////////////////////////////////////////////////////

	//HW#3 Convert a BST to a circular double linked list.
	Node* treeToList(Node* root);
	//void treeToList(Node* root, List& _list);
	void join(Node* next, Node* prev);
	Node* append(Node* prev, Node* next);
/////////////////////////////////////////////////////////////////////////////////////

	//HW#4
	Node* findLCA(Node* root, int n1, int n2);
/////////////////////////////////////////////////////////////////////////////////////

	//HW#5 Merge Trees
	Node* mergeTrees(Node* n1, Node* n2);
	void inOrderList(Node* n, vector<int>& v);
	vector<int> inOrderList(Node* n);
	vector<int> mergeLists(const vector<int>& v1, const vector<int>& v2);
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
	//TEST#1
	Node* build_balanced_bst(const vector<int>& a, Node* n, int beg, int end);
	Node* build_balanced_bst(const vector<int>& a);

	//TEST#2
	int kth_smallest_element(Node* root, int k);
	pair<bool, int> kthSmallestElement(Node* root, int& k);
/////////////////////////////////////////////////////////////////////////////////////
};

#endif // _BINARY_TREE_H_
