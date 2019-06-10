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
	int maxSubArray(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return 0;
		int maxSum = nums[0];//曾经出现过的最大子序列和
		int sum = nums[0];//以nums[i]为结尾最大子序列和
		for (auto i = 1; i < nums.size(); ++i)
		{
			//如果以nums[i-1]为结尾最大子序列和sum为负数，则加上nums[i]后必定比nums[i]还小
			//此时可以直接抛弃以nums[i-1]为结尾最大子序列，从nums[i]开始计算
			//如果为正数，则可以添加上以nums[i-1]为结尾最大子序列，sum+=nums[i]
			//最终结果是遍历中曾经出现的最大子序列和
			if (sum >= 0)
				sum += nums[i];
			else
				sum = nums[i];
			maxSum = max(maxSum, sum);//maxSum是曾经出现过的最大子序列和
		}
		return maxSum;
	}
};

int main()
{
	srand(0x411);
	Solution solution;
	cout << solution.maxSubArray(vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;

	system("pause");
	return 0;
}

