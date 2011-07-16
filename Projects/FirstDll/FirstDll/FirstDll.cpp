
// FirstDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FirstDll.h"
#include <iostream>
#include <curlpp/curlpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
using namespace std;
using namespace curlpp::options;
// This is an example of an exported variable
FIRSTDLL_API int nFirstDll=0;

// This is an example of an exported function.
FIRSTDLL_API int fnFirstDll(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see FirstDll.h for the class definition
CFirstDll::CFirstDll()
{
	return;
}

void CFirstDll::sayThis(TCHAR* message)
{
	wcout<<message;
	try
  {
    // That's all that is needed to do cleanup of used resources (RAII style).
    curlpp::Cleanup myCleanup;
 
    // Our request to be sent.
    curlpp::Easy myRequest;
 
    // Set the URL.
    myRequest.setOpt<Url>("http://example.com");
 
    // Send request and get a result.
    // By default the result goes to standard output.
    myRequest.perform();
  }
 
  catch(curlpp::RuntimeError & e)
  {
    std::cout << e.what() << std::endl;
  }
 
  catch(curlpp::LogicError & e)
  {
    std::cout << e.what() << std::endl;
  }
}