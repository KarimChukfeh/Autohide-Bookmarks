#define WINVER 0x0500
#define WM_WINDOWPOSCHANGED
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;



string GetActiveWindowTitle()
{
 
	char wnd_title[256];
 
	HWND hwnd=GetForegroundWindow(); 
	GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
 
	return wnd_title;
}


int GetYPos()
{
	
	HWND hwnd=GetForegroundWindow();
	RECT r1;
	
	GetWindowRect(hwnd, &r1);
	return r1.top;
}

int GetLeftPos()
{
	
	HWND hwnd=GetForegroundWindow();
	RECT r1;
	
	GetWindowRect(hwnd, &r1);
	return r1.left;
}

int GetRightPos()
{
	
	HWND hwnd=GetForegroundWindow();
	RECT r1;
	
	GetWindowRect(hwnd, &r1);
	return r1.right;
}

bool PixelIsYellow(){
	HDC hdc_ = GetDC(GetDesktopWindow());
	string color;
	int y = GetYPos();
	int x = GetLeftPos();
	std::cout<<"\n"<<x<<","<<y<<"\n";
	
	COLORREF pColor = GetPixel(hdc_, x+92, y+79);
	
	std::cout<< (((GetRValue(pColor) == 255)
			&&
			(GetGValue(pColor) == 216)
			&&
			(GetBValue(pColor) == 144)));
			
	return ((GetRValue(pColor) == 255)
			&&
			(GetGValue(pColor) == 216)
			&&
			(GetBValue(pColor) == 144));
}

