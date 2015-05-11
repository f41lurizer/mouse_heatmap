// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h"
#include "Winuser.h"
#include <iostream>
#include <fstream>
int _tmain(int argc, _TCHAR* argv[])
{
	std::ofstream out;
	out.open("winInput.txt");
	int x, y;
	x = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	y = GetSystemMetrics(SM_CYVIRTUALSCREEN);
	std::cout << y << "x" << x << std::endl;
	out << x << "x" << y << std::endl;
	POINT coords;
	while (1)
	{
		BOOL result = GetPhysicalCursorPos(&coords);
		if (result)//api call returned a position
			out << "x:" << coords.x << " y:" << coords.y << std::endl;
			std::cout << "x: " << coords.x << " y: " << coords.y << std::endl;
		Sleep(1000);
	}
	out.close();
	return 0;

}

