#ifndef __SYSTEM_H__
#define __SYSTEM_H__


#include "VideoManager.h"
#include "InputManager.h"


class System
{
public:
	//::.. DUMMY CONSTRUCTORS ..:://
	System();
	virtual ~System();

	//::.. THE MAIN LOOP ..:://
	void Run();

private:
	//::.. HELP FUNCTIONS ..:://
	void Init();

private:
	VideoManager * m_videoManager;
	InputManager * m_inputManager;
};


#endif // __SYSTEM_H__