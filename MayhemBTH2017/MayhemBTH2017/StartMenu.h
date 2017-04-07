#ifndef __STARTMENU_H__
#define __STARTMENU_H__


#include "AMenu.h"
#include "MainMenu.h"


class StartMenu : public AMenu
{
public:
	StartMenu();
	virtual ~StartMenu();

	virtual void Init();
	virtual void Update();
	virtual void Render();

private:
	Canvas m_canvas;

};


#endif // __STARTMENU_H__