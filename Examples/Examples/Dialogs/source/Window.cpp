#include "pch.h"

#include "Window.h"
#include "constants.h"
#include "HelloDlg.h"

CWindow::CWindow()
{
	CPoint pos(1500, 200);
	CPoint size(400, 300);
	Create(NULL, _T("MFC Application Tutorial"), WS_SYSMENU, CRect(pos, pos + size), NULL);

	//When this data member is enabled (which is the default), menu items that do not have ON_UPDATE_COMMAND_UI
	//or ON_COMMAND handlers will be automatically disabled when the user pulls down a menu.
	m_bAutoMenuEnable = false;

	AddMenus();
}

void CWindow::AddMenus()
{
	if (CMenu* pMenu = new CMenu())
	{
		VERIFY(pMenu->CreateMenu());

		// Assign default menu
		VERIFY(SetMenu(pMenu));
		m_hMenuDefault = pMenu->m_hMenu;


		// File menu
		if (CMenu* pFileMenu = new CMenu())
		{
			VERIFY(pFileMenu->CreatePopupMenu());
			VERIFY(pMenu->AppendMenu(MF_POPUP, (UINT_PTR)pFileMenu->m_hMenu, _T("&File")));

			// New menu
			if (CMenu* pNewMenu = new CMenu())
			{
				VERIFY(pNewMenu->CreatePopupMenu());

				VERIFY(pFileMenu->AppendMenu(MF_POPUP, (UINT_PTR)pNewMenu->m_hMenu, _T("&New")));

				// New File and New Project menu
				VERIFY(pNewMenu->AppendMenu(MF_STRING, MenuID::NewFile, _T("&File...")));
				VERIFY(pNewMenu->AppendMenu(MF_STRING, MenuID::NewProject, _T("&Project...")));
			}

			// Exit menu
			VERIFY(pFileMenu->AppendMenu(MF_STRING, ID_APP_EXIT, _T("E&xit")));
		}

		// Dialogs menu
		if (CMenu* pDialogsMenu = new CMenu())
		{
			VERIFY(pDialogsMenu->CreatePopupMenu());
			VERIFY(pMenu->AppendMenu(MF_POPUP, (UINT_PTR)pDialogsMenu->m_hMenu, _T("&Dialogs")));

			VERIFY(pDialogsMenu->AppendMenu(MF_STRING, MenuID::DialogSimple, _T("&Simple Dialog")));
			VERIFY(pDialogsMenu->AppendMenu(MF_STRING, MenuID::DialogFromTemplate, _T("&Dialog from template")));
		}

		// Help menu
		VERIFY(pMenu->AppendMenu(MF_POPUP, MenuID::Help, _T("&Help")));
	}

	// Redraw
	DrawMenuBar();
}

LRESULT CWindow::DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	switch (nMsg)
	{
		case WM_COMMAND:

			switch (LOWORD(wParam))
			{
				case MenuID::NewFile:
				{
					MessageBox("Hit", "NewFile");
					break;
				}
				case MenuID::NewProject:
				{
					MessageBox("Hit", "NewProject");
					break;
				}
				case MenuID::Help:
				{
					MessageBox("Hit", "Help");
					break;
				}
				case MenuID::DialogSimple:
				{
					CHelloDlg helloDlg;
					helloDlg.DoModal();
					break;
				}
				case MenuID::DialogFromTemplate:
				{
					MessageBox("Hit", "DialogFromTemplate");
					break;
				}
				default:
					break;
			}
			
			break;
		
		case WM_LBUTTONDOWN:
			break;
		default:
			return CFrameWnd::DefWindowProc(nMsg, wParam, lParam);
	}

	return 0;
}

