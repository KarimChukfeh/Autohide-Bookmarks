#include <windows.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>


using std::string;



const int NUM_SECONDS = 6;
//const int CLOCKS_PER_SEC = 5;


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
	std::cout << GetActiveWindowTitle();

	for( int a = 1; a < 20; a = a + 0 )
		{
			HWND hwnd=GetForegroundWindow();
			if(IsZoomed(hwnd))
			{
				flush(std::cout) << GetActiveWindowTitle();
				flush(std::cout) << "\n";
	
				ofstream myfile;
				myfile.open ("updatedForeground.txt");
				myfile << GetActiveWindowTitle();
				myfile << "\n";
				myfile.close();
				
			}else{
				flush(std::cout) << GetActiveWindowTitle();
				flush(std::cout) << "\n";
				
				ofstream myfile;
				myfile.open ("updatedForeground.txt");
				myfile << ".";
				myfile << "\n";
				myfile.close();
			}
			
			Sleep(256);
		}
}