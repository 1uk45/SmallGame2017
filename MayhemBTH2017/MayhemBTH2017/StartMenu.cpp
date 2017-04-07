#include "StartMenu.h"



StartMenu::StartMenu()
{
}


StartMenu::~StartMenu()
{
}

void StartMenu::Init()
{
	m_canvas.AddButton(glm::vec2(0.0f), glm::vec2(0.3f));

	MainMenu * menu = new MainMenu;
	
	AddChild(menu);

}

void StartMenu::Update()
{

}

void StartMenu::Render()
{

}
