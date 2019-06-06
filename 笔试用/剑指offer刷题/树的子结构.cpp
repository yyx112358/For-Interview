#include "..\������\GlobalInc.h"
#include "..\������\ListArray.hpp"
#include "..\������\BinTree.h"
#include "..\������\Plot.h"
#include <memory>

/*�����ӽṹ��572. ��һ���������� https://leetcode-cn.com/problems/subtree-of-another-tree/��

�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��

˼·���������ƣ���LEETCODEΪ׼���������ݹ麯����ɡ�
	����s��t����Ϊ�վ���������������������s���ҵ�s�к�t���ڵ���ֵͬ�Ľڵ�
	���Ӹýڵ㿪ʼ�����Ӧ������tͬʱ�������ж��ǲ�����ͬ���Ƿ���true����������������
*/
class Solution_isSubtree 
{
public:
	bool isSubtree(TreeNode* s, TreeNode* t)//����������ҵ�s��ֵ��t��ͬ�ڵ�
	{
		if (t == nullptr || s == nullptr)
			return false;
		else
		{
			if (s->val == t->val && _isSubtree(s, t) == true)//�ҵ����ж϶�Ӧ������t�Ƿ���ͬ
				return true;
			else
			{
				return isSubtree(s->left, t) == true
					|| isSubtree(s->right, t) == true;
			}
		}
	}
	bool _isSubtree(TreeNode*s, TreeNode*t)//�ж�s��t��Ӧ�����Ƿ���ͬ
	{
		if (s == nullptr&&t == nullptr)//ţ�͸�Ϊif (s == nullptr&&t == nullptr || s != nullptr&&t == nullptr)
			return true;
		else if (s == nullptr&&t != nullptr || s != nullptr&&t == nullptr)//ţ�͸�Ϊelse if (s == nullptr&&t != nullptr)
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

