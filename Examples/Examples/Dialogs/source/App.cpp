#include "pch.h"

#include "App.h"
#include "Window.h"
#include "constants.h"

BEGIN_MESSAGE_MAP(CApp, CWinApp)
	//ON_COMMAND_EX(MenuID::NewFile, CApp::OnMenuClicked)
	//ON_COMMAND_EX(MenuID::NewProject, CApp::OnMenuClicked)
	//ON_COMMAND_EX(MenuID::Help, CApp::OnMenuClicked)
	//ON_COMMAND_EX(MenuID::Exit, CApp::OnMenuClicked)
END_MESSAGE_MAP()

BOOL CApp::InitInstance()
{
	CreateMainWindow();

	//AddMenusExample();

	return TRUE;
}

void CApp::CreateMainWindow()
{
	fpMainWindow = new CWindow();
	m_pMainWnd = fpMainWindow;

	fpMainWindow->ShowWindow(SW_NORMAL);
	fpMainWindow->UpdateWindow();
}

//BOOL CApp::OnMenuClicked(UINT id)
//{
//	switch (id)
//	{
//	case MenuID::NewFile:
//		break;
//	case MenuID::NewProject:
//		break;
//	case MenuID::DialogSimple:
//	{
//
//		break;
//	}
//	case MenuID::DialogFromTemplate:
//	{
//
//		break;
//	}
//	case MenuID::Help:
//		break;
//	case MenuID::Exit:
//		fpMainWindow->SendMessage(WM_CLOSE);
//		break;
//	default:
//		return false;
//		break;
//	}
//	return true;
//}

//void CApp::AddMenusExample()
//{
//	if (CMenu* pMenu = new CMenu())
//	{
//		VERIFY(pMenu->CreateMenu());
//
//		// Assign default menu
//		VERIFY(fpMainWindow->SetMenu(pMenu));
//		fpMainWindow->m_hMenuDefault = pMenu->m_hMenu;
//
//
//		// File menu
//		if (CMenu* pFileMenu = new CMenu())
//		{
//			VERIFY(pFileMenu->CreatePopupMenu());
//			VERIFY(pMenu->AppendMenu(MF_POPUP, (UINT_PTR)pFileMenu->m_hMenu, _T("&File")));
//
//			// New menu
//			if (CMenu* pNewMenu = new CMenu())
//			{
//				VERIFY(pNewMenu->CreatePopupMenu());
//
//				VERIFY(pFileMenu->AppendMenu(MF_POPUP, (UINT_PTR)pNewMenu->m_hMenu, _T("&New")));
//
//				// New File and New Project menu
//				VERIFY(pNewMenu->AppendMenu(MF_STRING, MenuID::NewFile, _T("&File...")));
//				VERIFY(pNewMenu->AppendMenu(MF_STRING, MenuID::NewProject, _T("&Project...")));
//			}
//
//			// Exit menu
//			VERIFY(pFileMenu->AppendMenu(MF_STRING, ID_APP_EXIT, _T("E&xit")));
//		}
//
//		// Dialogs menu
//		if (CMenu* pDialogsMenu = new CMenu())
//		{
//			VERIFY(pDialogsMenu->CreatePopupMenu());
//			VERIFY(pMenu->AppendMenu(MF_POPUP, (UINT_PTR)pDialogsMenu->m_hMenu, _T("&Dialogs")));
//
//			VERIFY(pDialogsMenu->AppendMenu(MF_STRING, MenuID::DialogSimple, _T("&Simple Dialog")));
//			VERIFY(pDialogsMenu->AppendMenu(MF_STRING, MenuID::DialogFromTemplate, _T("&Dialog from template")));
//		}
//
//		// Help menu
//		VERIFY(pMenu->AppendMenu(MF_POPUP, MenuID::Help, _T("&Help")));
//	}
//
//	// Redraw
//	fpMainWindow->DrawMenuBar();
//}
