#include "..\笔试用\GlobalInc.h"
#include "..\笔试用\ListArray.hpp"
#include "..\笔试用\BinTree.h"
#include "..\笔试用\Plot.h"
#include <memory>
#include <vld.h>

/*

*/
class Solution_VerifySquenceOfBST {
public:
	bool VerifySquenceOfBST(vector<int> sequence) 
	{
		if (sequence.size() <= 2)
			return true;
		return _VerifySquenceOfBST(sequence, 0, sequence.size());
	}
	bool _VerifySquenceOfBST(const vector<int> &sequence, int begin, int end)
	{
		if (end-begin <= 2)//如果只有2个数，必定成立
			return true;
		int root = sequence[end-1];
		int i = begin;
		for (; i < end - 1 && sequence[i] < root; ++i)
			;
		for (auto j = i; j < end - 1; j++)
			if (sequence[j] < root)
				return false;
		return _VerifySquenceOfBST(sequence, begin, i) == true
			&& _VerifySquenceOfBST(sequence, i, end - 1) == true;
	}
};

int main()
{
	srand(0x411);

	Solution_VerifySquenceOfBST solution;
	cout << (solution.VerifySquenceOfBST(vector<int>{1}) ? "true" : "false") << endl;

	cout << (solution.VerifySquenceOfBST(vector<int>{7,4,6,5}) ? "true" : "false") << endl;
	cout << (solution.VerifySquenceOfBST(vector<int>{5,7,6,9,11,10,8}) ? "true" : "false") << endl;
	cout << (solution.VerifySquenceOfBST(vector<int>{5, 6, 11, 10, 8}) ? "true" : "false") << endl;
	cout << (solution.VerifySquenceOfBST(vector<int>{5, 6, 11, 10, 10, 8}) ? "true" : "false") << endl;

	system("pause");
	return 0;
}

