#include "..\������\GlobalInc.h"
#include "..\������\ListArray.hpp"
#include "..\������\BinTree.h"
#include "..\������\Plot.h"
#include <memory>
#include <vld.h>

//������ӡvector��ģ�庯��
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
		int maxSum = nums[0];//�������ֹ�����������к�
		int sum = nums[0];//��nums[i]Ϊ��β��������к�
		for (auto i = 1; i < nums.size(); ++i)
		{
			//�����nums[i-1]Ϊ��β��������к�sumΪ�����������nums[i]��ض���nums[i]��С
			//��ʱ����ֱ��������nums[i-1]Ϊ��β��������У���nums[i]��ʼ����
			//���Ϊ������������������nums[i-1]Ϊ��β��������У�sum+=nums[i]
			//���ս���Ǳ������������ֵ���������к�
			if (sum >= 0)
				sum += nums[i];
			else
				sum = nums[i];
			maxSum = max(maxSum, sum);//maxSum���������ֹ�����������к�
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

