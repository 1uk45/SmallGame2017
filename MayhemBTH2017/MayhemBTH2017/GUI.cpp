#include "GUI.h"
#include "InputManager.h"
#include "VideoManager.h"



GUI::GUI() 
{
	m_selection = 0;
	m_trueOnce = true;
}


GUI::~GUI()
{
}

void GUI::AddSprite(Sprite sprite)
{
	m_spriteArr.PushBack(sprite);
	if (m_spriteArr.GetSize() == 1)
	{
		m_spriteArr[0].SetColor(glm::vec3(0,1,1));
	}
}

void GUI::Update()
{

	InputManager* inputManager2 = InputManager::Get();
	
	/*int mouse_x;
	int mouse_y;

	SDL_GetMouseState(&mouse_x, &mouse_y);

	float new_mouseX = VideoManager::Get()->GetScreenWidth() / (float)mouse_x;
	float new_mouseY = VideoManager::Get()->GetScreenHeight() / (float)mouse_y;*/

	m_down = inputManager2->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN);
	m_up = inputManager2->GetButtonUp(CONTROLLER_BUTTON_DPAD_UP);


	if (m_down)
	{
		if (m_trueOnce)
		{
			m_selection += 1;
		}
		m_trueOnce = false;
	}

	if (!m_down)
	{
		m_trueOnce = true;
	}


	if (m_down)
	{

		glm::vec3 white(1,1,1);
		glm::vec3 black(0, 0, 0);
		for (int i = 0; i < m_spriteArr.GetSize(); i++)
		{
			m_spriteArr[i].SetColor(black);
		}

		//glm::vec3 color = m_spriteArr[m_selection].SetColor(white);

	}
	m_spriteArr[1].SetColor(glm::vec3(1));
}

void GUI::Render()
{
	for (int i = 0; i < m_spriteArr.GetSize(); i++)
	{
		m_spriteArr[i].Draw();
	}
}
