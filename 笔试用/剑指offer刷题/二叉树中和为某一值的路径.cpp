#include "..\笔试用\GlobalInc.h"
#include "..\笔试用\ListArray.hpp"
#include "..\笔试用\BinTree.h"
#include "..\笔试用\Plot.h"
#include <memory>
#include <vld.h>

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
class Solution_FindPath {
public:
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) 
	{
		vector <vector<int>>result;
		vector<int>path;
		PlotBinTree(root);
		WaitKey(1);
		_FindPath(root, expectNumber, result, path);
		sort(result.begin(), result.end(), 
			[](vector<int>&a, vector<int>&b) {return a.size() > b.size(); });
		return result;
	}
	void _FindPath(TreeNode*node, int expectNumber, vector<vector<int>>&result, vector<int>&path)
	{
		if (node != nullptr)
		{
			if (expectNumber - node->val < 0)
				return;
			else
			{
				path.push_back(node->val);
				if (node->left != nullptr || node->right != nullptr)//不是叶节点
				{
					_FindPath(node->left, expectNumber - node->val, result, path);
					_FindPath(node->right, expectNumber - node->val, result, path);
				}
				else if (expectNumber == node->val)
					result.push_back(path);
				path.pop_back();
			}
		}
	}
};

int main()
{
	srand(0x411);

	Solution_FindPath solution;
	cout << solution.FindPath(CreateBinTree("[10,5,12,4,7]"),22)<< endl;

	system("pause");
	return 0;
}

