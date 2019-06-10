#include "GlobalInc.h"

//��ѡ�����򣨲��ȶ���
//�κ����ʱ�临�Ӷ�O(N^2)
//�ռ临�Ӷ�O(1)
void SelectionSort(vector<int>&nums)
{
	const size_t size = nums.size();
	for (auto i = 0u; i < size - 1; i++)
	{
		auto minId = i;
		for (auto j = i + 1; j < size; j++)//�ҵ����i֮��Ĳ�������СԪ�أ�����iС��Ԫ��
			if (nums[j] < nums[minId])
				minId = j;
		swap(nums[i], nums[minId]);//���������iСԪ�ص���i��λ��
	}
}
//ð�������ȶ���
//ʱ�临�Ӷ�O(N^2)�����O(N)(���������������һ��bool���ж�һ��������û�з�������)
//�ռ临�Ӷ�O(1)
void BubbleSort(vector<int>&nums)
{
	const size_t size = nums.size();
	for (auto i = 0u; i < size; i++)
	{
		for (auto j = 0u; j < size - i - 1; j++)//����ǰsize-i-1��������Ⱥ���1����ͽ���
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
	}
}
//�򵥲��������ȶ���
//ʱ�临�Ӷ�ƽ��O(N^2)�����O(N)�����������򣩡����ʺ�������Сʱ������
//�ռ临�Ӷ�O(1)
void InsertSort(vector<int>&nums)
{
	const size_t size = nums.size();
	for (auto i = 1u; i < size; ++i)
	{
		int tmp = nums[i];
		auto j = i;
		while (j >= 1 && tmp <= nums[j - 1])//����nums[i]��Ķ�����ƶ�һλ
			nums[j--] = nums[j - 1];
		nums[j] = tmp;//��nums[i]���뵽��Ӧλ��
	}
}
//ϣ�����򣨲��ȶ���
//��ϣ������������ÿ���۰룩��ƽ��ʱ�临�Ӷ�O(nlogn)���O(N^2)
//����ĳЩ�����£��ܴﵽO(N^(3/2))��ϣ��������ѡ���֤����һ����ѧ����
//�ռ临�Ӷ�O(1)
void ShellSort(vector<int>&nums)
{
	const int size = nums.size();//ע������ĳ�int���Ͷ�����size_t���������ʽת��Ϊsize_t�ò�������
	for (int gap = size / 2; gap >= 1; gap /= 2)//ÿ�������������٣�ֱ�����Ϊ1������ɣ�������в������ţ�
	{
		for (int i = gap; i < size; i++)//��(i,i-gap,i-2*gap)���в�������
		{
			int tmp = nums[i];
			int j;
			for (j = i; j >= gap && tmp <= nums[j - gap]; j -= gap)
				nums[j] = nums[j - gap];
			nums[j] = tmp;
		}
	}
}

void _QuickSort(vector<int>&nums, int begin, int end)
{
	if (!(0 <= begin&&begin < end&&end < nums.size()))
		return;
	int pivot = nums[begin];//ȡ��һ��Ϊpivot�����Ǹ���ѡ�񣬱ȽϺõ�������ȡ�У�
	int i = begin, j = end + 1;
	while (1)
	{
		//�ҵ��ұߵ�һ����pivotС��Ԫ�أ���ȡ�ȣ�Ϊ�˷�ֹ�������ͬԪ��Խ�磩
		//�����ж�Խ�磬��Ϊpivot��������ߣ���������4,8,7,6���������ʹ��nums[j]==pivot
		while (pivot < nums[--j]);
		//����߿�ʼ�ҵ���һ����pivot���Ԫ��
		//i<=endΪ�˷�ֹԽ��
		//����ǰ�棬��֤��ʹ����4,3,1,2����û���ҵ�һ����pivot��Ԫ�ص�����£�i�ᵽend+1
		//	��ʱ������j������end��ʹ��i>j�����������i<=end��ǰ�棬����ʹ��i==j==end
		while (++i <= end && nums[i] < pivot);
		if (i <= j)//�ҵ��ˣ���������Ļ���ߣ�С�Ļ��ұߣ�
			swap(nums[i], nums[j]);
		else
		{
			swap(nums[begin], nums[j]);//����ǰ��nums[j]Ҫô��pivotС��Ҫô��pivot����˽�����ض��ܱ�֤�������pivot��߱���С
			break;
		}
	}
	//�����²��ֵݹ�����
	_QuickSort(nums, begin, j - 1);
	_QuickSort(nums, j + 1, end);
	//�Ż���pivotʹ������ȡ�У�����С��ʱ��Ŀ���Ϊ���ţ������Ԫ�ؾۼ�
	/*//���Ȼ�ȡһ����ŦԪ���ȽϺõķ���������ȡ�У��ס��м䡢ĩ����Ԫ�����м��Ǹ���
	//���ֱ��ȡ��һ��������������һ��������ʱ���˻�ΪO(N^2)��ð������
	int pivotId;
	{
	//������ĩ��Ԫ������
	int mid = begin + (end - begin) >> 1;
	if (nums[begin] > nums[mid])swap(nums[begin], nums[mid]);
	if (nums[begin] > nums[end])swap(nums[begin], nums[end]);
	if (nums[mid] > nums[end])swap(nums[mid], nums[end]);
	//���м�Ԫ�ش洢��
	}*/

}
void QuickSort(vector<int>&nums)
{
	_QuickSort(nums, 0, nums.size() - 1);
}