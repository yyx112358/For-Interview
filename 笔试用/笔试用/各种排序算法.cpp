#include "GlobalInc.h"

//简单选择排序（不稳定）
//任何情况时间复杂度O(N^2)
//空间复杂度O(1)
void SelectionSort(vector<int>&nums)
{
	const size_t size = nums.size();
	for (auto i = 0u; i < size - 1; i++)
	{
		auto minId = i;
		for (auto j = i + 1; j < size; j++)//找到序号i之后的部分中最小元素，即第i小的元素
			if (nums[j] < nums[minId])
				minId = j;
		swap(nums[i], nums[minId]);//交换这个第i小元素到第i个位置
	}
}
//冒泡排序（稳定）
//时间复杂度O(N^2)，最佳O(N)(基本有序，且需加入一个bool来判定一趟排序中没有发生交换)
//空间复杂度O(1)
void BubbleSort(vector<int>&nums)
{
	const size_t size = nums.size();
	for (auto i = 0u; i < size; i++)
	{
		for (auto j = 0u; j < size - i - 1; j++)//遍历前size-i-1个，如果比后面1个大就交换
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
	}
}
//简单插入排序（稳定）
//时间复杂度平均O(N^2)，最佳O(N)（基本被排序）。很适合数据量小时的排序
//空间复杂度O(1)
void InsertSort(vector<int>&nums)
{
	const size_t size = nums.size();
	for (auto i = 1u; i < size; ++i)
	{
		int tmp = nums[i];
		auto j = i;
		while (j >= 1 && tmp <= nums[j - 1])//将比nums[i]大的都向后移动一位
			nums[j--] = nums[j - 1];
		nums[j] = tmp;//把nums[i]插入到相应位置
	}
}
//希尔排序（不稳定）
//在希尔增量（增量每次折半）下平均时间复杂度O(nlogn)，最坏O(N^2)
//其它某些序列下，能达到O(N^(3/2))，希尔增量的选择和证明是一个数学难题
//空间复杂度O(1)
void ShellSort(vector<int>&nums)
{
	const int size = nums.size();//注意这里改成int类型而不是size_t，否则会隐式转换为size_t得不到负数
	for (int gap = size / 2; gap >= 1; gap /= 2)//每次排序增量减少，直至最后为1排序完成（这个序列不是最优）
	{
		for (int i = gap; i < size; i++)//对(i,i-gap,i-2*gap)进行插入排序
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
	int pivot = nums[begin];//取第一个为pivot（不是个好选择，比较好的是三数取中）
	int i = begin, j = end + 1;
	while (1)
	{
		//找到右边第一个比pivot小的元素（不取等，为了防止因存在相同元素越界）
		//不用判定越界，因为pivot放在最左边，最多出现如4,8,7,6这种情况，使得nums[j]==pivot
		while (pivot < nums[--j]);
		//从左边开始找到第一个比pivot大的元素
		//i<=end为了防止越界
		//放在前面，保证即使出现4,3,1,2这种没有找到一个比pivot大元素的情况下，i会到end+1
		//	此时，后面j将等于end，使得i>j，跳出。如果i<=end放前面，将会使得i==j==end
		while (++i <= end && nums[i] < pivot);
		if (i <= j)//找到了，交换（大的换左边，小的换右边）
			swap(nums[i], nums[j]);
		else
		{
			swap(nums[begin], nums[j]);//交换前，nums[j]要么比pivot小，要么是pivot，因此交换后必定能保证交换后的pivot左边比他小
			break;
		}
	}
	//对余下部分递归排序
	_QuickSort(nums, begin, j - 1);
	_QuickSort(nums, j + 1, end);
	//优化：pivot使用三数取中，数字小的时候改快排为插排，将相等元素聚集
	/*//首先获取一个枢纽元，比较好的方法是三数取中（首、中间、末三个元素在中间那个）
	//如果直接取第一个，当碰到大致一样的数组时会退化为O(N^2)即冒泡排序
	int pivotId;
	{
	//对首中末三元素排序
	int mid = begin + (end - begin) >> 1;
	if (nums[begin] > nums[mid])swap(nums[begin], nums[mid]);
	if (nums[begin] > nums[end])swap(nums[begin], nums[end]);
	if (nums[mid] > nums[end])swap(nums[mid], nums[end]);
	//将中间元素存储在
	}*/

}
void QuickSort(vector<int>&nums)
{
	_QuickSort(nums, 0, nums.size() - 1);
}