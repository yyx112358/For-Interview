#include "BinTree.h"
#include "Plot.h"

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}
//层序遍历序列创建二叉树，空节点填null。例如[1,2,null]
//参考leetcode，https://support.leetcode-cn.com/hc/kb/article/1194353/
TreeNode*CreateBinTree(string input)
{
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}
		try
		{
			trimLeftTrailingSpaces(item);
			if (item != "null") {
				int leftNumber = stoi(item);
				node->left = new TreeNode(leftNumber);
				nodeQueue.push(node->left);
			}

			if (!getline(ss, item, ',')) {
				break;
			}

			trimLeftTrailingSpaces(item);
			if (item != "null") {
				int rightNumber = stoi(item);
				node->right = new TreeNode(rightNumber);
				nodeQueue.push(node->right);
			}
		}
		catch (std::exception&e)
		{
			cout << __FILE__ << ',' << __LINE__ << ',' << __FUNCSIG__ << endl << e.what() << endl;
			throw e;
		}
	}
	return root;
}
//序列化方法与leetcode一致，除了不加左右括号，null简化为n
//序列化方法：类似于层次遍历，但如果某一节点为NULL,则其子节点不显示，否则都显示（空子节点为“n”）
string SerilizeBinTree(TreeNode* root)
{
	string result = "[";
	queue<TreeNode*>qnode;//层序遍历队列
	qnode.push(root);//预先压入root

	int levelNode = 1, nextLevelNode = 0;//当前层节点数(初始为1即root)，下一层节点数（初始未知为0）
	int nextLevelValidNode;//下一层非空有效节点，如果为0说明下一层全空，应结束
	do
	{
		nextLevelValidNode = 0;
		while (levelNode > 0)
		{
			TreeNode* node = qnode.front();
			if (node != nullptr)
			{
				result += to_string(node->val);

				TreeNode*nodeL = node->left, *nodeR = node->right;
				qnode.push(nodeL);
				qnode.push(nodeR);
				if (nodeL != nullptr)
					nextLevelValidNode++;
				if (nodeR != nullptr)
					nextLevelValidNode++;
				nextLevelNode += 2;
			}
			else
				result += "null";

			result += ',';
			qnode.pop();

			levelNode--;
		}
		levelNode = nextLevelNode;//进入下一层
		nextLevelNode = 0;
		//result+='|';
	} while (nextLevelValidNode != 0);
	if (result.back() == ',')//去掉末尾的','，否则分割将
		result.pop_back();
	//cout<<result<<endl;
	result += ']';
	return result;
}
//打印二叉树
void PrintBinTree(TreeNode*node)
{
	cout << SerilizeBinTree(node) << endl;
}

bool PlotBinTree(TreeNode*root)
{
	vector<int>values;
	vector<char>isNulls;
	int totalLevel = 0;

	//层序遍历，构造节点序列（空节点也加入，构成完全二叉树）
	{
		queue<TreeNode*>qnode;//层序遍历队列
		qnode.push(root);//预先压入root

		int levelNode = 1, nextLevelNode = 0;//当前层节点数(初始为1即root)，下一层节点数（初始未知为0）
		int nextLevelValidNode;//下一层非空有效节点，如果为0说明下一层全空，应结束
		do
		{
			nextLevelValidNode = 0;
			while (levelNode > 0)
			{
				TreeNode* node = qnode.front();
				if (node != nullptr)
				{
					values.push_back(node->val);
					isNulls.push_back(false);

					TreeNode*nodeL = node->left, *nodeR = node->right;
					qnode.push(nodeL);
					qnode.push(nodeR);
					if (nodeL != nullptr)
						nextLevelValidNode++;
					if (nodeR != nullptr)
						nextLevelValidNode++;
					nextLevelNode += 2;
				}
				else
				{
					values.push_back(0);
					isNulls.push_back(true);
					qnode.push(nullptr);
					qnode.push(nullptr);
					nextLevelNode += 2;
				}
				qnode.pop();

				levelNode--;
			}
			levelNode = nextLevelNode;//进入下一层
			nextLevelNode = 0;

			totalLevel++;
		} while (nextLevelValidNode != 0);
	}
	if (root == nullptr)
		return true;

	ClearWindow();
	auto rect = GetWindowSize();
	int imgWidth = rect.width(), imgHeight = rect.height();
	auto levelHeight = imgHeight / 2 / totalLevel;//层高
	for (auto level = 0, cnt = 0; level < totalLevel; level++)
	{
		int levelNodeCnt = pow(2, level);//当前层节点数
		auto nodeWidth = imgWidth / levelNodeCnt / 2;

		for (auto i = 0; i < levelNodeCnt && cnt < isNulls.size(); i++, cnt++)
		{
			if (isNulls[cnt] == false)
			{
				if (level > 0)
					Line(nodeWidth*(i * 2 + 1), levelHeight*(level * 2 + 1),
						imgWidth / pow(2, level - 1) / 2 * (i / 2 * 2 + 1), levelHeight*(level * 2 - 1));
			}
		}
	}
	for (auto level = 0, cnt = 0; level < totalLevel; level++)
	{
		int levelNodeCnt = pow(2, level);
		auto nodeHeight = levelHeight*(level * 2 + 1);
		auto nodeWidth = imgWidth / levelNodeCnt / 2;
		auto circleRadius = levelHeight / 2;
		for (auto i = 0; i < levelNodeCnt && cnt < isNulls.size(); i++, cnt++)
		{
			if (isNulls[cnt] == false)
			{
				Circle(nodeWidth*(i * 2 + 1), nodeHeight, circleRadius);
				Text(nodeWidth*(i * 2 + 1) - circleRadius / 3, nodeHeight, to_string(values[cnt]));
			}
		}
	}
	WaitKey(1);
	return true;
}