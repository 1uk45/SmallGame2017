#include "System.h"

#include "GUI.h"
#include "LevelEditor.h"
#include "InputManager.h"

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
	glDisable(GL_CULL_FACE);
	LevelEditor l;
	
	GUI menu;

	menu.AddSprite(glm::vec2(0.0, 0.0), glm::vec2(0.6, 0.2), true);

	menu.AddSprite(glm::vec2(0.0, -0.3), glm::vec2(0.6, 0.2), true);

	menu.AddSprite(glm::vec2(0.0, -0.6), glm::vec2(0.6, 0.2), true);


	
	SDL_Color White = { 255, 255, 255 };

	while (true)
	{
		m_inputManager->Update();

		glClear(GL_COLOR_BUFFER_BIT);

		menu.Update();

		menu.SelectionUpdate();

		menu.Render();

		//l.Update();

		m_inputManager->Reset();

		// Switch between back and front buffer.
		m_videoManager->Swap();

	}
}

void System::Init()
{
	m_videoManager = VideoManager::Get();
	m_inputManager = InputManager::Get();
}