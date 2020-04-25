#include "pch.h"

#include "Window.h"

CWindow::CWindow() {
	Create(NULL, _T("MFC Application Tutorial"), WS_SYSMENU, CRect(90, 120, 550, 480), NULL);
}

void CWindow::CreateMainMenu()
{
	fpMainMenu = new CMenu();
	VERIFY(fpMainMenu->CreateMenu());

	// Assign default menu
	VERIFY(SetMenu(fpMainMenu));
	m_hMenuDefault = fpMainMenu->m_hMenu;
}

void CWindow::AddMenuItem(std::string newMenuName, UINT_PTR newMenuID)
{
	if (!fpMainMenu)
		CreateMainMenu();

	CMenu* pNewMenu = new CMenu();
	VERIFY(pNewMenu->CreatePopupMenu());

	VERIFY(fpMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pNewMenu->m_hMenu, _T(newMenuName.c_str())));

	fMenuMap[newMenuName] = pNewMenu;

	// Redraw
	DrawMenuBar();
}

void CWindow::AddSubMenuItem(std::string menuName, std::string subMenuName, UINT_PTR subMenuID, MenuType subMenuType)
{
	CMenu* pMenu;

	const auto& it = fMenuMap.find(menuName);
	if (it != fMenuMap.end()) //found
	{
		pMenu = it->second;
	}
	else
	{
		pMenu = new CMenu();
		VERIFY(pMenu->CreateMenu());
		fMenuMap[menuName] = pMenu;
	}

	if (subMenuType == MenuType::Popup)
	{
		CMenu* pSubMenu = new CMenu();
		VERIFY(pSubMenu->CreatePopupMenu());

		VERIFY(pMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu->m_hMenu, _T(subMenuName.c_str())));
		fMenuMap[subMenuName] = pSubMenu;
	}
	else
	{
		VERIFY(pMenu->AppendMenu(MF_STRING, subMenuID, _T(subMenuName.c_str())));
	}

	// Redraw
	DrawMenuBar();
}
