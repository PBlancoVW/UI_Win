#include "pch.h"

#include "MainWindow.h"

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(NULL, _T("The Hello Application"));
}

void CMainWindow::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(_T("Hello, MFC"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}