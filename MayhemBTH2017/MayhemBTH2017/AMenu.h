#ifndef __AMENU_H__
#define __AMENU_H__


#include "Canvas.h"


class AMenu
{
public:
	AMenu();
	virtual ~AMenu();
	
	virtual void Update() = 0;
};


#endif // !__AMENU_H__