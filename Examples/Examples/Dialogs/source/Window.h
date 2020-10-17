#pragma once

class CWindow : public CFrameWnd
{
public:
	CWindow();

protected:
	virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);

private:
	void AddMenus();

private:
	CMenu* fpMainMenu;
	std::map<std::string, CMenu*> fMenuMap;
};

