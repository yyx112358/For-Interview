#include "..\笔试用\GlobalInc.h"
#include "..\笔试用\ListArray.hpp"

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr)return nullptr;
		while (pHead->next != nullptr)
		{
			int flag = 0;
			while (pHead->next != nullptr&&pHead->val == pHead->next->val)
			{
				flag = 1;
				pHead = pHead->next;
			}
			if (flag == 0)break;
			pHead = pHead->next;
			if (pHead == nullptr || pHead->next == nullptr || pHead->val != pHead->next->val)
				break;
		}
		if (pHead == nullptr)return nullptr;
		ListNode* pcur = pHead->next;
		ListNode *pt = pHead;
		while (pcur != nullptr&&pcur->next != nullptr)
		{
			int flag = 0;
			while (pcur->next != nullptr&&pcur->next->val == pcur->val)
			{
				pcur = pcur->next;
				flag = 1;
			}
			pcur = pcur->next;
			flag == 1 ? pt->next = pcur : pt = pt->next;
		}
		return pHead;
	}
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
};

int main()
{
	Solution so;
	ListNode *p = nullptr;
	ListNode *q = nullptr;
	p = so.deleteDuplication(so.CreateListArray(vector<int>{ 1, 1, 1, 1, 1, 1, 1, 1 }));
	q = so.deleteDuplication(so.CreateListArray(vector<int>{ 1, 2, 2, 3, 4, 5, 6, 6 }));
	so.PrintListArray(p);
	so.PrintListArray(q);
	return 0;
}