#define WINVER 0x0500
#define WM_WINDOWPOSCHANGED
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>


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

bool TrueInPreferences(){
	
	string settingsString = "\"show_apps_shortcut\":false,\"show_on_all_tabs\":true";
	
	string inputBuffer;
	string finalstring;
    
	ifstream fin;
    fin.open ("Preferences");
	
    do {
		int current(0);
		getline(fin, inputBuffer);          
		while(current < 1500 && current < inputBuffer.size())
		{
			//cout << inputBuffer[current++];
			finalstring += inputBuffer[current++];
		}
		cout << endl;
    } while (!fin.eof());
	
    fin.close();
	
	cout << "|||" << finalstring << "DONE"; 
	
	smatch m; 
	
	regex e1("\"show_apps_shortcut\":false,\"show_on_all_tabs\":true");
	
	//std::cout << "Target sequence: " << finalstring << std::endl;
	//std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
	std::cout << "\n\n\nThe following matches and submatches were found for e1:" << std::endl;

	try{
		while (std::regex_search (finalstring,m,e1)) {
			for (auto x:m) std::cout << x << " ";
			//std::cout << std::endl;
			finalstring = m.suffix().str();
		}
	}catch (const std::regex_error& e1) {
		std::cout << "regex_error caught: " << e1.what() << '\n';
        if (e1.code() == std::regex_constants::error_brack) {
            std::cout << "The code was error_brack\n";
        }
	}
	
	return (finalstring==settingsString);
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
				)&&TrueInPreferences()
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
				)&&TrueInPreferences()
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