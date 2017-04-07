#ifndef __MAINMENU_H__
#define __MAINMENU_H__


#include "Canvas.h"
#include "Text.h"
#include "OptionsMenu.h"
#include "CreateMenu.h"
#include "InputManager.h"

#include <cstdint>
#include <vector>


class MenuSystem
{
public:
	MenuSystem();
	virtual ~MenuSystem();

	void Init();

	void Update();

private:
	InputManager * m_input;

	uint32_t m_currentMenu;
	std::vector<AMenu*> m_menus;
};


#endif // __MAINMENU_H__