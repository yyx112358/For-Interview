#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int64_t size;
	cin >> size;
	vector<int64_t>vec;
	vector<int64_t>result;
	int64_t word;
	while (cin >> word)
	{
		vec.push_back(word);
	}
	sort(vec.begin(), vec.end());
	int left = 0;
	int right = vec.size() - 2;
	result.push_back(vec[size - 1]);
	bool flag = false;
	while (left < right)
	{
		if (flag == false)
		{
			result.insert(result.begin(),vec[left]);
			result.insert(result.end(), vec[left + 1]);
			left += 2;
			flag = true;
		}
		else
		{
			result.insert(result.begin(), vec[right]);
			result.insert(result.end(), vec[right - 1]);
			flag = false;
			right -= 2;
		}
	}
	if (size % 2 == 0)
		result.insert(result.begin(), vec[left]);
	if (abs(result[size - 1] - result[size - 2]) < abs(result[size - 1] - result[0]))
	{
		result.insert(result.begin(), result[size - 1]);
		result.erase(result.end()-1);
	}
	int re = 0;
	for (int i = 1; i < result.size(); ++i)
	{
		re += abs(result[i] - result[i - 1]);
	}
	cout << re << endl;
	system("pause");
	return 0;
}