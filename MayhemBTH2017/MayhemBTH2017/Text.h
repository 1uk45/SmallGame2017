#ifndef __TEXT_H__
#define __TEXT_H__


#include <SDL_ttf.h>


class Text
{
public:
	Text();
	virtual ~Text();

	void Render();
private:
	SDL_Renderer* m_renderer;
	TTF_Font * m_font;
	SDL_Color m_color;
	SDL_Surface* m_surfaceMessage;
	SDL_Texture* m_message;

	SDL_Rect m_messageRect;

};


#endif // __TEXT_H__