#include "MenuSystem.h"



MenuSystem::MenuSystem()
{
	m_test.AddButton(glm::vec2(1.0f), glm::vec2(0.3f));
	m_test.AddButton(glm::vec2(0.0f,-0.3f), glm::vec2(0.3f));
	m_test.AddText(glm::vec2(0.0f), glm::vec2(0.2f), "lol");
}

MenuSystem::~MenuSystem()
{
}


void MenuSystem::Update()
{
//	m_test.SelectionUpdate();
	m_test.Render();
}
