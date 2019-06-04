#pragma once
#include "GlobalInc.h"

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	~TreeNode()
	{
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
		left = nullptr, right = nullptr;
	}
};
class BinTree
{
public:
	BinTree(string);
	BinTree(const BinTree&);
	~BinTree();

	TreeNode* Create(const string&);
	void Destroy();

	BinTree& operator=(string&);
	operator string();
	friend ostream&operator<<(ostream&os, const BinTree&btree);

	TreeNode*root();
	int depth()const;
private:
	TreeNode*_root = nullptr;
	int _depth = 0, _nodeAmount = 0;
};

//======================声明======================
//层序遍历序列创建二叉树，空节点填null。
//例如[1,2,null]创建一个根节点1，左节点2的树
//参考leetcode，https://support.leetcode-cn.com/hc/kb/article/1194353/
extern TreeNode*CreateBinTree(string input);
//序列化二叉树为字符串。
//序列化方法与leetcode一致
extern string SerilizeBinTree(TreeNode* root);
//打印二叉树
extern void PrintBinTree(TreeNode*node);
//绘制二叉树
extern bool PlotBinTree(TreeNode*root);