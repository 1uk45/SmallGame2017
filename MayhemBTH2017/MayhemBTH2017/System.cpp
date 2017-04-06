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

	GUI gui1;

	Sprite s1("leo", true);

	Sprite s2("leo", true);

	s1.Init(0.5f, 0.5f, 0.5f, 0.5f, glm::vec3(1.0, 0.0, 0.0));

	s2.Init(0.5f, -0.7f, 0.5f, 0.5f, glm::vec3(1.0, 0.0, 0.0));

	gui1.AddSprite(s1, glm::vec2(0.5, 0.0), glm::vec2(0.5, 0.5), true, glm::vec3(0.7, 0.7, 0.7));

	gui1.AddSprite(s1, glm::vec2(-0.5, 0.0), glm::vec2(0.5, 0.5), true, glm::vec3(0.7, 0.7, 0.7));

	while (true)
	{
		m_inputManager->Update();

		glClear(GL_COLOR_BUFFER_BIT);

		gui1.Update();

		gui1.Render();

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
