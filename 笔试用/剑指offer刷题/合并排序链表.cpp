#include "..\������\GlobalInc.h"
#include "..\������\ListArray.hpp"
#include "..\������\BinTree.h"
#include "..\������\Plot.h"
#include <memory>
#include <vld.h>

/*�ϲ���������

*/
class Solution_mergeTwoLists
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		if (l1->val > l2->val)//��֤һ��ʼl1��l2С
			swap(l1, l2);
		auto head = l1;

		while (l1 != nullptr&&l2 != nullptr)
		{
			while (l1->next != nullptr&&l1->next->val < l2->val)//�ҵ�l1�е�һ����l2С������һ���ڵ��l2��Ľڵ�
				l1 = l1->next;
			auto tmp = l1->next;//��l2ͷ�ڵ����l1��ǰ�ڵ�󷽣����l1,l2����
			l1->next = l2;
			l1 = l2;
			l2 = l2->next;
			l1->next = tmp;
		}
		return head;
	}
};

int main()
{
	srand(0x411);

	Solution_mergeTwoLists solution;
	PrintListArray(solution.mergeTwoLists(CreateListArray(vector<int>{1, 3, 5, 7}), CreateListArray(vector<int>{2, 4, 6, 7, 9, 10})));
	PrintListArray(solution.mergeTwoLists(CreateListArray(vector<int>{1, 3, 5, 7}), CreateListArray(vector<int>{2, 5, 6})));
	PrintListArray(solution.mergeTwoLists(CreateListArray(vector<int>{1, 3, 5, 7}), CreateListArray(vector<int>{2, 4, 6})));

	system("pause");
	return 0;
}

