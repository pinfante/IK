#include "gmock/gmock.h"
#include "llist.h"

using namespace testing;
using namespace llist;

class TestLinkedList : public Test
{
	public:

	pair<LinkedListNode*, LinkedListNode*> populuate();

	LinkedListNode* createList(const vector<int>& values);

};

pair<LinkedListNode*, LinkedListNode*> TestLinkedList::populuate()
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};
	LinkedListNode *head2{nullptr}, *tail2{nullptr};

	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	head2 = tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 6);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 9);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 3);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 2);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 1);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 5);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 8);
	return make_pair(head1, head2);
}

LinkedListNode* TestLinkedList::createList(const vector<int>& values)
{
	LinkedListNode *head{nullptr}, *tail{nullptr};
	head = tail = _insert_node_into_singlylinkedlist(head, tail, values[0]);
	for(auto it = values.begin()+1; it != values.end(); ++it)
		tail = _insert_node_into_singlylinkedlist(head, tail, *it);

	return head;
}

TEST_F(TestLinkedList, verifyValues)
{
	auto values{populuate()};
	auto n1{values.first};
	auto n2{values.second};
	ASSERT_THAT(n1, NotNull());
	ASSERT_THAT(n2, NotNull());
	EXPECT_THAT(n1->val, Eq(4));
	EXPECT_THAT(n1->next->val, Eq(9));
	EXPECT_THAT(n2->val, Eq(6));
	EXPECT_THAT(n2->next->val, Eq(3));
}

TEST_F(TestLinkedList, addNumbers)
{
	auto values{populuate()};
	auto l1{values.first};
	auto l2{values.second};

	auto resList{addNumbers(l1, l2)};

	EXPECT_THAT(resList->val, Eq(0));
	EXPECT_THAT(resList->next->val, Eq(3));
	EXPECT_THAT(resList->next->next->val, Eq(4));
	EXPECT_THAT(resList->next->next->next->val, Eq(3));
	EXPECT_THAT(resList->next->next->next->next->val, Eq(1));
}


TEST_F(TestLinkedList, addNumbers1)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};
	LinkedListNode *head2{nullptr}, *tail2{nullptr};
	head1 = _insert_node_into_singlylinkedlist(head1, tail1, 1);
	tail1 = head1;
	head2 = _insert_node_into_singlylinkedlist(head2, tail2, 2);
	tail2 = head2;

	auto resList{addNumbers(head1, head2)};
	ASSERT_THAT(resList, NotNull());
	EXPECT_THAT(resList->val, Eq(3));
}

TEST_F(TestLinkedList, add1Numbers2)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};
	LinkedListNode *head2{nullptr}, *tail2{nullptr};
	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 1);
	head2 = tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 9);

	auto resList{addNumbers(head1, head2)};
	ASSERT_THAT(resList, NotNull());
	EXPECT_THAT(resList->val, Eq(0));
	EXPECT_THAT(resList->next->val, Eq(1));
}

TEST_F(TestLinkedList, add1Numbers3)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};
	LinkedListNode *head2{nullptr};
	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 2);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 1);

	auto resList{addNumbers(head1, head2)};
	ASSERT_THAT(resList, NotNull());
	EXPECT_THAT(resList->val, Eq(2));
	EXPECT_THAT(resList->next->val, Eq(1));
}

TEST_F(TestLinkedList, add1Numbers4)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};
	LinkedListNode *head2{nullptr}, *tail2{nullptr};
	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 1);
	_insert_node_into_singlylinkedlist(head1, tail1, 2);

	head2 = tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 2);
	_insert_node_into_singlylinkedlist(head2, tail2, 2);

	auto resList{addNumbers(head1, head2)};
	ASSERT_THAT(resList, NotNull());
	EXPECT_THAT(resList->val, Eq(3));
	EXPECT_THAT(resList->next->val, Eq(4));
}

