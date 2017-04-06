#ifndef __GUI_H__
#define __GUI_H__


#include "AShader.h"
#include "Sprite.h"
#include "Vector.h"
#include "String.h"
#include "InputManager.h"
#include "VideoManager.h"


#include <SDL.h>


class Menu
{
public:
	Menu();
	virtual ~Menu();

	void AddSprite(glm::vec2 pos, glm::vec2 size);

	void AddButton(glm::vec2 pos, glm::vec2 size);

	void Update();

	void Render();

	void SelectionUpdate();

	int GetSelect();

private:

	int m_selection;
	glm::vec4 defaultColor, selectColor;

	Vector<Sprite> m_spriteArr;
	Vector<Sprite> m_buttonArr;

};



#endif // !__GUI_H__
