#pragma once

class CWindow;

class CApp : public CWinApp
{
	BOOL InitInstance();

private:

	//Windows
	void CreateMainWindow();

	//Menus
	enum MenuID : UINT
	{
		File,
		New,
		NewProject,
		NewFile,
		Help,
		Exit
	};
	afx_msg BOOL OnMenuClicked(UINT id);
	DECLARE_MESSAGE_MAP()

	void AddMenusExample();
	void AddMenusExample_OOP();

protected:
	CWindow* fpMainWindow;
};

