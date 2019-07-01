#pragma once
#include "GlobalInc.h"

//用于全排列的类
template<typename Tp>
class Permutation
{
public:
	Permutation(vector<Tp>&src);//对全部数做全排列
	Permutation(vector<Tp>&src, size_t n);//取出n个数做排列

	//全排列
	vector<vector<Tp>>GetAll(bool allowDuplication=false);
	vector<Tp>GetNext(bool allowDuplication = false);
	bool GetNext(vector<Tp>&result, bool allowDuplication = false);

	//子集
	vector<vector<Tp>>GetSub(bool allowDuplication = false);
	vector<Tp>GetSub(bool allowDuplication = false);
	bool GetSub(vector<Tp>&result, bool allowDuplication = false);
private:
	Permutation();

	vector<Tp>&_src;
	vector<size_t>_ids;
	size_t _n;
};
//TODO:取模运算
class ModNumber//取模运算数
{
public:
	ModNumber(int mod);
	ModNumber(int64_t num, int mod);

	//加减乘除比较

	operator int64_t()const;
private:
	ModNumber();

};
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
//用于字符串分割的函数
//例如，split("2019-07-01","-")将获得{"2019","07","01"}
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
