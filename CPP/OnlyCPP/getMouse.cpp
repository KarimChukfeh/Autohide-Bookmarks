#include <windows.h>
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	static POINT point;
	while(true)
	{
		HWND hwnd=GetForegroundWindow();
		HDC hdc_ = GetDC(GetDesktopWindow());
		
		GetCursorPos(&point);
 		std::cout << point.x << ", " << point.y << "\n";
/* 		std::cout << GetPixel(
						GetDC(hwnd),
						point.x,
						point.y);
						
		std::cout << "\n"; */ 
		
	COLORREF pColor = GetPixel(hdc_, 92, 79);
	
	printf("%d, %d , %d", GetRValue(pColor), GetGValue(pColor), GetBValue(pColor));
	
	std::cout << "\n";
	
	printf("%d, %d , %d", GetRValue(pColor)-2, GetGValue(pColor)-2, GetBValue(pColor)-2);
	
	std::cout << "\n";
	
	printf("%d, %d , %d", GetRValue(pColor)-4, GetGValue(pColor)-4, GetBValue(pColor)-4);
	
	std::cout << "\n";
	
	printf("%d, %d , %d", GetRValue(pColor)-6, GetGValue(pColor)-6, GetBValue(pColor)-6);
	
	std::cout << "\n";
	
	printf("%d, %d , %d", GetRValue(pColor)-8, GetGValue(pColor)-8, GetBValue(pColor)-8);
	
	std::cout << "\n";
	
	
/* 	COLORREF mColor = GetPixel(hdc_, point.x-2, point.y-2);
	
	printf("%d, %d , %d", GetRValue(mColor), GetGValue(mColor), GetBValue(mColor)); */
	
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

		Sleep(1000);
	}
	
	
}