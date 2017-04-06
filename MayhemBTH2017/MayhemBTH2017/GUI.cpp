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

void GUI::AddSprite(Sprite sprite, glm::vec2 pos, glm::vec2 size, bool isButton, glm::vec3 color)
{
	if (!isButton)
	{
		sprite.Init(pos.x, pos.y, size.x, size.y, color);
		m_spriteArr.PushBack(sprite);
	}

	if (isButton)
	{
		sprite.Init(pos.x, pos.y, size.x, size.y, color);
		m_buttonArr.PushBack(sprite);
	}
}

void GUI::Update()
{

	InputManager* inputManager2 = InputManager::Get();

	m_down = inputManager2->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN);
	m_up = inputManager2->GetButtonDown(CONTROLLER_BUTTON_DPAD_UP);

	Target(m_down, m_up, glm::vec3(0.5, 0.5, 0.7), glm::vec3(0.9, 0.2, 0.7));
	m_buttonArr[1].SetColor(glm::vec3(1.0, 1.0, 1.0));
}

void GUI::Render()
{
	for (int i = 0; i < m_spriteArr.GetSize(); i++)
	{
		m_spriteArr[i].Draw();
	}
	for (int i = 0; i < m_buttonArr.GetSize(); i++)
	{
		m_buttonArr[i].Draw();
	}
}

void GUI::Target(bool down, bool up, glm::vec3 selectColor, glm::vec3 defaultColor)
{
	if (down)
	{
		if (m_selection < m_buttonArr.GetSize() - 1)
		{
			m_selection++;
			m_buttonArr[m_selection - 1].SetColor(defaultColor);
			m_buttonArr[m_selection].SetColor(selectColor);
		}
	}
	if (up)
	{
		if (m_selection > 0)
		{
			m_selection--;
			m_buttonArr[m_selection + 1].SetColor(defaultColor);
			m_buttonArr[m_selection].SetColor(selectColor);
		}
	}

}
