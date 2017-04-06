#ifndef __MAINMENU_H__
#define __MAINMENU_H__


#include "Menu.h"


class MenuSystem
{
public:
	MenuSystem();
	virtual ~MenuSystem();

	void Update();

private:
	Menu m_test;


};


#endif // __MAINMENU_H__