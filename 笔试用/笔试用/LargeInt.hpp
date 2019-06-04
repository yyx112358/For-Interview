#pragma once
//https://www.cnblogs.com/rmthy/p/8644236.html
#include <iostream>
#include <vector>
#include <string>

typedef unsigned int uint;
typedef unsigned long long uint64;

#define MAX_VAL 1000000000 // 10��
#define VAL_LEN 9
#define FORMAT_STR "%09d"

//�������ࡣ֧�����ⳤ���޷�����������֧�ָ�����������
class LargeInt
{
public:
	LargeInt::LargeInt() {}

	LargeInt::LargeInt(uint val)
	{
		this->_data.push_back(val % MAX_VAL);
		if (val >= MAX_VAL)
			this->_data.push_back(val / MAX_VAL);
	}

	// �ַ�������
	//  valStr��ʮ�����ַ���
	LargeInt::LargeInt(const string &valStr)
	{
		if (checkValStr(valStr))
		{
			int len = valStr.length();
			// ������9��ȡ�Ӵ�
			while (len >= VAL_LEN)
			{
				string s = valStr.substr(len - VAL_LEN, VAL_LEN);
				this->_data.push_back(stoi(s));
				len -= VAL_LEN;
			}
			// �����Ӵ�
			if (len > 0)
			{
				string s = valStr.substr(0, len);
				this->_data.push_back(stoi(s));
			}
		}
		this->arrange(); // ȥ��
	}

	// �������������
	LargeInt LargeInt::operator+(const LargeInt &li) const
	{
		int         len1 = this->_data.size();
		int         len2 = li._data.size();

		int         minLen = len1 > len2 ? len2 : len1;
		int         maxLen = len1 > len2 ? len1 : len2;
		const LargeInt &extraLi = (len1 > len2) ? (*this) : li;

		uint        value = 0;  // �ͣ����������ֵ��2��
		uint        carry = 0;  // ��λ
		LargeInt    retVal;

		for (int idx = 0; idx < minLen; ++idx)
		{
			value = this->_data[idx] + li._data[idx] + carry;

			if (value >= MAX_VAL)
			{
				retVal._data.push_back(value - MAX_VAL);
				carry = 1;
			}
			else
			{
				retVal._data.push_back(value);
				carry = 0;
			}
		}

		for (int idx = minLen; idx < maxLen; ++idx)
		{
			value = extraLi._data[idx] + carry;

			if (value >= MAX_VAL)
			{
				retVal._data.push_back(value - MAX_VAL);
				carry = 1;
			}
			else
			{
				retVal._data.push_back(value);
				carry = 0;
			}
		}

		if (carry > 0)
			retVal._data.push_back(carry);

		//retVal.arrange(); // ȥ0����
		return retVal;
	}

	LargeInt LargeInt::operator-(const LargeInt &li) const
	{
		if (*this <= li)
		{
			return LargeInt(0);
		}

		int         len1 = this->_data.size();
		int         len2 = li._data.size();

		uint        value = 0;  // ��
		uint        carry = 0;  // ��λ
		LargeInt    retVal;

		for (int idx = 0; idx < len2; ++idx)
		{
			if (this->_data[idx] < li._data[idx] + carry) // ע��ϸ�ڣ�carry�����Ҳ࣬������ֲ�ֵΪ���������
			{
				value = this->_data[idx] + MAX_VAL - carry - li._data[idx];
				carry = 1;
			}
			else
			{
				value = this->_data[idx] - carry - li._data[idx];
				carry = 0;
			}

			retVal._data.push_back(value);
		}

		for (int idx = len2; idx < len1; ++idx)
		{
			if (this->_data[idx] < carry)
			{
				value = this->_data[idx] + MAX_VAL - carry;
				carry = 1;
			}
			else
			{
				value = this->_data[idx] - carry;
				carry = 0;
			}
			retVal._data.push_back(value);
		}

		retVal.arrange();
		return retVal;
	}

	LargeInt LargeInt::operator*(const LargeInt &li) const
	{
		int         len1 = this->_data.size();
		int         len2 = li._data.size();

		if (len1 < len2) return li.operator*(*this); // �Ż�����֤������λ�����ڳ���

		uint64      value;      // ��
		uint64      carry = 0;  // ��λ
		LargeInt    retVal(0);
		LargeInt    mulTemp;

		for (int idx2 = 0; idx2 < len2; ++idx2)
		{
			mulTemp._data.clear();
			carry = 0;

			// ����
			for (int tmpIdx = 0; tmpIdx < idx2; ++tmpIdx)
				mulTemp._data.push_back(0);

			for (int idx1 = 0; idx1 < len1; ++idx1)
			{
				value = (uint64)(li._data[idx2]) * (uint64)(this->_data[idx1]) + carry;

				mulTemp._data.push_back((uint)(value % MAX_VAL));
				carry = value / MAX_VAL;
			}

			if (carry)
				mulTemp._data.push_back((uint)carry);

			retVal = retVal + mulTemp;
		}

		return retVal;
	}

	LargeInt LargeInt::operator/(const LargeInt &li) const
	{
		if (li._data.empty() || li == 0) return LargeInt("");
		if (*this < li) return LargeInt(0);

		int         len1 = this->_data.size();
		int         len2 = li._data.size();

		uint        value;
		LargeInt    retVal;
		LargeInt    divTemp;

		for (int idx = len1 - len2 + 1; idx < len1; ++idx)
		{
			divTemp._data.push_back(this->_data[idx]);
		}

		// len1 >= len2
		for (int idx = len1 - len2; idx >= 0; --idx)
		{
			divTemp._data.insert(divTemp._data.begin(), this->_data[idx]);
			divTemp.arrange();

			value = getMaxCycle(divTemp, li); // ��

			divTemp = divTemp - li * value;   // ����  

			retVal._data.insert(retVal._data.begin(), value); // �������ɸ�λ���λ���У����Բ���λ����begin
		}

		retVal.arrange();
		return retVal;
	}

