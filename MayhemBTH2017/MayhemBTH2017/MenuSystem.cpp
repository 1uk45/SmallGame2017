#include "MenuSystem.h"



MenuSystem::MenuSystem()
{
	m_test.AddSprite(glm::vec2(0.0f), glm::vec2(0.3f), true);
	m_test.AddSprite(glm::vec2(-0.3f), glm::vec2(0.3f), true);
}

MenuSystem::~MenuSystem()
{
}


void MenuSystem::Update()
{
	m_test.SelectionUpdate();
	m_test.Render();
}
