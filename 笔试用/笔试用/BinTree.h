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

//======================����======================
//����������д������������սڵ���null��
//����[1,2,null]����һ�����ڵ�1����ڵ�2����
//�ο�leetcode��https://support.leetcode-cn.com/hc/kb/article/1194353/
extern TreeNode*CreateBinTree(string input);
//���л�������Ϊ�ַ�����
//���л�������leetcodeһ��
extern string SerilizeBinTree(TreeNode* root);
//��ӡ������
extern void PrintBinTree(TreeNode*node);
//���ƶ�����
extern bool PlotBinTree(TreeNode*root);