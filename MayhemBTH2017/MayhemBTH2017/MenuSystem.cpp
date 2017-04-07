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
