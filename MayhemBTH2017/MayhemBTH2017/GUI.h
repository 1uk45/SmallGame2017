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

	void AddSprite(Sprite sprite);

	void Update();

	void Render();

private:

	int m_selection;
	bool m_up, m_down, m_trueOnce;

	Vector<Sprite> m_spriteArr;
	Vector<Sprite> m_buttonArr;
	

};



#endif // !__GUI_H__
