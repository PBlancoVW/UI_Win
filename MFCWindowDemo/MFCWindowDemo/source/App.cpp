#include "pch.h"

#include "App.h"
#include "Frame.h"

BOOL CApp::InitInstance() {
	CFrame* pFrame = new CFrame(); 
	m_pMainWnd = pFrame;

	pFrame->ShowWindow(SW_NORMAL);
	pFrame->UpdateWindow();

	return TRUE;
}
