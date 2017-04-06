#include "Text.h"
#include "VideoManager.h"


Text::Text()
{

	m_font = TTF_OpenFont(".\\Assets\\Fonts\\SkaterGirlsRock.ttf", 28);

	// TEMP RENDERER
	m_renderer = SDL_CreateRenderer(VideoManager::Get()->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
	SDL_Color col = { 255, 255, 255 };
	m_surfaceMessage = TTF_RenderText_Solid(m_font, "HEJ", col);
	m_message = SDL_CreateTextureFromSurface(m_renderer, m_surfaceMessage);


	m_messageRect.x = 0;  //controls the rect's x coordinate 
	m_messageRect.y = 0; // controls the rect's y coordinte
	m_messageRect.w = 100; // controls the width of the rect
	m_messageRect.h = 100;
}


Text::~Text()
{

}

void Text::Render()
{
//	SDL_RenderCopy();



}