	LargeInt LargeInt::operator%(const LargeInt &li) const
	{
		if (li._data.empty() || li == 0) return LargeInt("");
		if (*this < li) return LargeInt(0);

		int         len1 = this->_data.size();
		int         len2 = li._data.size();

		uint        value;
		LargeInt    retVal;
		LargeInt    divTemp;

		for (int idx = len1 - len2 + 1; idx < len1; ++idx)
		{
			divTemp._data.push_back(this->_data[idx]);
		}

		// len1 >= len2
		for (int idx = len1 - len2; idx >= 0; --idx)
		{
			divTemp._data.insert(divTemp._data.begin(), this->_data[idx]);
			divTemp.arrange();

			value = getMaxCycle(divTemp, li); // ��

			divTemp = divTemp - li * value;   // ����  

			retVal._data.insert(retVal._data.begin(), value); // �������ɸ�λ���λ���У����Բ���λ����begin
		}

		divTemp.arrange();
		return divTemp;
	}
	// �Ƚ����������
	bool LargeInt::operator==(const LargeInt &li) const { return compare(li) == 0; }
	bool LargeInt::operator!=(const LargeInt &li) const { return compare(li) != 0; }
	bool LargeInt::operator<(const LargeInt &li) const { return compare(li) < 0; }
	bool LargeInt::operator>(const LargeInt &li) const { return compare(li) > 0; }
	bool LargeInt::operator<=(const LargeInt &li) const { return compare(li) <= 0; }
	bool LargeInt::operator>=(const LargeInt &li) const { return compare(li) >= 0; }
	string LargeInt::toString() const
	{
		int len = this->_data.size();
		int shift = 0;
		char *buff = new char[len * VAL_LEN + 1];

		if (len > 0)
			shift += sprintf(buff + shift, "%d", this->_data[len - 1]);

		for (int idx = len - 2; idx >= 0; --idx)
			shift += sprintf(buff + shift, FORMAT_STR, this->_data[idx]);
		buff[shift] = '\0';

		string retStr(buff);
		delete[] buff;

		return retStr;
	}
	friend std::ostream&operator<<(std::ostream&os, const LargeInt&li)
	{
		os << li.toString();
		return os;
	}
private:
	std::vector<uint>  _data;

	inline bool isDigit(const char ch) { return ch >= '0' && ch <= '9'; }

	// �ַ����Ϸ��Լ�飬ֻ��������ַ� 0~9
	bool checkValStr(const string &valStr)
	{
		for (auto it = valStr.begin(); it != valStr.end(); ++it)
			if (!isDigit(*it)) return false;
		return true;
	}

	// �ȽϺ�����0 ��ȣ�1 ���ڣ�-1 С��
	int LargeInt::compare(const LargeInt &li) const
	{
		int len1 = this->_data.size();
		int len2 = li._data.size();

		// step1: �Ƚϳ���
		if (len1 != len2)
			return (len1 > len2) ? 1 : -1;

		// step2: �ɸ�λ����λ�Ƚ�ֵ
		for (int idx = len1 - 1; idx >= 0; --idx)
		{
			if (this->_data[idx] == li._data[idx]) continue;
			return this->_data[idx] > li._data[idx] ? 1 : -1;
		}

		return 0;
	}
	// ȥ������������������еĸ�λ���ڶ������
	void LargeInt::arrange()
	{
		int idx = this->_data.size();
		// ע�⣬���������ȫΪ0��Ҫ�������λ��0
		while (--idx >= 1)
		{
			if (this->_data[idx] > 0) break;
			this->_data.pop_back();
		}
	}

	// ������ֵ
	uint LargeInt::getMaxCycle(const LargeInt &liA, const LargeInt &liB) const
	{
		LargeInt        tempA = liA;
		const LargeInt& tempB = liB;
		uint            tempC;
		uint            res = 0;
		bool            flag = true;
		while (tempA >= tempB)
		{
			tempC = estimateQuotient(tempA, tempB);
			tempA = tempB * tempC - tempA;

			res = flag ? (res + tempC) : (res - tempC);
			flag = !flag;
		}
		// ΢�� 
		while (res > 0 && liB * res > liA) res--;
		return res;
	}

	// ��ֵ
	uint LargeInt::estimateQuotient(const LargeInt &liA, const LargeInt &liB) const
	{
		int         lenA = liA._data.size();
		int         lenB = liB._data.size();
		uint64      valA, valB;

		if (lenA == lenB)
		{
			if (lenA > 1)
			{
				valA = (uint64)liA._data[lenA - 1] * MAX_VAL + liA._data[lenA - 2];
				valB = (uint64)liB._data[lenB - 1] * MAX_VAL + liB._data[lenB - 2];
			}
			else
			{
				valA = (uint64)liA._data[lenA - 1];
				valB = (uint64)liB._data[lenB - 1];
			}
		}
		else
		{
			valA = (uint64)liA._data[lenA - 1] * MAX_VAL + liA._data[lenA - 2];
			valB = (uint64)liB._data[lenB - 1];
		}
		return (uint)(valA / valB);
	}
};

#undef MAX_VAL
#undef VAL_LEN
#undef FORMAT_STR
