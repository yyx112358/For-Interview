#pragma once
#include "GlobalInc.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};
//从一个vector<int>中创建链表
ListNode*CreateListArray(vector<int>&input)
{
	ListNode*head;
	if (input.size() == 0)
		return nullptr;
	else
		head = new ListNode(input.front());

	ListNode*p = head;
	for (auto i = 1; i < input.size(); ++i, p = p->next)
		p->next = new ListNode(input[i]);
	return head;
}
void PrintListArray(const ListNode* head)
{
#ifdef _DEBUG
	cout << '[';
	while (head != nullptr) 
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << ']' << endl;
#endif // _DEBUG
}