int main()
{
	
	 INPUT leftctrl;
	 INPUT leftshft;
	 INPUT bkey;
	
	 leftctrl.type = INPUT_KEYBOARD;
	 leftctrl.ki.wScan = 0;
	 leftctrl.ki.time = 0;
	 leftctrl.ki.dwExtraInfo = 0;
	 
	 leftshft.type = INPUT_KEYBOARD;
	 leftshft.ki.wScan = 0;
	 leftshft.ki.time = 0;
	 leftshft.ki.dwExtraInfo = 0;

	 bkey.type = INPUT_KEYBOARD;
	 bkey.ki.wScan = 0;
	 bkey.ki.time = 0;
	 bkey.ki.dwExtraInfo = 0;
	 
	 static POINT point;
	
	do
	{

		if(GetActiveWindowTitle().find("Google Chrome") != std::string::npos)
		{

			do
			{	
				 GetCursorPos(&point);
				 Sleep(16);
				if(
					((point.y - 11) < (GetYPos() + 62))&&
					(point.x>GetLeftPos())&&
					(point.x<GetRightPos())
					&&
					!(((point.y-10) < (GetYPos()+16))&&
					(point.x>GetLeftPos())&&
					(point.x>(GetRightPos()-120)))
					&&
					!(((point.y-10) < (GetYPos()+75))&&
					(point.x>GetLeftPos())&&
					(point.x>(GetRightPos()-38)))	
				  )
				{
					
				 leftctrl.ki.wVk = VK_CONTROL;
				 leftctrl.ki.dwFlags = 0;
				 
				 
				 leftshft.ki.wVk = VK_SHIFT;
				 leftshft.ki.dwFlags = 0;
				

				 bkey.ki.wVk = 0x42;
				 bkey.ki.dwFlags = 0;
				 
				 SendInput(1, &leftctrl, sizeof(INPUT));
				 SendInput(1, &leftshft, sizeof(INPUT));
				 SendInput(1, &bkey, sizeof(INPUT));
				 
				 
				 //Sleep(16);
				 
				 leftctrl.ki.dwFlags = KEYEVENTF_KEYUP;
				 leftshft.ki.dwFlags = KEYEVENTF_KEYUP;
				 bkey.ki.dwFlags = KEYEVENTF_KEYUP;
				 
				 SendInput(1, &leftctrl, sizeof(INPUT));
				 SendInput(1, &leftshft, sizeof(INPUT));					 
				 SendInput(1, &bkey, sizeof(INPUT));	
				 

				 break;
				}
			
			
			 //Sleep(16);
			 
			}while(GetActiveWindowTitle().find("Google Chrome") != std::string::npos);
			 
			 Sleep(512);
			if(
				(
				(((point.y-10) > (GetYPos()+88))&&
				(point.x>GetLeftPos())&&
				(point.x<GetRightPos()))
				||
				(((point.y-10) < (GetYPos()+16))&&
				(point.x>GetLeftPos())&&
				(point.x>(GetRightPos()-120)))	
				||
				(((point.y-10) < (GetYPos()+75))&&
				(point.x>GetLeftPos())&&
				(point.x>(GetRightPos()-38)))
				)&&PixelIsYellow()
			 ){
											 
					 leftctrl.ki.wVk = VK_CONTROL;
					 leftctrl.ki.dwFlags = 0;
					 
					 
					 leftshft.ki.wVk = VK_SHIFT;
					 leftshft.ki.dwFlags = 0;
					 

					 bkey.ki.wVk = 0x42;
					 bkey.ki.dwFlags = 0;
					 
					 SendInput(1, &leftctrl, sizeof(INPUT));
					 SendInput(1, &leftshft, sizeof(INPUT));
					 SendInput(1, &bkey, sizeof(INPUT));
					 
					 Sleep(16);
					 
					 leftctrl.ki.dwFlags = KEYEVENTF_KEYUP;
					 leftshft.ki.dwFlags = KEYEVENTF_KEYUP;
					 bkey.ki.dwFlags = KEYEVENTF_KEYUP;
					 
					 SendInput(1, &bkey, sizeof(INPUT));	
					 SendInput(1, &leftctrl, sizeof(INPUT));
					 SendInput(1, &leftshft, sizeof(INPUT));
				}	 
			do
			{		
				 GetCursorPos(&point);

				Sleep(16);
				if(
					(((point.y-10) > (GetYPos()+88))&&
					(point.x>GetLeftPos())&&
					(point.x<GetRightPos()))
					||
					(((point.y-10) < (GetYPos()+16))&&
					(point.x>GetLeftPos())&&
					(point.x>(GetRightPos()-120)))	
					||
					(((point.y-10) < (GetYPos()+75))&&
					(point.x>GetLeftPos())&&
					(point.x>(GetRightPos()-38)))	
				  )
				{
					
				 leftctrl.ki.wVk = VK_CONTROL;
				 leftctrl.ki.dwFlags = 0;
				 
				 
				 leftshft.ki.wVk = VK_SHIFT;
				 leftshft.ki.dwFlags = 0;
				 

				 bkey.ki.wVk = 0x42;
				 bkey.ki.dwFlags = 0;
				 
				 SendInput(1, &leftctrl, sizeof(INPUT));
				 SendInput(1, &leftshft, sizeof(INPUT));
				 SendInput(1, &bkey, sizeof(INPUT));
				 
				 //Sleep(16);
				 
				 leftctrl.ki.dwFlags = KEYEVENTF_KEYUP;
				 leftshft.ki.dwFlags = KEYEVENTF_KEYUP;
				 bkey.ki.dwFlags = KEYEVENTF_KEYUP;
				 
				 SendInput(1, &bkey, sizeof(INPUT));	
				 SendInput(1, &leftctrl, sizeof(INPUT));
				 SendInput(1, &leftshft, sizeof(INPUT));
				 
				 
				 break;
				} 

			 //Sleep(16);
			 
			}while(GetActiveWindowTitle().find("Google Chrome") != std::string::npos);
			
			Sleep(512);
			
			if(
				(
				(((point.y-10) > (GetYPos()+88))&&
				(point.x>GetLeftPos())&&
				(point.x<GetRightPos()))
				||
				(((point.y-10) < (GetYPos()+16))&&
				(point.x>GetLeftPos())&&
				(point.x>(GetRightPos()-120)))	
				||
				(((point.y-10) < (GetYPos()+75))&&
				(point.x>GetLeftPos())&&
				(point.x>(GetRightPos()-38)))
				)&&PixelIsYellow()
			 ){
											 
					 leftctrl.ki.wVk = VK_CONTROL;
					 leftctrl.ki.dwFlags = 0;
					 
					 
					 leftshft.ki.wVk = VK_SHIFT;
					 leftshft.ki.dwFlags = 0;
					 

					 bkey.ki.wVk = 0x42;
					 bkey.ki.dwFlags = 0;
					 
					 SendInput(1, &leftctrl, sizeof(INPUT));
					 SendInput(1, &leftshft, sizeof(INPUT));
					 SendInput(1, &bkey, sizeof(INPUT));
					 
					 //Sleep(16);
					 
					 leftctrl.ki.dwFlags = KEYEVENTF_KEYUP;
					 leftshft.ki.dwFlags = KEYEVENTF_KEYUP;
					 bkey.ki.dwFlags = KEYEVENTF_KEYUP;
					 
					 SendInput(1, &bkey, sizeof(INPUT));	
					 SendInput(1, &leftctrl, sizeof(INPUT));
					 SendInput(1, &leftshft, sizeof(INPUT));
				}

		 //Sleep(32);
		}
		
		Sleep(16);
		//std::cout << ("%d",PixelIsYellow());
		//std::cout << "\n";

	}while(1<2);
	
	
	return 0;
}