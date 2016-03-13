#define WINVER 0x0500
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	 std::ifstream updatedForeground;
	
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
	 
	 static string STRING;
	 static POINT point;
	
	do
	{
		
		 updatedForeground.open("updatedForeground.txt");
		 
		 getline(updatedForeground, STRING);
		 std::cout << STRING;
		 std::cout << "\n";

		if(STRING.find("Google Chrome") != std::string::npos)
		{
			while(STRING.find("Google Chrome") != std::string::npos)
			{	
				do
				{	
					 GetCursorPos(&point);
					 Sleep(16);
					if(point.y < 62)
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
				 
				}while(1<2);
				 
				 Sleep(16);
				 
				do
				{		
					 GetCursorPos(&point);
					if(point.y > 88)
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

				 Sleep(16);
				 
				}while(1<2);
				
			 Sleep(32);
				
			}//while(STRING.find("Google Chrome") != std::string::npos);
		}
		
		Sleep(16);
		
		updatedForeground.close();
		

	}while(1<2);
	
	
	return 0;
}