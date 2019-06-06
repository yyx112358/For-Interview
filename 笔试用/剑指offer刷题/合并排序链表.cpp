#include "..\笔试用\GlobalInc.h"
#include "..\笔试用\ListArray.hpp"
#include "..\笔试用\BinTree.h"
#include "..\笔试用\Plot.h"
#include <memory>
#include <vld.h>

/*合并有序链表

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
		if (l1->val > l2->val)//保证一开始l1比l2小
			swap(l1, l2);
		auto head = l1;

		while (l1 != nullptr&&l2 != nullptr)
		{
			while (l1->next != nullptr&&l1->next->val < l2->val)//找到l1中第一个比l2小且其下一个节点比l2大的节点
				l1 = l1->next;
			auto tmp = l1->next;//将l2头节点插入l1当前节点后方，随后l1,l2后移
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

