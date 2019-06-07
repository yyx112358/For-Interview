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
	vector<vector<Tp>>GetAll();
	vector<Tp>GetNext();
	bool GetNext(vector<Tp>&result);

	//子集
	vector<vector<Tp>>GetSub();
	vector<Tp>GetSub();
	bool GetSub(vector<Tp>&result);
private:
	Permutation();

	vector<Tp>&_src;
	vector<size_t>_ids;
	size_t _n;
};

class ModNumber//取模运算数
{
public:
	ModNumber(int mod);
	ModNumber(int64_t num, int mod);

	//TODO:加减乘除比较
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