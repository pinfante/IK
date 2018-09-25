#include "llist.h"
#include <iostream>

LinkedListNode* llist::_insert_node_into_singlylinkedlist(LinkedListNode* head, LinkedListNode *tail, int val)
{
    if(head == NULL) 
	{
        head = new LinkedListNode(val);
        tail = head;
    }
    else 
	{
        LinkedListNode *node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}


void llist::print(LinkedListNode* n)
{
	while(n)
	{
		std::cout << "[" << n->val << "]";
		n = n->next;
	}
	std::cout << std::endl;
}

LinkedListNode* llist::addNumbers(LinkedListNode* l1, LinkedListNode* l2) 
{
	LinkedListNode* head{nullptr};
	LinkedListNode* tail{head};

	int carry{0};

	while(l1 || l2)
	{
		int val{0};

		if(l1 && l2)
			val = l1->val + l2->val + carry;
		else if(l1) val = l1->val + carry;  
		else val = l2->val + carry;

		int newVal{val % 10};
		carry = val/10;

		if(!head)
			head = tail = _insert_node_into_singlylinkedlist(head, tail, newVal);
		else
			tail = _insert_node_into_singlylinkedlist(head, tail, newVal);

		if(l1)
			l1 = l1->next;
		if(l2)
			l2 = l2->next;
	}

	if(carry)
	{
		if(!head)
			head = tail = _insert_node_into_singlylinkedlist(head, tail, carry);
		else 
			tail = _insert_node_into_singlylinkedlist(head, tail, carry);
	}		
	return head;
}

LinkedListNode* llist::zip_given_linked_list(LinkedListNode* head)
{
	if(head && head->next)
		zip_given_linked_list(head, head);
	return head;
}

LinkedListNode* llist::zip_given_linked_list(LinkedListNode* curr, LinkedListNode* end)
{
	LinkedListNode* nextNode{nullptr};

	if(end->next)
		nextNode = zip_given_linked_list(curr, end->next);
	
	if(end->next != nullptr)
		curr = nextNode;

	if(!curr)
		return nullptr;

	if(curr->next == end || curr == end)
	{
		end->next = nullptr;
		return nullptr;
	}

	else if(curr->next)
	{
		LinkedListNode* n{curr->next};
		curr->next = end;
		end->next = n;
		end = end->next;
	}

	return end;
}

LinkedListNode* llist::mergeAt(int index, LinkedListNode* head1, LinkedListNode* tail2)
{
	for(int i{0}; i < index; ++i)
		head1 = head1->next;

	if(!tail2)
		tail2 = head1;
	else
		tail2->next = head1;

	return tail2;
}

pair<int, int> llist::findLengths(LinkedListNode* l1, LinkedListNode* l2)
{
	return findLengths(l1, 0, l2, 0);
}

pair<int, int> llist::findLengths(LinkedListNode* l1, int size1, LinkedListNode* l2, int size2)
{
	if(!l1 && !l2)
		return make_pair(size1, size2);
	else if(l1 && l2)
		return findLengths(l1->next, size1+1, l2->next, size2+1);
	else if(l1 && !l2)
		return findLengths(l1->next, size1+1, l2, size2);
	else 
		return findLengths(l1, size1, l2->next, size2+1);
}

int llist::find_intersection(LinkedListNode* l1, LinkedListNode* l2) 
{
    auto n1{l1};
    auto n2{l2};

	auto sizes{findLengths(l1, l2)};
	int size1{sizes.first}, size2{sizes.second};

    if(size1 > size2)
    {
        int diff{size1-size2};
        
        for(int i{0}; i< diff; ++i)
            n1 = n1->next;
    }
    else
    {
        int diff{size2-size1};
        
        for(int i{0}; i< diff; ++i)
            n2 = n2->next;
    }
    
    while(n1 && n2)
    {
        if(n1 == n2)
            return n1->val;
        
        n1 = n1->next;
        n2 = n2->next;
    }
    
    return -1;
}

bool llist::isAscending(LinkedListNode* n)
{
	auto curr{n->next};
	auto prev{n};
	size_t less{0}, greater{0};

	while(curr != n)
	{
		if(curr->val > prev->val)
			++greater;
		else if(curr->val < prev->val)
			++less;

		curr = curr->next;
		prev = prev->next;
	}

	return greater >= less;
}

pair<int, LinkedListNode*> llist::lengthNStarting(LinkedListNode* n)
{
	bool asc{isAscending(n)};
	size_t len{1};
	auto curr{n->next};
	LinkedListNode* start{nullptr};
	

	while(curr != n)
	{
		if(!start)
		{
			if((asc && curr->val < n->val) || (!asc && curr->val > n->val))
				start = curr;
		}

		++len;
		curr = curr->next;
	}

	if(!start)
		start = n;

	return make_pair(len, start);
}

long llist::find_median(LinkedListNode* n) 
{
	auto res{lengthNStarting(n)};
	int len{res.first};
	n = res.second;

	bool isEven{len % 2 == 0};
	len /= 2;

	for(int i{0}; i < len-1; ++i)
		n = n->next;

	if(!isEven)
		return n->next->val;

	auto next{n->next};

	while(next->val == n->val && next != n)
		next = next->next;

	int x1{0}, x2{0};
	if(n->val < next->val)
	{
		x1 = n->val;
		x2 = next->val;
	}
	else
	{
		x1 = next->val;
		x2 = n->val;
	}

	return x1 + (x2 - x1)/2;
}
