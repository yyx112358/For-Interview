// #include "..\笔试用\GlobalInc.h"
// #include "..\笔试用\ListArray.hpp"
// #include "..\笔试用\BinTree.h"
// #include "..\笔试用\Plot.h"
// #include <memory>
// #include <vld.h>



#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
//#include <xfunctional>
#include <functional>
#include <random>
#include <numeric>
#include <assert.h>
#include <time.h>
#include <array>
#include <bitset>

using namespace std;

//用来打印vector的模板函数
template<typename Tp>
ostream&operator<<(ostream&os, const vector<Tp>&v)
{
	os << '[';
	for (auto i : v)
		os << i << ',';
	os << ']' << endl;
	return os;
}

std::vector<std::string> split(std::string str, const std::string& pattern)
{
	size_t pos;
	std::vector<std::string> result;

	str += pattern;//扩展字符串以方便操作
	size_t size = str.size();

	for (size_t i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

int waste(int N)
{
	if (N % 150 == 0 || N % 200 == 0 || N % 250 == 0)
		return 0;
	
	int left = 99999999;

	N %= 120 * 50;

	if (N % 350 > 200)
		left=min( N % 350 - 200,left);
	else if (N % 350 > 150)
		left = min(N % 350 - 200, left);
	else
		left = min(N % 350, left);

	if (N % 200 > 150)
		left = min(N % 200 - 150, left);
	else
		left = min(N % 200, left);

	left = min(N % 150, left);

	return left;
}
/*
2
340
900
*/
int main()
{
	int t;
	cin >> t;
	for (auto i = 0; i < t; i++)
	{
		int N;
		cin >> N;
		cout << waste(N) << endl;
	}
#ifdef _DEBUG
	system("pause");
#endif // _DEBUG
	return 0;
}