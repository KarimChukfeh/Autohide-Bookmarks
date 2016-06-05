#include <windows.h>
#include <iostream>


using namespace std;
int main()
{
	static POINT point;
	while(true)
	{
		HWND hwnd=GetForegroundWindow();
		GetCursorPos(&point);
		std::cout << point.x << ", " << point.y << "\n";
		std::cout << GetPixel(
						GetDC(hwnd),
						point.x,
						point.y);
		std::cout << "\n";


		Sleep(1000);
	}
	
	
}