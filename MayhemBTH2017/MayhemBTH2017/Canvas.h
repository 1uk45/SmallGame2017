#ifndef __CANVAS_H__
#define __CANVAS_H__


#include "AShader.h"
#include "Sprite.h"
#include "Vector.h"
#include "String.h"
#include "InputManager.h"
#include "VideoManager.h"
#include "Text.h"

#include <SDL.h>


class Canvas
{
public:
	Canvas();
	virtual ~Canvas();

	//::.. MODIFY FUNCTIONS ..:://
	void AddSprite(glm::vec2 pos, glm::vec2 size);
	void AddButton(glm::vec2 pos, glm::vec2 size);
	void AddText(glm::vec2 pos, glm::vec2 size, char* text);
	
	void Update();
	void Render();
	void SelectionUpdate();
	int GetSelect();

private:

	int m_selection;
	glm::vec4 defaultColor, selectColor;

	Vector<ASprite> m_spriteArr;
	Vector<ASprite> m_buttonArr;
	Vector<Text> m_textArr;

};



#endif // __CANVAS_H__
