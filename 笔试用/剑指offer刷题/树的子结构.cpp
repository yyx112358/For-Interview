#include "..\笔试用\GlobalInc.h"
#include "..\笔试用\ListArray.hpp"
#include "..\笔试用\BinTree.h"
#include "..\笔试用\Plot.h"
#include <memory>

/*树的子结构（572. 另一个树的子树 https://leetcode-cn.com/problems/subtree-of-another-tree/）

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

思路：二者类似，以LEETCODE为准。由两个递归函数组成。
	首先s、t任意为空均不是子树。随后先序遍历s，找到s中和t根节点相同值的节点
	随后从该节点开始对其对应子树和t同时遍历，判断是不是相同，是返回true，否则继续先序遍历
*/
class Solution_isSubtree 
{
public:
	bool isSubtree(TreeNode* s, TreeNode* t)//先序遍历，找到s中值和t相同节点
	{
		if (t == nullptr || s == nullptr)
			return false;
		else
		{
			if (s->val == t->val && _isSubtree(s, t) == true)//找到后，判断对应子树和t是否相同
				return true;
			else
			{
				return isSubtree(s->left, t) == true
					|| isSubtree(s->right, t) == true;
			}
		}
	}
	bool _isSubtree(TreeNode*s, TreeNode*t)//判断s、t对应的树是否相同
	{
		if (s == nullptr&&t == nullptr)//牛客改为if (s == nullptr&&t == nullptr || s != nullptr&&t == nullptr)
			return true;
		else if (s == nullptr&&t != nullptr || s != nullptr&&t == nullptr)//牛客改为else if (s == nullptr&&t != nullptr)
			return false;
		else
			return s->val == t->val
			&& _isSubtree(s->left, t->left) == true
			&& _isSubtree(s->right, t->right) == true;
	}
};

int main()
{
	srand(0x411);

	shared_ptr<TreeNode>s = shared_ptr<TreeNode>(CreateBinTree("[1,1]"));
	shared_ptr<TreeNode>t = shared_ptr<TreeNode>(CreateBinTree("[1]"));

	Solution_isSubtree solution;
	cout << (solution.isSubtree(s.get(), t.get()) ? "true" : "false") << endl;

	system("pause");
	return 0;
}