TEST_F(TestLinkedList, add1Numbers5)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};
	LinkedListNode *head2{nullptr}, *tail2{nullptr};
	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 6);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 1);

	head2 = tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 4);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 1);

	auto resList{addNumbers(head1, head2)};
	ASSERT_THAT(resList, NotNull());
	EXPECT_THAT(resList->val, Eq(0));
	EXPECT_THAT(resList->next->val, Eq(3));
}

TEST_F(TestLinkedList, add1Numbers6)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};
	LinkedListNode *head2{nullptr}, *tail2{nullptr};
	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 9);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 9);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 9);

	head2 = tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 9);

	auto resList{addNumbers(head1, head2)};
	ASSERT_THAT(resList, NotNull());
	EXPECT_THAT(resList->val, Eq(8));
	EXPECT_THAT(resList->next->val, Eq(0));
	EXPECT_THAT(resList->next->next->val, Eq(0));
	EXPECT_THAT(resList->next->next->next->val, Eq(1));
}

TEST_F(TestLinkedList, zipNullList)
{
	LinkedListNode *head{nullptr};
	head = zip_given_linked_list(head);
	ASSERT_THAT(head, IsNull());
}

TEST_F(TestLinkedList, zipList1)
{
	LinkedListNode *head{nullptr}, *tail{nullptr};
	head = tail = _insert_node_into_singlylinkedlist(head, tail, 1);
	tail = _insert_node_into_singlylinkedlist(head, tail, 2);
	tail = _insert_node_into_singlylinkedlist(head, tail, 3);
	tail = _insert_node_into_singlylinkedlist(head, tail, 4);
	tail = _insert_node_into_singlylinkedlist(head, tail, 5);
	tail = _insert_node_into_singlylinkedlist(head, tail, 6);

	head = zip_given_linked_list(head);
	ASSERT_THAT(head, NotNull());
	EXPECT_THAT(head->val, Eq(1));
	EXPECT_THAT(head->next->val, Eq(6));
	EXPECT_THAT(head->next->next->val, Eq(2));
	EXPECT_THAT(head->next->next->next->val, Eq(5));
	EXPECT_THAT(head->next->next->next->next->val, Eq(3));
	EXPECT_THAT(head->next->next->next->next->next->val, Eq(4));
}

TEST_F(TestLinkedList, zipListOneElement)
{
	LinkedListNode *head{nullptr}, *tail{nullptr};
	head = tail = _insert_node_into_singlylinkedlist(head, tail, 1);
	head = zip_given_linked_list(head);
	ASSERT_THAT(head, NotNull());
	EXPECT_THAT(head->val, Eq(1));
}

TEST_F(TestLinkedList, zipListTwoElements)
{
	LinkedListNode *head{nullptr}, *tail{nullptr};
	head = tail = _insert_node_into_singlylinkedlist(head, tail, 1);
	tail = _insert_node_into_singlylinkedlist(head, tail, 2);

	head = zip_given_linked_list(head);
	ASSERT_THAT(head, NotNull());
	EXPECT_THAT(head->val, Eq(1));
	EXPECT_THAT(head->next->val, Eq(2));
}

TEST_F(TestLinkedList, zipListThreeElements)
{
	LinkedListNode *head{nullptr}, *tail{nullptr};
	head = tail = _insert_node_into_singlylinkedlist(head, tail, 1);
	tail = _insert_node_into_singlylinkedlist(head, tail, 2);
	tail = _insert_node_into_singlylinkedlist(head, tail, 3);


	head = zip_given_linked_list(head);
	ASSERT_THAT(head, NotNull());
	EXPECT_THAT(head->val, Eq(1));
	EXPECT_THAT(head->next->val, Eq(3));
	EXPECT_THAT(head->next->next->val, Eq(2));
}

TEST_F(TestLinkedList, find_intersection)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};
	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 1);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 2);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 3);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 7);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 9);

	LinkedListNode *head2{nullptr}, *tail2{nullptr};
	head2 = tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 5);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 6);
	tail2 = mergeAt(3, head1, tail2);
	EXPECT_THAT(find_intersection(head1, head2), Eq(4)); 
}

