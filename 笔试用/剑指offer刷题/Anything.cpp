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
	for (auto &i : v)
		os << i << ',';
	os << ']' << endl;
	return os;
}
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		vector<int>record(1, 0);
		//[0,1]有0个，[0,9]有1个，[0,99]有10+10*1(10位10次，1位10次)，[0,999]有100+99+99
	}
};

int main()
{
	srand(0x411);
	
	Solution solution;
	cout << solution.NumberOf1Between1AndN_Solution(9) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(13) << endl;
	system("pause");
	return 0;
}

