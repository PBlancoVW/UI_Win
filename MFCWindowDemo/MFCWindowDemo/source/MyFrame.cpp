#include "pch.h"

#include "MyFrame.h"

CMyFrame::CMyFrame() {
	Create(NULL, _T("MFC Application Tutorial"), WS_SYSMENU, CRect(90, 120, 550, 480));
}