// Example2-2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <Windows.h>

VOID ReportError(LPCTSTR UserMessage, DWORD ExitCode, BOOL PrintErrorMsg)
{
	DWORD eMsgLen, LastError = GetLastError();
	LPTSTR lpvSysMsg;
	HANDLE hStdErr = GetStdHandle(STD_ERROR_HANDLE);
	PrintMsg(hStdErr, UserMessage);
	if(PrintErrorMsg){
		eMsgLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM, NULL, LastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&lpvSysMsg, 0, NULL);
		PrintStrings(hStdErr, _T("\n"), lpvSysMsg, _T("\n"), NULL);
		HeapFree(GetProcessHeap(), 0, lpvSysMsg);
	}
	if(ExitCode>0){
		ExitProcess(ExitCode);
	} else {
		return;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

