#include "pch.h"

#include "MyApp.h"
#include "MyFrame.h"

BOOL CMyApp::InitInstance() {
	CMyFrame* pFrame = new CMyFrame(); 
	m_pMainWnd = pFrame;

	pFrame->ShowWindow(SW_NORMAL);
	pFrame->UpdateWindow();

	return TRUE;
}
