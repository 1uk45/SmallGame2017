#include "Menu.h"

#include <sdl_ttf.h>

Menu::Menu() 
{
	m_selection = 0;
	defaultColor = glm::vec4(0.0, 0.5, 0.5, 0.0);
	selectColor = glm::vec4(0.0, 1.0, 1.0, 0.0);
}


Menu::~Menu()
{
}

void Menu::AddSprite(glm::vec2 pos, glm::vec2 size)
{

	//ändra så att sprite class har color etc...
	Sprite newSprite("leo", true);

	newSprite.Init(pos.x, pos.y, size.x, size.y);
	newSprite.SetColor(defaultColor);
	m_spriteArr.PushBack(newSprite);

}

void Menu::AddButton(glm::vec2 pos, glm::vec2 size)
{
	Sprite newSprite("leo", true);

	newSprite.Init(pos.x, pos.y, size.x, size.y);
	newSprite.SetColor(defaultColor);
	m_buttonArr.PushBack(newSprite);

	if (m_buttonArr.GetSize() == 1)
	{
		m_buttonArr[0].SetColor(selectColor);
	}
}

void Menu::Update()
{
	
}

void Menu::Render()
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

void Menu::SelectionUpdate()
{
	//m_down = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN);
	//m_up = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_UP);
	//m_a = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_A);

	if (InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN))
	{
		if (m_selection < m_buttonArr.GetSize() - 1)
		{
			m_selection += 1;
			m_buttonArr[m_selection-1].SetColor(defaultColor);
			m_buttonArr[m_selection].SetColor(selectColor);
		}
	}

	if (InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_UP))
	{
		if (m_selection > 0)
		{
			m_selection -= 1;
			m_buttonArr[m_selection+1].SetColor(defaultColor);
			m_buttonArr[m_selection].SetColor(selectColor);
		}
	}

	if (InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_A))
	{
		switch (m_selection)
		{
		case 0:
			//Call Play
			std::cout << "1" << std::endl;
			break;

		case 1:
			//Call Editor
			std::cout << "2" << std::endl;
			break;

		case 2:
			//Call Exit
			std::cout << "3" << std::endl;
			break;
		}
	}
}

int Menu::GetSelect()
{
	return m_selection;
}
