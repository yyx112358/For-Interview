// #include "..\������\GlobalInc.h"
// #include "..\������\ListArray.hpp"
// #include "..\������\BinTree.h"
// #include "..\������\Plot.h"
// #include <memory>
// #include <vld.h>
// 
// //������ӡvector��ģ�庯��
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
// 		priority_queue<int, vector<int>, std::greater<int>>qnum;//С���ѣ���¼ǰk�����Ԫ��
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
// 		vector<int>qnum;//��¼ǰk�����Ԫ�صĶ��У��Ӷ��׵���β�ݼ�
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
	int NumberOf1Between1AndN_Solution(int n)
	{
		vector<int>record{ 1,20,300,4000,50000,600000,7000000,80000000,900000000 };
		//[0,1]��0����[0,9]��1����[0,99]��10+10*1(10λ10�Σ�1λ10��)��[0,999]��100+100+100
		//��12345��1~9999��4000�Σ�10000~12345��2345+1��1������10000��
		int sum = 0;
		int i = 1;
		for (auto tmp = n; tmp > 9; tmp /= 10, i *= 10)
			;
		for (; i > 1; i /= 10)
		{
			//��22145����λ���ֹ�10000�Σ�ǧλ���ֹ�21*1000+1000�Σ���λ220*100+45�Σ�ʮλ2210*10+10����λ2214*1
			if (n / i > 1)
				sum += i;
			else//12345����λ���ֹ�2346��
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
	//��ά��˹�����
	static struct {
		const int kernalSize;//����˴�С
		const double sigma;//��׼��
		Mat kernal;//�����
	}paramRetinex[3] = { { 160, 10 },{ 160, 80, },{ 160, 150, }, };

	//Ҫ���ǻҶ�ͼ
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
		//��һ��ʱ��ʼ������ˣ���ά��˹����ˣ�
		if (paramRetinex[i].kernal.empty() == true)
		{
			//ֱ�۶��ٶȽ������㷨
			paramRetinex[i].kernal = cv::getGaussianKernel(paramRetinex[i].kernalSize, paramRetinex[i].sigma);//���һά��˹����ˣ�n*1��
			paramRetinex[i].kernal = paramRetinex[i].kernal*paramRetinex[i].kernal.t();//�Գ�ת�ã���Ϊ��ά�����
		}
		//ȡ���������������
		//ʹ���ڲ���������ָ����������ڲ���������ָ��Ͷ��߳��Ż�
		Mat  convMat;
		cv::filter2D(src, convMat, src.depth(), paramRetinex[i].kernal);
		cv::log(convMat, convMat);
		dst += (logMat - convMat)/* *1.0/3 */;
	}
	dst *= 1.0 / 3;//�ѳ�����Ϊ�˷��ŵ���������Ч��
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

