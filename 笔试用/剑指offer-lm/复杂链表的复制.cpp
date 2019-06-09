#include "..\±  ‘”√\GlobalInc.h"
#include "..\±  ‘”√\ListArray.hpp"
#include "..\±  ‘”√\BinTree.h"
#include "..\±  ‘”√\Plot.h"

int main()
{
	auto root = CreateBinTree("[1,2,3,4,null,5]");
	PlotBinTree(root);
	WaitKey(-1);
	return 0;
}