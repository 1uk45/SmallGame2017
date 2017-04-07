#include "Menu.h"

#include <sdl_ttf.h>

Menu::Menu(glm::vec4 defaultColor, glm::vec4 selectColor)
{
	defaultColor = defaultColor;
	selectColor = selectColor;
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

Vector<Sprite> &Menu::GetSpriteArr()
{
	return m_spriteArr;
}

Vector<Sprite> &Menu::GetButtonArr()
{
	return m_buttonArr;
}
