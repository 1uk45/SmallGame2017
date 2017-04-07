#ifndef __MAINMENU_H__
#define __MAINMENU_H__


#include "AMenu.h"



class MainMenu : public AMenu
{
public:
	MainMenu();
	virtual ~MainMenu();

	virtual void Init();
	virtual void Update();
	virtual void Render();

private:
	Canvas m_canvas;

};


#endif // __MAINMENU_H__