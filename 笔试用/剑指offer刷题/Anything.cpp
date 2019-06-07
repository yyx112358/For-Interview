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
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int>>results;
		if (pRoot == nullptr)
			return results;
		int nowLevelCnt = 1, nextLevelCnt = 0;//当前层待处理数，下一层待处理数
		queue<TreeNode*>qnode;//层序遍历用队列
		vector<int>result;//当前层遍历结果
		qnode.push(pRoot);
		do
		{
			nowLevelCnt--;
			auto node = qnode.front();
			qnode.pop();
			result.push_back(node->val);

			if (node->left != nullptr) 
			{
				qnode.push(node->left);
				nextLevelCnt++;
			}
			if (node->right != nullptr)
			{
				qnode.push(node->right);
				nextLevelCnt++;
			}

			if (nowLevelCnt == 0)//当前层遍历完了
			{
				results.push_back(vector<int>());
				result.swap(results.back());
				swap(nowLevelCnt, nextLevelCnt);
			}
		} while (nowLevelCnt>0 || nextLevelCnt > 0);

		for (auto i = 0; i < results.size(); ++i)
			if (i % 2 == 1)
				reverse(results[i].begin(), results[i].end());
		return results;
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

