#pragma once

class CWindow : public CFrameWnd
{
public:
	CWindow();

	enum class MenuType
	{
		Static,
		Popup
	};
	void CreateMainMenu();
	void AddMenuItem(std::string newMenuName, UINT_PTR newMenuID);
	void AddSubMenuItem(std::string menuName, std::string subMenuName, UINT_PTR subMenuID, MenuType subMenuType = MenuType::Static);

private:
	CMenu* fpMainMenu;
	std::map<std::string, CMenu*> fMenuMap;

};

