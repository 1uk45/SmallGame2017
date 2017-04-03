#include "System.h"



//::.. DUMMY CONSTRUCTORS ..:://
System::System()
{
	Init();
}


System::~System()
{
}

//::.. THE MAIN LOOP ..:://
void System::Run()
{
	while (true)
	{
		//Update input from controller
		m_inputManager->Update();

		// Switch between back and front buffer.
		m_videoManager->DisplayUpdate();
	}
}

void System::Init()
{
	m_videoManager = VideoManager::Get();
	m_inputManager = InputManager::Get();
}
