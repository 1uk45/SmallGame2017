#ifndef __OPTIONSMENU_H__
#define __OPTIONSMENU_H__


#include "AMenu.h"


class OptionsMenu : public AMenu
{
public:
	OptionsMenu();
	virtual ~OptionsMenu();

	virtual void Init();
	virtual void Update();
	virtual void Render();

	virtual void MoveUp();
	virtual void MoveDown();
	virtual void PressedDown();

private:
	Canvas m_canvas;


};

#endif // __OPTIONSMENU_H__