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
	vector<vector<Tp>>GetAll(bool allowDuplication=false);
	vector<Tp>GetNext(bool allowDuplication = false);
	bool GetNext(vector<Tp>&result, bool allowDuplication = false);

	//�Ӽ�
	vector<vector<Tp>>GetSub(bool allowDuplication = false);
	vector<Tp>GetSub(bool allowDuplication = false);
	bool GetSub(vector<Tp>&result, bool allowDuplication = false);
private:
	Permutation();

	vector<Tp>&_src;
	vector<size_t>_ids;
	size_t _n;
};
//TODO:ȡģ����
class ModNumber//ȡģ������
{
public:
	ModNumber(int mod);
	ModNumber(int64_t num, int mod);

	//�Ӽ��˳��Ƚ�

	operator int64_t()const;
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