#ifndef __MAINMENU_H__
#define __MAINMENU_H__


#include "Menu.h"


class MenuSystem
{
public:
	MenuSystem();
	virtual ~MenuSystem();

	void Update();

	void SelectionUpdate();

	Void MenuSelection();

private:
	Menu m_test;

	glm::vec4 defaultColor, selectColor;
	int m_selection;

};


#endif // __MAINMENU_H__