#include "GUIManager.h"


//::.. DUMMY CONSTRUCTORS ..:://
GUIManager::GUIManager()
{
	// Do nothing...
}

GUIManager::~GUIManager()
{
	// Do nothing...
}

//::.. FAKE CONSTRUCTORS ..:://
void GUIManager::StartUp()
{
	if (m_instance == nullptr)
	{
		m_instance = this;
		Init();
	}
}

void GUIManager::ShutDown()
{
	for (int i = 0; i < 4; i++)
	{
		//m_gui[i]. //remove stuff in GUI
	}
}

GUIManager & GUIManager::Get()
{
	return *m_instance;
}

void GUIManager::Init()
{
	createMainMenu();
}

void GUIManager::createMainMenu()
{
	Sprite playButton("menu", true);
	playButton.Init(0.5f, 0.5f, 0.5f, 0.5f);
	Sprite exit("menu", true);
	exit.Init(0.5f, -0.7f, 0.5f, 0.5f);

	m_gui[0].AddSprite(playButton);
	m_gui[0].AddSprite(exit);
}

GUI GUIManager::getGUI(int index)
{
	return m_gui[index];
}
