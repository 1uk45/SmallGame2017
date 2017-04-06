#ifndef __GUI_H__
#define __GUI_H__

#include <SDL.h>

#include "AShader.h"
#include "Sprite.h"
#include "Vector.h"
#include "String.h"


class GUI
{
public:
	GUI();
	virtual ~GUI();

	void AddSprite(glm::vec2 pos, glm::vec2 size, bool isButton);

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
