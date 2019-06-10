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
		vector<int>record{1,20,300,4000,50000,600000,7000000,80000000,900000000};
		//[0,1]有0个，[0,9]有1个，[0,99]有10+10*1(10位10次，1位10次)，[0,999]有100+100+100
		//如12345，1~9999有4000次，10000~12345有2345+1次1出现在10000，
		int sum = 0;
		for (auto i = 1; i <= n; i++)
		{
			int tmp = i;
			while (tmp > 0)
			{
				if (tmp % 10 == 1)
					sum++;
				tmp /= 10;
			}
		}
		return sum;
	}
};

int main()
{
	srand(0x411);
	Solution solution;
	cout << solution.NumberOf1Between1AndN_Solution(1) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(9) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(13) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(99) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(999) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(9999) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(99999) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(12345) << endl;

	system("pause");
	return 0;
}

