#include "pch.h"

#include "App.h"
#include "Window.h"

BEGIN_MESSAGE_MAP(CApp, CWinApp)
	ON_COMMAND_EX(MenuID::NewFile, CApp::OnMenuClicked)
	ON_COMMAND_EX(MenuID::NewProject, CApp::OnMenuClicked)
	ON_COMMAND_EX(MenuID::Help, CApp::OnMenuClicked)
	ON_COMMAND_EX(MenuID::Exit, CApp::OnMenuClicked)
END_MESSAGE_MAP()

BOOL CApp::InitInstance()
{
	CreateMainWindow();

	AddMenusExample_OOP();


	return TRUE;
}

void CApp::CreateMainWindow()
{
	fpMainWindow = new CWindow();
	m_pMainWnd = fpMainWindow;

	fpMainWindow->ShowWindow(SW_NORMAL);
	fpMainWindow->UpdateWindow();
}

BOOL CApp::OnMenuClicked(UINT id)
{
	switch (id)
	{
	case MenuID::NewFile:
		break;
	case MenuID::NewProject:
		break;
	case MenuID::Help:
		break;
	case MenuID::Exit:
		fpMainWindow->SendMessage(WM_CLOSE);
		break;
	default:
		return false;
		break;
	}
	return true;
}

void CApp::AddMenusExample()
{
	CMenu* pMenu = new CMenu();
	VERIFY(pMenu->CreateMenu());

	// Remove and destroy old menu
	VERIFY(fpMainWindow->SetMenu(NULL));
	CMenu *pOldMenu = CMenu::FromHandle(fpMainWindow->m_hMenuDefault);
	pOldMenu->DestroyMenu();

	// Assign default menu
	VERIFY(fpMainWindow->SetMenu(pMenu));
	fpMainWindow->m_hMenuDefault = pMenu->m_hMenu;


	// File menu
	CMenu* pFileMenu = new CMenu();
	VERIFY(pFileMenu->CreatePopupMenu());
	VERIFY(pMenu->AppendMenu(MF_POPUP, (UINT_PTR)pFileMenu->m_hMenu, _T("&File")));

	// New menu
	CMenu* pNewMenu = new CMenu();
	VERIFY(pNewMenu->CreatePopupMenu());

	VERIFY(pFileMenu->AppendMenu(MF_POPUP, (UINT_PTR)pNewMenu->m_hMenu, _T("&New")));

	// Exit menu
	VERIFY(pFileMenu->AppendMenu(MF_STRING, ID_APP_EXIT, _T("E&xit")));

	// New Project menu
	VERIFY(pNewMenu->AppendMenu(MF_STRING, (UINT_PTR)75, _T("&Project...")));

	// About menu
	VERIFY(pMenu->AppendMenu(MF_POPUP, ID_APP_ABOUT, _T("&About")));


	// Redraw
	fpMainWindow->DrawMenuBar();
}

void CApp::AddMenusExample_OOP()
{
	fpMainWindow->AddMenuItem("File", MenuID::File);
	fpMainWindow->AddSubMenuItem("File", "New", MenuID::New, CWindow::MenuType::Popup);
	fpMainWindow->AddSubMenuItem("New", "File...", MenuID::NewFile, CWindow::MenuType::Static);
	fpMainWindow->AddSubMenuItem("New", "Project...", MenuID::NewProject, CWindow::MenuType::Static);
	fpMainWindow->AddSubMenuItem("File", "Exit", MenuID::Exit, CWindow::MenuType::Static);
	fpMainWindow->AddMenuItem("Help", MenuID::Help);
}
