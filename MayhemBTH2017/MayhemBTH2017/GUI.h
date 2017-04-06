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

	void AddSprite(Sprite sprite, glm::vec2 pos, glm::vec2 size, bool isButton, glm::vec3 color);

	void Update();

	void Render();

	void Target(bool button1, bool button2, glm::vec3 selectColor, glm::vec3 defaultColor);

private:

	int m_selection;
	bool m_up, m_down, m_trueOnce;

	Vector<Sprite> m_spriteArr;
	Vector<Sprite> m_buttonArr;
};



#endif // !__GUI_H__
