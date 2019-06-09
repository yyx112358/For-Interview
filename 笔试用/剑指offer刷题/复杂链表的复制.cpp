#include "..\笔试用\GlobalInc.h"
#include "..\笔试用\ListArray.hpp"
#include "..\笔试用\BinTree.h"
#include "..\笔试用\Plot.h"
#include <memory>
#include <vld.h>

//用来打印vector的模板函数
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
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;

		RandomListNode*newHead = new RandomListNode(pHead->label);
		unordered_map<RandomListNode*, RandomListNode*>tbl;
		for (auto p = pHead, pnew = newHead;p->next!=nullptr;p=p->next)
		{

		}

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

