#include <windows.h>
#include <Windowsx.h>
#include <iostream>

using namespace std;
int main()
{
		
	while(true)
	{
		if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
		{
			std::cout << "TRUE";
		}
	}
	
	
	return 0;
}