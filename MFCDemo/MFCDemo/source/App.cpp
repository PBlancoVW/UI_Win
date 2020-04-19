#include "pch.h"

#include "App.h"
#include "Window.h"

BOOL CApp::InitInstance() {
	CWindow* pWindow = new CWindow();
	m_pMainWnd = pWindow;

	pWindow->ShowWindow(SW_NORMAL);
	pWindow->UpdateWindow();

	return TRUE;
}
