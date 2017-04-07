#ifndef __MAINMENU_H__
#define __MAINMENU_H__


#include "Canvas.h"
#include "Text.h"

class MenuSystem
{
public:
	MenuSystem();
	virtual ~MenuSystem();

	void Update();

private:
	Canvas m_test;
	Text t;

};


#endif // __MAINMENU_H__