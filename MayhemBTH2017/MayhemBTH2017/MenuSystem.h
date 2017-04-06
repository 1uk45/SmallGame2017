#ifndef __MAINMENU_H__
#define __MAINMENU_H__


#include "Menu.h"
#include "Text.h"

class MenuSystem
{
public:
	MenuSystem();
	virtual ~MenuSystem();

	void Update();

private:
	Menu m_test;
	Text t;

};


#endif // __MAINMENU_H__