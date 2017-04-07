#include "OptionsMenu.h"



OptionsMenu::OptionsMenu()
{
}


OptionsMenu::~OptionsMenu()
{
}


void OptionsMenu::Init()
{
	m_canvas.AddButton(glm::vec2(0.0), glm::vec2(0.2f, 0.4f));
	m_canvas.AddButton(glm::vec2(0.4f), glm::vec2(0.2f, 0.4f));


}

void OptionsMenu::Update()
{
	
}

void OptionsMenu::Render()
{
	m_canvas.SelectionUpdate();
	m_canvas.Render();
}

void OptionsMenu::MoveUp()
{
	m_canvas.SelectionUpdate();
}

void OptionsMenu::MoveDown()
{
	m_canvas.SelectionUpdate();
}

void OptionsMenu::PressedDown()
{
}
