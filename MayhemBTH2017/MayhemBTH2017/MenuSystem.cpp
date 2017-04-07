#include "MenuSystem.h"



MenuSystem::MenuSystem()
{
	m_selection = 0;
	m_test.AddButton(glm::vec2(0.0f), glm::vec2(0.3f));
	m_test.AddButton(glm::vec2(-0.3f), glm::vec2(0.3f));

	defaultColor = glm::vec4(0.0, 0.5, 0.5, 0.0);
	selectColor = glm::vec4(0.0, 1.0, 1.0, 0.0);
}

MenuSystem::~MenuSystem()
{
}


void MenuSystem::Update()
{
	SelectionUpdate();
	m_test.Render();
}

void MenuSystem::SelectionUpdate()
{
	//m_down = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN);
	//m_up = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_UP);
	//m_a = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_A);

	InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN);

	if (InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN) || InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN))
	{
		if (m_selection < m_test.GetButtonArr().GetSize() - 1)
		{
			m_selection += 1;
			m_test.GetButtonArr()[m_selection - 1].SetColor(defaultColor);
			m_test.GetButtonArr()[m_selection].SetColor(selectColor);
		}
	}

	if (InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_UP))
	{
		if (m_selection > 0)
		{
			m_selection -= 1;
			m_test.GetButtonArr()[m_selection + 1].SetColor(defaultColor);
			m_test.GetButtonArr()[m_selection].SetColor(selectColor);
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
