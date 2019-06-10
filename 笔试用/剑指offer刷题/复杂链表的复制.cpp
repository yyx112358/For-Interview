#include "..\������\GlobalInc.h"
#include "..\������\ListArray.hpp"
#include "..\������\BinTree.h"
#include "..\������\Plot.h"
#include <memory>
#include <vld.h>

//������ӡvector��ģ�庯��
template<typename Tp>
ostream&operator<<(ostream&os, const vector<Tp>&v)
{
	os << '[';
	for (auto i : v)
		os << i << ',';
	os << ']' << endl;
	return os;
}
/*

*/
struct Node {
	int val;
	struct Node *next, *random;
	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
class Solution {
public:
	Node* Clone(Node* head)
	{
		if (head == nullptr)
			return nullptr;
		auto newHead = new Node(head->val,nullptr,nullptr);
		unordered_map<Node*, Node*>tbl;
		tbl[head] = newHead;
		for (auto p = head, pnew = newHead; p->next != nullptr; p = p->next, pnew = pnew->next)
		{
			pnew->next = new Node(p->next->val, nullptr, nullptr);
			tbl[p->next] = pnew->next;
		}
		for (auto p = head, pnew = newHead; p != nullptr; p = p->next, pnew = pnew->next)
			pnew->random = tbl[p->random];
		return newHead;
	}
};

int main()
{
	srand(0x411);

	Solution solution;
	cout << solution.Print(CreateBinTree("[1,2,3,4,5,6,7,8,9,10,11,12,13]")) << endl;

	cout << solution.Print(CreateBinTree("[1,2,3,null,5,7,null]")) << endl;
	system("pause");
	return 0;
}