TEST_F(TestLinkedList, find_median)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr}, *start{nullptr};

	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 1);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 2);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 3);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	start =	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 7);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 9);
	tail1->next = head1;

	EXPECT_THAT(find_median(start), Eq(4)); 

	LinkedListNode *head2{nullptr}, *tail2{nullptr};
	head2 = tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 2);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 2);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 3);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 4);
	start =	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 6);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 8);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 9);
	tail2 = _insert_node_into_singlylinkedlist(head2, tail2, 10);
	tail2->next = head2;
	EXPECT_THAT(find_median(start), Eq(5));



	LinkedListNode *head3{nullptr}, *tail3{nullptr};
	head3 = tail3 = _insert_node_into_singlylinkedlist(head3, tail3, 12);
	tail3 = _insert_node_into_singlylinkedlist(head3, tail3, 10);
	tail3 = _insert_node_into_singlylinkedlist(head3, tail3, 8);
	tail3 = _insert_node_into_singlylinkedlist(head3, tail3, 6);
	start =	tail3 = _insert_node_into_singlylinkedlist(head3, tail3, 4);
	tail3 = _insert_node_into_singlylinkedlist(head3, tail3, 2);
	tail3->next = head3;
	EXPECT_THAT(find_median(start), Eq(7));

}

TEST_F(TestLinkedList, find_medianLen1)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};

	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 2000000000);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 2000000000);
	tail1->next = head1;

	EXPECT_THAT(find_median(tail1), Eq(2000000000)); 
}

TEST_F(TestLinkedList, find_medianNeg)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr};

	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, -2000000000);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, -2000000000);
	tail1->next = head1;

	EXPECT_THAT(find_median(tail1), Eq(-2000000000)); 
}

TEST_F(TestLinkedList, find_repeating)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr}, *start{nullptr};

	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	start = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1->next = head1;

	EXPECT_THAT(find_median(start), Eq(6)); 
}

TEST_F(TestLinkedList, find_repeating1)
{
	LinkedListNode *head1{nullptr}, *tail1{nullptr}, *start{nullptr};

	head1 = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 4);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	start = tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1 = _insert_node_into_singlylinkedlist(head1, tail1, 8);
	tail1->next = head1;

	EXPECT_THAT(find_median(start), Eq(6)); 
}

TEST_F(TestLinkedList, find_middle_node)
{
	LinkedListNode *head{nullptr}, *tail{nullptr};

	head = tail = _insert_node_into_singlylinkedlist(head, tail, 1);
	tail = _insert_node_into_singlylinkedlist(head, tail, 2);
	tail = _insert_node_into_singlylinkedlist(head, tail, 3);
	tail = _insert_node_into_singlylinkedlist(head, tail, 4);
	tail = _insert_node_into_singlylinkedlist(head, tail, 5);

	auto mid = find_middle_node(head);
	EXPECT_THAT(mid->val, Eq(3));

	tail = _insert_node_into_singlylinkedlist(head, tail, 6);
	mid = find_middle_node(head);
	EXPECT_THAT(mid->val, Eq(4));
}

TEST_F(TestLinkedList, swap_nodes)
{
	LinkedListNode *head{nullptr}, *tail{nullptr};

	head = tail = _insert_node_into_singlylinkedlist(head, tail, 1);
	tail = _insert_node_into_singlylinkedlist(head, tail, 2);
	tail = _insert_node_into_singlylinkedlist(head, tail, 3);
	tail = _insert_node_into_singlylinkedlist(head, tail, 4);
	tail = _insert_node_into_singlylinkedlist(head, tail, 7);
	tail = _insert_node_into_singlylinkedlist(head, tail, 0);

	auto n{swap_nodes(head, 2)};
	EXPECT_THAT(n->next->val, Eq(7));

	n = swap_nodes(head, 1);
	EXPECT_THAT(n->val, Eq(0));
}

