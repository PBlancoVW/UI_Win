#include "pch.h"

#include "Window.h"

CWindow::CWindow() {
	Create(NULL, _T("MFC Application Tutorial"), WS_SYSMENU, CRect(90, 120, 550, 480), NULL);
}