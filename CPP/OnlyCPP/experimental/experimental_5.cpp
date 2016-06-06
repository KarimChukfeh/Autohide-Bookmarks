#define WINVER 0x0500
#define WM_WINDOWPOSCHANGED
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

bool PixelIsYellow(){
	HDC hdc_ = GetDC(GetDesktopWindow());
	string color;
	COLORREF pColor = GetPixel(hdc_, 84, 71);
	//color = printf("%d %d %d\n", GetRValue(pColor), GetGValue(pColor), GetBValue(pColor));
	return ((GetRValue(pColor) == 255)
			&&
			(GetGValue(pColor) == 216)
			&&
			(GetBValue(pColor) == 144));
}


bool Unpause(){
	
	
		while(true){
			//std::cout << "CLICK222\n";
			Sleep(16);
			std::cout << "in pause\n";
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0){
				std::cout << "if 1\n";
				if((GetKeyState(VK_LBUTTON) & 0x100) != 0){
					std::cout << "if 2\n";
					//Sleep(1000);
					return PixelIsYellow();
				}
				return 1;
			}return 0;
	}	
}

bool Pause()
{

	static POINT point;
	GetCursorPos(&point);
	
	int x;
	if((GetKeyState(VK_LBUTTON) & 0x100) != 0){
		std::cout << "CLICK\n";
		Sleep(16);
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0){
			return Unpause();
		}
	}
	std::cout << "out\n";
	return 0;

}


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
				 
				 
				 Sleep(16);
				 
				 leftctrl.ki.dwFlags = KEYEVENTF_KEYUP;
				 leftshft.ki.dwFlags = KEYEVENTF_KEYUP;
				 bkey.ki.dwFlags = KEYEVENTF_KEYUP;
				 
				 SendInput(1, &leftctrl, sizeof(INPUT));
				 SendInput(1, &leftshft, sizeof(INPUT));					 
				 SendInput(1, &bkey, sizeof(INPUT));	
				 

				 break;
				}
			
			
			 Sleep(16);
			 
			}while(GetActiveWindowTitle().find("Google Chrome") != std::string::npos);
			 
			 Sleep(16);
			 
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
				 
				 Sleep(16);
				 
				 leftctrl.ki.dwFlags = KEYEVENTF_KEYUP;
				 leftshft.ki.dwFlags = KEYEVENTF_KEYUP;
				 bkey.ki.dwFlags = KEYEVENTF_KEYUP;
				 
				 SendInput(1, &bkey, sizeof(INPUT));	
				 SendInput(1, &leftctrl, sizeof(INPUT));
				 SendInput(1, &leftshft, sizeof(INPUT));
				 
				 
				 break;
				} 
				if(
					(point.x > 1787)&&
					(point.x < 1907)&&
					(point.y > 78)&&
					(point.y < 95)
					){
						do{
							//std::cout << point.x << ", " << point.y << "\n";
							if(Pause()==1){
								 std::cout << "x == 1\n";
								 Sleep(200);
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
								break;
							}else if(Pause()==0){
								std::cout << "x == 0\n";
							}
						}while(
								(point.x > 1787)&&
								(point.x < 1907)&&
								(point.y > 78)&&
								(point.y < 95)
							);
					} 

			 Sleep(16);
			 
			}while(GetActiveWindowTitle().find("Google Chrome") != std::string::npos);
			
			//Sleep(1000);
			
			
		 Sleep(32);
		}
		
		Sleep(16);
		//std::cout << ("%d",PixelIsYellow());
		//std::cout << "\n";

	}while(1<2);
	
	
	return 0;
}