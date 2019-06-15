#include<iostream>
#include <vector>
#include<string>
using namespace std;
int main()
{
	int x1, k1, x2, k2;
	cin >> x1 >> k1 >> x2 >> k2;
	int p1=0;
	int p2=0;
	bool flag = false;
	string s1 = to_string(x1);
	string s2 = to_string(x2);
	if (s1.size()*k1 > s2.size() *k2)
	{
		cout << "Greater" << endl;
		system("pause");
		return 0;
	}
	else if (s1.size()*k1 < s2.size() * k2)
	{
		cout << "Less" << endl;
		system("pause");
		return 0;
	}
	else
	{
		while (flag == false)
		{
			if (s1[p1] > s2[p2])
			{
				cout << "Greater" << endl;
				flag = true;
			}
			else if (s1[p1] < s2[p2])
			{
				cout << "Less" << endl;
				flag = true;
			}
			else
			{
				p1++;
				p2++;
				if (p1 >= s1.size() && k1 > 0)
				{
					p1 = 0;
					k1--;
				}
				if (p2 >= s2.size() && k2 > 0)
				{
					p2 = 0;
					k2--;
				}
			}
			if (k1 == 0 && k2 == 0 && p1 == 0&& p2 == 0)
			{
				cout << "Equal" << endl;
				flag = true;
			}

		}
		system("pause");
		return 0;
	}
}