#pragma once
#include "GlobalInc.h"
struct Rect
{
	long left;
	long top;
	long right;
	long bottom;

	Rect(long _left, long _top, long _right, long _bottom)
		:left(_left),top(_top),right(_right),bottom(_bottom){}
	long width()const { return right - left; }
	long height() const{ return bottom - top; }
};

bool _stdcall Ellipse(int left, int top, int right, int bottom);
bool _stdcall Circle(int ox, int oy, int radius);
bool _stdcall Line(int ax, int ay, int bx, int by);
bool _stdcall Text(int x, int y, const string& str);
bool _stdcall Rectangle(int left, int top, int right, int bottom);

bool _stdcall ClearWindow();
bool _stdcall SetWindowSize(int X, int Y, int nWidth, int nHeight, bool bRepaint = true);
Rect _stdcall GetWindowSize();

int WaitKey(int ms);