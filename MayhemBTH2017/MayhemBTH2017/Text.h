#ifndef __TEXT_H__
#define __TEXT_H__


#include <SDL_ttf.h>


class Text
{
public:
	Text();
	virtual ~Text();

	void Render();
};


#endif // __TEXT_H__