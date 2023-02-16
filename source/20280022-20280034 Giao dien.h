
// 20280022-20280034 Giao dien.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy2028002220280034GiaodienApp:
// See 20280022-20280034 Giao dien.cpp for the implementation of this class
//

class CMy2028002220280034GiaodienApp : public CWinApp
{
public:
	CMy2028002220280034GiaodienApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy2028002220280034GiaodienApp theApp;
