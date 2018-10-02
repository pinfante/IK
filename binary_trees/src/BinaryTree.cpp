#include "BinaryTree.h"
#include <iostream>
using std::cout;
using std::endl;
using std::make_pair;

Node* BinaryTree::insert(Node* root, int n)
{
	if(!root)
		return new Node(n);

	if(n < root->val)
		root->left = insert(root->left, n);
	else
		root->right = insert(root->right, n);

	return root;
}

Node* BinaryTree::findMax(Node* root)
{
	if(!root)return nullptr;

	while(root->right)
		root = root->right;

	return root;
}

int BinaryTree::numOfChildren(Node* root)
{
	if(!root)
		throw("");

	if(root->left && root->right)return 2;
	else if(!root->left && !root->right)return 0;
	else return 1;
}

void BinaryTree::remove(Node* root, int value)
{
	if(!root)return;

	if(root->val == value)
	{
		delete root;
		return;
	}

	if(value < root->val)
	{
		if(!root->left)
			return;

		if(root->left->val != value)
			remove(root->left, value);
		
		else
		{
			auto n = root->left;
			int numCh{numOfChildren(n)};
			switch(numCh)
			{
				case 0:
				{
					delete n;
					root->left = nullptr;
					return;
				}
				case 1:
				{
					if(n->left)
						root->left = n->left;
					else
						root->left = n->right;

					delete n;
					return;
				}
				case 2:
				{
					auto m = findMax(n->left);
					n->val = m->val;
					remove(n->left, m->val);		
				}
			}
		}
	}
	else
	{
		if(!root->right)
			return;

		if(root->right->val != value)
			remove(root->right, value);
		
		else
		{
			auto n = root->right;
			int numCh{numOfChildren(n)};
			switch(numCh)
			{
				case 0:
				{
					delete n;
					root->right = nullptr;
					return;
				}
				case 1:
				{
					if(n->left)
						root->right = n->left;
					else
						root->right = n->right;

					delete n;
					return;
				}
				case 2:
				{
					auto m = findMax(n->left);
					n->val = m->val;
					remove(n->left, m->val);		
				}
			}
		}
	}
}

Node* BinaryTree::find(Node* root, int n)
{
	if(!root)
		return nullptr;

	if(n == root->val)
		return root;
	else if(n < root->val)
		return find(root->left, n);
	else 
		return find(root->right, n);
}

bool BinaryTree::isBST(Node* root)
{
	if(!root)return true;

	bool isBst{true};

	if(root->left)
		isBst = root->left->val < root->val;

	if(root->right)
		isBst = root->right->val > root->val && isBst;

	return isBst && isBST(root->right) && isBST(root->left);
}

void BinaryTree::printAllPaths(Node* root)
{
	if(!root)return;

	vector<int> s;
	printAllPaths(root, s);
}

void BinaryTree::printAllPaths(Node* root, vector<int>& s)
{
	if(root)
		s.push_back(root->val);

	if(!root->right && !root->left)
	{
		for(size_t i{0}; i < s.size(); ++i)
		{
			if(i == s.size()-1)
				cout << s[i];
			else
				cout << s[i] << " ";
		}
		cout << endl;
		return;
	}

	if(root->left)
	{
		printAllPaths(root->left, s);
		s.pop_back();
	}
	if(root->right)
	{
		printAllPaths(root->right, s);
		s.pop_back();
	}
}

Node* BinaryTree::findLCA(Node* root, int n1, int n2)
{
	if(!root)
		return nullptr;

	if(root->val == n1 || root->val == n2)
		return root;

	auto leftNode = findLCA(root->left, n1, n2);
	auto rightNode = findLCA(root->right, n1, n2);

	if(leftNode && rightNode)return root;

	return leftNode ? leftNode : rightNode;
}

Node* BinaryTree::build_balanced_bst(const vector<int>& a, Node* n, int beg, int end)
{
    if(beg > end)return nullptr;
    
	int mid{beg + (end-beg)/2};
    n = new Node(a[mid]);
    n->left = build_balanced_bst(a, n->left, beg, mid-1);
	n->right = build_balanced_bst(a, n->right, mid+1, end);
	return n;
}

Node* BinaryTree::build_balanced_bst(const vector<int>& a)
{
	Node* root{nullptr};
    return build_balanced_bst(a, root, 0, static_cast<int>(a.size())-1);
}

int BinaryTree::kth_smallest_element(Node* root, int k) 
{
	auto res{BinaryTree::kthSmallestElement(root, k)};
	if(res.first)
		return res.second;

	return -1;
}

pair<bool, int> BinaryTree::kthSmallestElement(Node* root, int& k) 
{
	if(!root)return make_pair(false,-1);

	auto res{kthSmallestElement(root->left, k)};
	if(res.first)
		return res;

	if(!--k)
		return make_pair(true, root->val);

	return kthSmallestElement(root->right, k);
}

void BinaryTree::inOrderList(Node* n, vector<int>& v)
{
	if(!n)return;

	inOrderList(n->left, v);
	v.push_back(n->val);
	inOrderList(n->right, v);
}

vector<int> BinaryTree::inOrderList(Node* n)
{
	vector<int> v;
	inOrderList(n, v);
	return v;
}

vector<int> BinaryTree::mergeLists(const vector<int>& v1, const vector<int>& v2)
{
	vector<int> m;
	size_t s1{v1.size()};
	size_t s2{v2.size()};
	m.reserve(s1+s2);
	size_t i{0}, j{0};

	while(i < s1 && j < s2)
	{
		if(v1[i] < v2[j])
			m.push_back(v1[i++]);
		else
			m.push_back(v2[j++]);
	}

	while(i < s1)m.push_back(v1[i++]);
	while(j < s2)m.push_back(v2[j++]);

	return m;
}

Node* BinaryTree::mergeTrees(Node* n1, Node* n2)
{
	return build_balanced_bst(mergeLists(inOrderList(n1), inOrderList(n2)));
}

void BinaryTree::join(Node* next, Node* prev)
{
	next->right = prev;
	prev->left = next;
}

Node* BinaryTree::append(Node* prev, Node* next)
{
	if(!prev)return next;
	if(!next)return prev;

	Node* prevLast = prev->left;
	Node* nextLast = next->right;

	join(prevLast, next);
	join(nextLast, prev);	

	return prev;
}

Node* BinaryTree::treeToList(Node* root)
{
	Node* prev{nullptr};
	Node* next{nullptr};

	if(!root) return nullptr;

	prev = treeToList(root->left);
	next = treeToList(root->right);

	root->left = root;
	root->right = root;

	prev = append(prev, root);
	prev = append(prev, next);

	return prev;
}


