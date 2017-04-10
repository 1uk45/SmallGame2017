#include "MenuSystem.h"



MenuSystem::MenuSystem()
{
	m_input = InputManager::Get();
	Init();
}

MenuSystem::~MenuSystem()
{
}


void MenuSystem::Init()
{
	AMenu* optionsMenu = new OptionsMenu;
	optionsMenu->SetParent(0);

	m_menus.push_back(optionsMenu);
	m_menus[0]->Init();


	m_currentMenu = 0;
}

void MenuSystem::Update()
{
//	std::cout << m_menus.size << std::endl

	if (m_input->GetButtonHeld(CONTROLLER_BUTTON_A))
	{
		m_menus[m_currentMenu]->Render();
	}

}

void MenuSystem::SelectionUpdate() {
	//m_down = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN);
	//m_up = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_UP);
	//m_a = InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_A);

	if (InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_DOWN))
	{
		if (m_selection < m_buttonArr.GetSize() - 1)
		{
			m_selection += 1;
			m_buttonArr[m_selection - 1].SetColor(defaultColor);
			m_buttonArr[m_selection].SetColor(selectColor);
		}
	}

	if (InputManager::Get()->GetButtonDown(CONTROLLER_BUTTON_DPAD_UP))
	{
		if (m_selection > 0)
		{
			m_selection -= 1;
			m_buttonArr[m_selection + 1].SetColor(defaultColor);
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