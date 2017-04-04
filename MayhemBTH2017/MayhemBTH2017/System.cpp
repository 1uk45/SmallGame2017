#include "System.h"
#include "GUI.h"
#include "InputManager.h"
#include "LevelEditor.h"



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
	InputManager::Get()->Update();


	while (true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		GUI gui1("leo", true);

		Sprite s1, s2;

		s1.Init(0.2f, 0.2f, 0.5f, 0.5f);
		s2.Init(0.2f, -0.4f, 0.5f, 0.5f);

		gui1.AddSprite(s1);
		gui1.AddSprite(s2);

		gui1.Update();
		gui1.Update();

		gui1.Render();
		gui1.Render();

		//l.Update();
		// Switch between back and front buffer.
		m_videoManager->Swap();
	}
}

void System::Init()
{
	m_videoManager = VideoManager::Get();
}
