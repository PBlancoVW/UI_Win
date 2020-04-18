
// Tutorial0_Setup.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTutorial0SetupApp:
// See Tutorial0_Setup.cpp for the implementation of this class
//

class CTutorial0SetupApp : public CWinApp
{
public:
	CTutorial0SetupApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTutorial0SetupApp theApp;
