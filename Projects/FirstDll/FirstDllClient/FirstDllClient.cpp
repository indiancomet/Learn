// FirstDllClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "FirstDll.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CFirstDll *temp = new CFirstDll();
	temp->sayThis(L"can you print this");
	getch();
	return 0;

}

