#include "gmock/gmock.h"
#include "BinaryTree.h"
#include <iostream>

using std::cout;
using std::endl;

using namespace testing;
using namespace BinaryTree;

class Test_BinaryTree : public Test
{
	public:

		Node* root;
		Test_BinaryTree();

};

Test_BinaryTree::Test_BinaryTree() : root{nullptr}
{
	root = BinaryTree::insert(root, 20);
	root = BinaryTree::insert(root, 10);
	root = BinaryTree::insert(root, 30);
	root = BinaryTree::insert(root, 5);
	root = BinaryTree::insert(root, 17);
	root = BinaryTree::insert(root, 25);
	root = BinaryTree::insert(root, 35);
	root = BinaryTree::insert(root, 3);
	root = BinaryTree::insert(root, 6);
	root = BinaryTree::insert(root, 15);
	root = BinaryTree::insert(root, 4);
	root = BinaryTree::insert(root, 16);
}

TEST_F(Test_BinaryTree, insert)
{
	ASSERT_THAT(root, NotNull());
	EXPECT_THAT(root->val, Eq(20));
	EXPECT_THAT(root->left->val, Eq(10));
	EXPECT_THAT(root->right->val, Eq(30));
}

TEST_F(Test_BinaryTree, find)
{
	auto n = BinaryTree::find(root, 20);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(20));
	EXPECT_THAT(n, Eq(root));

	n = BinaryTree::find(root, 16);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(16));
	EXPECT_THAT(n->left, IsNull());
	EXPECT_THAT(n->right, IsNull());

	n = BinaryTree::find(root, 17);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(17));
	ASSERT_THAT(n->left, NotNull());
	EXPECT_THAT(n->left->val, Eq(15));
	EXPECT_THAT(n->right, IsNull());

	n = BinaryTree::find(root, 100);
	ASSERT_THAT(n, IsNull());
}

TEST_F(Test_BinaryTree, findMax)
{
	auto n = BinaryTree::findMax(root);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(35));
}

TEST_F(Test_BinaryTree, numOfChildren)
{
	EXPECT_THAT(BinaryTree::numOfChildren(root), Eq(2));
	auto n = BinaryTree::find(root, 35);
	EXPECT_THAT(BinaryTree::numOfChildren(n), Eq(0));
	n = BinaryTree::find(root, 3);
	EXPECT_THAT(BinaryTree::numOfChildren(n), Eq(1));
}

TEST_F(Test_BinaryTree, remove)
{
	BinaryTree::remove(root, 35);
	ASSERT_THAT(BinaryTree::find(root, 35), IsNull());
	root = BinaryTree::insert(root, 35);
	BinaryTree::remove(root, 3);
	ASSERT_THAT(BinaryTree::find(root, 3), IsNull());
	auto n = BinaryTree::find(root, 5);
	EXPECT_THAT(n->left->val, Eq(4));

	BinaryTree::remove(root, 10);
	EXPECT_THAT(root->left->val, Eq(6));
	EXPECT_THAT(root->left->left->val, Eq(5));
}

TEST_F(Test_BinaryTree, isBST)
{
	EXPECT_THAT(BinaryTree::isBST(root), Eq(true));
}

TEST_F(Test_BinaryTree, findLCA)
{
	auto n = BinaryTree::findLCA(root, 3, 6);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(5));

	n = BinaryTree::findLCA(root, 16, 4);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(10));

	n = BinaryTree::findLCA(root, 3, 35);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(20));

	n = BinaryTree::findLCA(root, 3, 4);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(3));

	n = BinaryTree::findLCA(root, 30, 35);
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(30));
}

TEST_F(Test_BinaryTree, build_balanced_bst)
{
	auto n = BinaryTree::build_balanced_bst(vector{8,10,12,15,16,20,25});
	ASSERT_THAT(n, NotNull());
	EXPECT_THAT(n->val, Eq(15));
	EXPECT_THAT(n->left->val, Eq(10));
	EXPECT_THAT(n->right->val, Eq(20));
	EXPECT_THAT(n->left->left->val, Eq(8));
	EXPECT_THAT(n->left->right->val, Eq(12));
	EXPECT_THAT(n->right->left->val, Eq(16));
	EXPECT_THAT(n->right->right->val, Eq(25));
}

TEST_F(Test_BinaryTree, kth_smallest_element)
{
	int k{1};
	EXPECT_THAT(BinaryTree::kth_smallest_element(root, k), Eq(3));
	k = 3;
	EXPECT_THAT(BinaryTree::kth_smallest_element(root, k), Eq(5));
	k = 9;
	EXPECT_THAT(BinaryTree::kth_smallest_element(root, k), Eq(20));

}

TEST_F(Test_BinaryTree, treeToList)
{
	auto n = treeToList(root);
	EXPECT_THAT(n->val, Eq(3));
	EXPECT_THAT(n->right->val, Eq(4));
	EXPECT_THAT(n->right->right->val, Eq(5));	
}

TEST_F(Test_BinaryTree, mergeTrees)
{
	auto n1 = BinaryTree::insert(nullptr, 2);	
	n1 = BinaryTree::insert(n1, 1);
	n1 = BinaryTree::insert(n1, 3);

	auto n2 = BinaryTree::insert(nullptr, 7);	
	n2 = BinaryTree::insert(n2, 6);
	n2 = BinaryTree::insert(n2, 8);

	auto n3 = BinaryTree::mergeTrees(n1, n2);
	ASSERT_THAT(n3, NotNull());
	EXPECT_THAT(n3->val, Eq(3));
	EXPECT_THAT(n3->left->val, Eq(1));
	EXPECT_THAT(n3->right->val, Eq(7));
	EXPECT_THAT(n3->left->right->val, Eq(2));
	EXPECT_THAT(n3->right->left->val, Eq(6));
	EXPECT_THAT(n3->right->right->val, Eq(8));

}
