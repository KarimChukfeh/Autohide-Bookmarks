#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

using std::string;
const int NUM_SECONDS = 6;

string GetActiveWindowTitle()
{
	char wnd_title[256];
 
	HWND hwnd=GetForegroundWindow(); 
	GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
 
	return wnd_title;
}

using namespace std;
int main()
{
	for( int a = 1; a < 20; a = a + 0 )
		{
			HWND hwnd=GetForegroundWindow();
			
			flush(std::cout) << GetActiveWindowTitle();
			flush(std::cout) << "\n";

			ofstream myfile;
			myfile.open ("updatedForeground.txt");
			myfile << GetActiveWindowTitle();
			myfile << "\n";
			myfile.close();
		
			Sleep(64);
		}
}