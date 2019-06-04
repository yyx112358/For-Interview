#include "GlobalInc.h"
#include "ListArray.hpp"
#include "BinTree.h"
#include "Plot.h"
#include <memory>
//#include <vld.h>

int main()
{
	srand(0x411);

	shared_ptr<TreeNode>n = shared_ptr<TreeNode>(CreateBinTree("[1,2,3,5,null,4,5,9,null,7,11]"));
	PrintBinTree(n.get());
	PlotBinTree(n.get());
	WaitKey(500);

	n = shared_ptr<TreeNode>(CreateBinTree("[1,2,3,5,null,4,5,9,null,7,11,null,8,null,7,null,8,11,66,5]"));
	PrintBinTree(n.get());
	PlotBinTree(n.get());
	WaitKey(-1);

	system("pause");
	return 0;
}

