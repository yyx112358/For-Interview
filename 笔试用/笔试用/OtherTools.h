#pragma once
#include "GlobalInc.h"

//����ȫ���е���
template<typename Tp>
class Permutation
{
public:
	Permutation(vector<Tp>&src);//��ȫ������ȫ����
	Permutation(vector<Tp>&src, size_t n);//ȡ��n����������

	//ȫ����
	vector<vector<Tp>>GetAll();
	vector<Tp>GetNext();
	bool GetNext(vector<Tp>&result);

	//�Ӽ�
	vector<vector<Tp>>GetSub();
	vector<Tp>GetSub();
	bool GetSub(vector<Tp>&result);
private:
	Permutation();

	vector<Tp>&_src;
	vector<size_t>_ids;
	size_t _n;
};

class ModNumber//ȡģ������
{
public:
	ModNumber(int mod);
	ModNumber(int64_t num, int mod);

	//TODO:�Ӽ��˳��Ƚ�
private:
	ModNumber();

};
//������ӡvector��ģ�庯��
template<typename Tp>
ostream&operator<<(ostream&os, const vector<Tp>&v)
{
	os << '[';
	for (auto i : v)
		os << i << ',';
	os << ']' << endl;
	return os;
}