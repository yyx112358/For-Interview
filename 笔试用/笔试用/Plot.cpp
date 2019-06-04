#include "Plot.h"
#include <windows.h>

#include <TCHAR.h>

struct 
{
	HWND hwnd;
	SIZE size;
	int key;
}_plotWindow;

#define __BEGIN__  _InitSystem();auto hdc = GetDC(_plotWindow.hwnd);
#define __END__ ReleaseDC(_plotWindow.hwnd, hdc);

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
);

static int _InitSystem()
{
	if(_plotWindow.hwnd==nullptr)
	{
		HINSTANCE hInstance;
		hInstance = GetModuleHandle(NULL);
		WNDCLASS Draw;
		Draw.cbClsExtra = 0;
		Draw.cbWndExtra = 0;
		Draw.hCursor = LoadCursor(hInstance, IDC_ARROW);;
		Draw.hIcon = LoadIcon(hInstance, IDI_APPLICATION);;
		Draw.lpszMenuName = NULL;
		Draw.style = CS_HREDRAW | CS_VREDRAW;
		Draw.hbrBackground = (HBRUSH)COLOR_WINDOW;
		Draw.lpfnWndProc = WindowProc;
		Draw.lpszClassName = _T("DDraw");
		Draw.hInstance = hInstance;
		
		RegisterClass(&Draw);

		_plotWindow.hwnd = CreateWindow(
			_T("DDraw"),           //上面注册的类名，要完全一致  
			"test",  //窗口标题文字  
			WS_OVERLAPPEDWINDOW^WS_THICKFRAME, //窗口外观样式  
			38,             //窗口相对于父级的X坐标  
			20,             //窗口相对于父级的Y坐标  
			640,                //窗口的宽度  
			480,                //窗口的高度  
			NULL,               //没有父窗口，为NULL  
			NULL,               //没有菜单，为NULL  
			hInstance,          //当前应用程序的实例句柄  
			NULL);              //没有附加数据，为NULL  


		// 显示窗口  
		ShowWindow(_plotWindow.hwnd, SW_SHOW);

		// 更新窗口  
		UpdateWindow(_plotWindow.hwnd);
	}
	return 0;
}

bool _stdcall Ellipse(int left, int top, int right, int bottom)
{
	__BEGIN__;	
	bool b= Ellipse(hdc, left, top, right, bottom);
	__END__;	
	return b;
}

bool _stdcall Circle(int ox, int oy, int radius)
{
	return Ellipse(ox - radius, oy - radius, ox + radius, oy + radius);
}

bool _stdcall Line(int ax, int ay, int bx, int by)
{
	__BEGIN__;
	if(MoveToEx(hdc, ax, ay, nullptr)==false)
		return false;
	if(LineTo(hdc, bx, by)==false)
		return false;
	__END__;
	return true;
}

bool _stdcall Text(int x, int y, const string& str)
{
	__BEGIN__;
	bool b = TextOut(hdc, x, y, str.c_str(), str.size());
	__END__;
	return b;
}

bool _stdcall Rectangle(int left, int top, int right, int bottom)
{
	__BEGIN__;
	bool b = Rectangle(hdc, left, top, right, bottom);
	__END__;
	return b;
}

bool _stdcall ClearWindow()
{
	_InitSystem();
	RECT rect;
	GetClientRect(_plotWindow.hwnd, &rect);
	MoveWindow(_plotWindow.hwnd, rect.left, rect.top,
		rect.right-rect.left, rect.bottom-rect.top, true);
	return true;
}

bool _stdcall SetWindowSize(int nWidth, int nHeight, bool bRepaint /*= true*/)
{
	_InitSystem();
	RECT rect;
	GetClientRect(_plotWindow.hwnd, &rect);
	MoveWindow(_plotWindow.hwnd, rect.left, rect.top, nWidth, nHeight, bRepaint);
	return true;
}



Rect _stdcall GetWindowSize()
{
	Rect result(-1, -1, -1, -1);
	//__BEGIN__;

	RECT rect;
	GetClientRect(_plotWindow.hwnd, &rect);
	{
		POINT pt = { rect.left, rect.top };
		ClientToScreen(_plotWindow.hwnd, &pt);
		result = Rect(pt.x, pt.y, rect.right - rect.left, rect.bottom - rect.top);
	}
	//__END__;
	return result;
}

int WaitKey(int ms)
{
	_plotWindow.key = -1;
	_InitSystem();
	// 消息循环  
	MSG msg;
	clock_t clk = clock();
	if (ms < 0)
		ms = INT_MAX;
	while (GetMessage(&msg, NULL, 0, 0) && clock() - clk < ms&&_plotWindow.key==-1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	auto key = _plotWindow.key;
	_plotWindow.key = -1;
	return key;
}
// 消息处理函数的实现
LRESULT CALLBACK WindowProc(
	_In_  HWND hwnd,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)
{
	//int wmId, wmEvent;
	//static int nTypy = TYPE_LINE;
	switch (uMsg)
	{
	case WM_PAINT:
	{
		__BEGIN__;

		// TODO: 在此添加任意绘图代码...
// 		MoveToEx(hdc, 120, 120, nullptr);
// 		LineTo(hdc, 70, 220);
// 		Ellipse(100, 100, 150, 150);
// 		TextOut(hdc, 120, 120, _T("1"), _tcslen(_T("1")));
// 		Ellipse(50, 200, 100, 250);
// 		TextOut(hdc, 70, 220, _T("2"), _tcslen(_T("1")));

		__END__;
		break;
	}
	case WM_KEYUP:
	{
		_plotWindow.key = wParam;
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		_plotWindow.hwnd = nullptr;
		return 0;
	}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
