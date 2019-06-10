// #include "..\笔试用\GlobalInc.h"
// #include "..\笔试用\ListArray.hpp"
// #include "..\笔试用\BinTree.h"
// #include "..\笔试用\Plot.h"
// #include <memory>
// #include <vld.h>
// 
// //用来打印vector的模板函数
// template<typename Tp>
// ostream&operator<<(ostream&os, const vector<Tp>&v)
// {
// 	os << '[';
// 	for (auto &i : v)
// 		os << i << ',';
// 	os << ']' << endl;
// 	return os;
// }
// class Solution {
// public:
// 	int findKthLargest(vector<int>& nums, int k)
// 	{
// 		//if(k>nums.size())
// 		//    return;
// 		priority_queue<int, vector<int>, std::greater<int>>qnum;//小顶堆，记录前k个最大元素
// 		for (auto n : nums)
// 		{
// 			if (qnum.size() >= k)
// 			{
// 				if (n>qnum.top())
// 				{
// 					qnum.pop();
// 					qnum.push(n);
// 				}
// 			}
// 
// 			else
// 				qnum.push(n);
// 		}
// 		
// 		return qnum.top();
// 		/*
// 		vector<int>qnum;//记录前k个最大元素的队列，从队首到队尾递减
// 		for (auto n : nums)
// 		{
// 		if (qnum.size() < k || qnum.back() < n)
// 		{
// 		if (qnum.size() >= k)
// 		qnum.pop_back();
// 		int it = qnum.size() - 1;
// 		for (; it >= 0 && qnum[it] < n; --it)
// 		;
// 		++it;
// 		qnum.insert(qnum.begin() + it, n);
// 		}
// 		}
// 		return qnum[k - 1];
// 		*/
// 	}
// };
// 
// int main()
// {
// 	srand(0x411);
// 	Solution solution;
// 	cout << solution.findKthLargest(vector<int>{7,5,2,4,1,5,3,2,6,8,9,4},4) << endl;
// 
// 	system("pause");
// 	return 0;
// }
// 
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
		vector<int>record{ 1,20,300,4000,50000,600000,7000000,80000000,900000000 };
		//[0,1]有0个，[0,9]有1个，[0,99]有10+10*1(10位10次，1位10次)，[0,999]有100+100+100
		//如12345，1~9999有4000次，10000~12345有2345+1次1出现在10000，
		int sum = 0;
		int i = 1;
		for (auto tmp = n; tmp > 9; tmp /= 10, i *= 10)
			;
		for (; i > 1; i /= 10)
		{
			//如22145，万位出现过10000次，千位出现过21*1000+1000次，百位220*100+45次，十位2210*10+10，个位2214*1
			if (n / i > 1)
				sum += i;
			else//12345，万位出现过2346次
				sum += n - i + 1;
		}
// 		for (auto i = 1; i <= n; i++)
// 		{
// 			int tmp = i;
// 			while (tmp > 0)
// 			{
// 				if (tmp % 10 == 1)
// 					sum++;
// 				tmp /= 10;
// 			}
// 		}
		return sum;
		return sum;
	}
};
cv::Mat Retinex(cv::Mat src)
{
	//二维高斯卷积核
	static struct {
		const int kernalSize;//卷积核大小
		const double sigma;//标准差
		Mat kernal;//卷积核
	}paramRetinex[3] = { { 160, 10 },{ 160, 80, },{ 160, 150, }, };

	//要求是灰度图
	CV_Assert(src.empty() != true);
// 	if (src.empty() == true)
// 		return Mat();
	if (src.type() == CV_8UC3)
		cvtColor(src, src, CV_BGR2GRAY);
	Mat dst(src.size(), CV_32F, Scalar::all(0));
	src.convertTo(src, CV_32F);
	//	cout << (getTickCount() - startTick) / getTickFrequency() * 1000 <<"~";
	Mat logMat;
	cv::log(src, logMat);
	for (auto i = 0; i < 3; i++)
	{
		//第一次时初始化卷积核（二维高斯卷积核）
		if (paramRetinex[i].kernal.empty() == true)
		{
			//直观而速度较慢的算法
			paramRetinex[i].kernal = cv::getGaussianKernel(paramRetinex[i].kernalSize, paramRetinex[i].sigma);//获得一维高斯卷积核（n*1）
			paramRetinex[i].kernal = paramRetinex[i].kernal*paramRetinex[i].kernal.t();//自乘转置，变为二维卷积核
		}
		//取对数，卷积，做差
		//使用内部函数而非指针操作，因内部函数做了指令集和多线程优化
		Mat  convMat;
		cv::filter2D(src, convMat, src.depth(), paramRetinex[i].kernal);
		cv::log(convMat, convMat);
		dst += (logMat - convMat)/* *1.0/3 */;
	}
	dst *= 1.0 / 3;//把除法变为乘法放到最后以提高效率
				   //	cout << (getTickCount() - startTick) / getTickFrequency() * 1000 <<endl;
	return dst;
}
int main()
{
	srand(0x411);
	Solution solution;
	cout << solution.NumberOf1Between1AndN_Solution(22145) << endl;
	cout << solution.NumberOf1Between1AndN_Solution(12345) << endl;

	for(auto j=0;j<100;j++)
	{
		int i;
		i = rand(); cout << i << '\t' << solution.NumberOf1Between1AndN_Solution(i) << endl;
		i = rand(); cout << i << '\t' << solution.NumberOf1Between1AndN_Solution(i) << endl;
		i = rand(); cout << i << '\t' << solution.NumberOf1Between1AndN_Solution(i) << endl;
		i = rand(); cout << i << '\t' << solution.NumberOf1Between1AndN_Solution(i) << endl;
		i = rand(); cout << i << '\t' << solution.NumberOf1Between1AndN_Solution(i) << endl;
		i = rand(); cout << i << '\t' << solution.NumberOf1Between1AndN_Solution(i) << endl;
		i = rand(); cout << i << '\t' << solution.NumberOf1Between1AndN_Solution(i) << endl;
	}
	system("pause");
	return 0;
}

