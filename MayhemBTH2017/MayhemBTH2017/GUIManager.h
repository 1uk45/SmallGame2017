#ifndef __GUIMANAGER__
#define __GUIMANAGER__


#include "GUI.h"


class GUIManager
{
public:
	//::.. DUMMY CONSTRUCTORS ..:://
	GUIManager();
	virtual ~GUIManager();

	//::.. FAKE CONSTRUCTORS ..:://
	void StartUp();
	void ShutDown();

	//::.. GET FUNCTIONS ..:://
	GUIManager& Get();
	GUI getGUI(int index);


private:
	//::.. HELP FUNCTIONS ..:://
	void Init();

private:

	static GUIManager * m_instance;

	//::.. MENU STATES ..:://
	GUI m_gui[4];

	void createMainMenu();
	void createPlayerChoose();
	void createInGamePause();
	void createEditor();

	
};

#endif // !__GUIMANAGER__