TEST_F(TestLinkedList, reverse_linked_list_in_groups_of_k)
{
	auto head = createList(vector<int>{1,2,3,4,5,6});
	head = reverse_linked_list_in_groups_of_k(head, 3);
	EXPECT_THAT(head->val, Eq(3));
	EXPECT_THAT(head->next->val, Eq(2));
	EXPECT_THAT(head->next->next->val, Eq(1));
	EXPECT_THAT(head->next->next->next->val, Eq(6));
	EXPECT_THAT(head->next->next->next->next->val, Eq(5));
	EXPECT_THAT(head->next->next->next->next->next->val, Eq(4));

	auto h2 = createList(vector<int>{1,2,3,4,5,6,7,8});
	h2 = reverse_linked_list_in_groups_of_k(h2, 3);
	EXPECT_THAT(h2->val, Eq(3));
	EXPECT_THAT(h2->next->val, Eq(2));
	EXPECT_THAT(h2->next->next->val, Eq(1));
	EXPECT_THAT(h2->next->next->next->val, Eq(6));
	EXPECT_THAT(h2->next->next->next->next->val, Eq(5));
	EXPECT_THAT(h2->next->next->next->next->next->val, Eq(4));
	EXPECT_THAT(h2->next->next->next->next->next->next->val, Eq(8));
	EXPECT_THAT(h2->next->next->next->next->next->next->next->val, Eq(7));

	auto h3 = createList(vector<int>{-50,0,50});
	h3 = reverse_linked_list_in_groups_of_k(h3, 2);
	EXPECT_THAT(h3->val, Eq(0));
	EXPECT_THAT(h3->next->val, Eq(-50));
	EXPECT_THAT(h3->next->next->val, Eq(50));


	auto h4 = createList(vector<int>{-20,10,20,-10});
	h4 = reverse_linked_list_in_groups_of_k(h4, 4);
	EXPECT_THAT(h4->val, Eq(-10));
	EXPECT_THAT(h4->next->val, Eq(20));
	EXPECT_THAT(h4->next->next->val, Eq(10));
	EXPECT_THAT(h4->next->next->next->val, Eq(-20));

	auto h5 = createList(vector<int>{-10, -20});
	h5 = reverse_linked_list_in_groups_of_k(h5, 2);
	EXPECT_THAT(h5->val, Eq(-20));
	EXPECT_THAT(h5->next->val, Eq(-10));

}

TEST_F(TestLinkedList, alternateSplit)
{
	auto [l1, l2] = alternateSplit(createList(vector<int>{1,2,3,4,5,6,7,8}));
	EXPECT_THAT(l1->val, Eq(1));
	EXPECT_THAT(l1->next->val, Eq(3));
	EXPECT_THAT(l1->next->next->val, Eq(5));
	EXPECT_THAT(l1->next->next->next->val, Eq(7));
	EXPECT_THAT(l2->val, Eq(2));
	EXPECT_THAT(l2->next->val, Eq(4));
	EXPECT_THAT(l2->next->next->val, Eq(6));
	EXPECT_THAT(l2->next->next->next->val, Eq(8));

	auto [list1, list2] = alternateSplit(createList(vector<int>{1}));
	EXPECT_THAT(list1->val, Eq(1));
	EXPECT_THAT(list2, Eq(nullptr));
}


TEST_F(TestLinkedList, mergeSortList)
{
	auto head = mergeSortList(createList(vector<int>{100,20,-35,14,51,16,-72,85}));
	EXPECT_THAT(head->val, Eq(-72));
	EXPECT_THAT(head->next->val, Eq(-35));
	EXPECT_THAT(head->next->next->val, Eq(14));
	EXPECT_THAT(head->next->next->next->val, Eq(16));
	EXPECT_THAT(head->next->next->next->next->val, Eq(20));
	EXPECT_THAT(head->next->next->next->next->next->val, Eq(51));
	EXPECT_THAT(head->next->next->next->next->next->next->val, Eq(85));
	EXPECT_THAT(head->next->next->next->next->next->next->next->val, Eq(100));
}

