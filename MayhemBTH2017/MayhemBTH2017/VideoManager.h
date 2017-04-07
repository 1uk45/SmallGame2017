#ifndef __VIDEOMANAGER_H__
#define __VIDEOMANAGER_H__


#include "glew.h"
#include <Windows.h>
#include <assert.h>
#include <string>
#include <SDL.h>
#include <glm.hpp>
#include <iostream>

enum ScreenResolution
{
	SCRRES_640X480 = 0,
	SCRRES_800X600,
	SCRRES_1024X600,
	SCRRES_1024X768,
	SCRRES_1152X864,
	SCRRES_1280X720,
	SCRRES_1280X768,
	SCRRES_1280X800,
	SCRRES_1280X1024,
	SCRRES_1360X768,
	SCRRES_1366X768,
	SCRRES_1440X900,
	SCRRES_1600X900,
	SCRRES_1600X1200,
	SCRRES_1680X1050,
	SCRRES_1920X1080,
	SCRRES_1920X1200,
	SCRRES_2560X1440,
	SCRRES_2560X1600,
	SCRRES_3840X2160,
};


class VideoManager
{
public:
	//::.. DUMMY CONSTRUCTORS ..:://
	VideoManager();
	virtual ~VideoManager();

	//::.. FAKE FUNCTIONS ..:://
	void StartUp();
	void ShutDown();

	//::.. SET FUNCTIONS ..:://
	void SetIsOpen(bool isOpen);
	void SetFullscreen(bool fullscreen);
	void SetScreenResolution(uint32_t x);

	//::.. GET FUNCTIONS ..:://
	static VideoManager* Get();
	bool GetIsOpen() const;
	int GetScreenHeight() const;
	int GetScreenWidth() const;
	SDL_Window* GetWindow() const;

	//::.. UPDATE FUNCTIONS ..:://
	void Swap();

private:
	//::.. HELPER FUNCTIONS ..:://
	void Init();
	void SetAttributes();

private:
	static VideoManager * m_instance;

	SDL_Window *	m_window;
	SDL_Renderer *	m_renderer;

	glm::vec2	m_scrRes;
	bool		m_isFullScreen;

	bool			m_isOpen;
	uint32_t		m_screenHeight;
	uint32_t		m_screenWidth;
	SDL_GLContext	m_glContext;


};


#endif