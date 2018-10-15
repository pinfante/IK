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


LinkedListNode* llist::find_middle_node(LinkedListNode* head)
{
	if(!head)return head;

	int mid{0};
	return find_middle_node(head, 1, mid);
}

LinkedListNode* llist::find_middle_node(LinkedListNode* n, int pos, int& mid)
{
	LinkedListNode* midNode{nullptr};

	if(n->next)
		midNode = find_middle_node(n->next, pos+1, mid);
	else
		mid = pos/2+1;

	if(pos == mid)
		return n;

	return midNode;
}

int llist::getLen(LinkedListNode* n)
{
	if(!n)return 0;

	size_t len{1};
	while(n->next)
	{
		n = n->next;
		++len;
	}
	return len;
}

LinkedListNode* llist::swap_nodes(LinkedListNode* head, int k)
{
	if(!head || !head->next || !k)return head;

	int len = getLen(head);

	if(k > len)return head;
	if(2*k-1 == len)return head;

	LinkedListNode* left{head}, *lprev{nullptr};
	
	for(int i{1}; i < k; ++i)
	{
		lprev = left;
		left = left->next;
	}

	LinkedListNode* right{head}, *rprev{nullptr};

	for(int i{len-k+1}; i > 1; --i)
	{
		rprev = right;
		right = right->next;
	}

	if(lprev)
		lprev->next = right;

	if(rprev)
		rprev->next = left;

	LinkedListNode* lnext{left->next};
	left->next = right->next;
	right->next = lnext;

	if(k == 1)
		head = right;
	if(k == len)
		head = left;

	return head;
}

LinkedListNode* llist::reverseList(LinkedListNode* head)
{
	auto tail = reverseList(head, head);
	tail->next = nullptr;
	return head;
}

LinkedListNode* llist::reverseList(LinkedListNode*& head, LinkedListNode* n)
{
	LinkedListNode* prev{nullptr};

	if(n->next)
		prev = reverseList(head, n->next);
	else
	{
		head = n;
		return n;
	}

	prev->next = n;
	return n;		
}

LinkedListNode* llist::reverse_linked_list_in_groups_of_k(LinkedListNode* head, int k)
{
	int len{getLen(head)};
	if(!len) return head;

	if(k == len)
	{
		reverseList(head, head);
		return head;
	}

	int iter{len/k};

	if(len % k != 0)++iter;

	LinkedListNode* curr{head->next}, *next{nullptr}, *prev{head}, *tail{nullptr}, *prevtail{nullptr};

	for(int i{0}; i < iter; ++i)
	{
		for(int j{1}; j < k; ++j)
		{
			if(!curr)break;
			
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		if(i+k == len)
			break;
		if(i == 0)
		{
			head->next = next;
			tail = next;
			prevtail = head;
			head = prev;
		}
		else
		{
			prevtail->next = prev;
			prevtail = tail;
			tail->next = next;
			tail = next;
		}

		if(!curr) break;
		curr = next->next;
		prev = next;
	}

	return head;
}

pair<LinkedListNode*, LinkedListNode*> llist::alternateSplit(LinkedListNode* head)
{
	if(!head)return make_pair(nullptr, nullptr);

	LinkedListNode* list1{head}, *list2{head->next};

	if(!list2)return make_pair(list1, list2);
 
	LinkedListNode* l1{list1}, *l2{list2};
	head = head->next->next;

	size_t i{0};
	while(head)
	{
		if(i % 2 == 0)
		{
			l1->next = head;
			l1 = l2->next;
		}
		else
		{
			l2->next = head;
			l2 = l2->next;
		}

		head = head->next;
		++i;			
	}

	l1->next = nullptr;
	l2->next = nullptr;

	return make_pair(list1, list2);
}

LinkedListNode* llist::mergeSortList(LinkedListNode* head)
{
	if(head == nullptr || head->next == nullptr)
		return head;

	return mergeList(mergeSortList(head), mergeSortList(split(head)));
}

LinkedListNode* llist::mergeList(LinkedListNode* l, LinkedListNode* r)
{
	if(l && !r)return l;
	if(r && !l)return r;
	if(!l && !r)return l;

	LinkedListNode* head{nullptr};
	if(l->val < r->val)
	{
		head = l;
		l = l->next;
	}
	else
	{
		head = r;
		r = r->next;
	}

	LinkedListNode* curr{head};

	while(l && r)
	{
		if(l->val < r->val)
		{
			curr->next = l;
			l = l->next;
		}
		else
		{
			curr->next = r;
			r = r->next;
		}
		curr = curr->next;
	}

	while(l)
	{
		curr->next = l;
		curr = curr->next;
		l = l->next;
	}
	while(r)
	{
		curr->next = r;
		curr = curr->next;
		r = r->next;
	}
	return head;
}

LinkedListNode* llist::split(LinkedListNode* head)
{
	if(!head || !head->next)return head; 

	LinkedListNode* fast{head->next}, *slow{head};
	while(fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	fast = slow->next;
	slow->next = nullptr;
	
	return fast;
}
