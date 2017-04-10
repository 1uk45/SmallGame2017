#include "Canvas.h"


Canvas::Canvas() 
{
	defaultColor = glm::vec4(0.0, 0.5, 0.5, 0.0);
	selectColor = glm::vec4(0.0, 1.0, 1.0, 0.0);
}


Canvas::~Canvas()
{
}

void Canvas::AddSprite(glm::vec2 pos, glm::vec2 size)
{

	//ändra så att sprite class har color etc...
	Sprite newSprite("leo", true);

	newSprite.Init(pos.x, pos.y, size.x, size.y);
	newSprite.SetColor(defaultColor);
	m_spriteArr.PushBack(newSprite);

}

void Canvas::AddButton(glm::vec2 pos, glm::vec2 size)
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

void Canvas::AddText(glm::vec2 pos, glm::vec2 size, char* text)
{
	Text newSprite;

	newSprite.Init(pos.x, pos.y, size.x, size.y);
	newSprite.SetColor(defaultColor);
	m_textArr.PushBack(newSprite);

	if (m_buttonArr.GetSize() == 1)
	{
		m_buttonArr[0].SetColor(selectColor);
	}
}

void Canvas::Update()
{
	
}

void Canvas::Render()
{
	for (int i = 0; i < m_spriteArr.GetSize(); i++)
	{
		m_spriteArr[i].Render();
	}

	for (int i = 0; i < m_buttonArr.GetSize(); i++)
	{
		m_buttonArr[i].Render();
	}

	for (int i = 0; i < m_textArr.GetSize(); i++)
	{
		m_textArr[i].Render();
	}
}

Vector<Sprite> Canvas::GetSpriteArr()
{
	return m_spriteArr;
}

Vector<Sprite> Canvas::GetButtonArr()
{
	return m_buttonArr;
}

Vector<Text> Canvas::GetTextArr()
{
	return m_textArr;
}
