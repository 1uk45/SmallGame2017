#ifndef __LEVELEDITOR_H__
#define __LEVELEDITOR_H__


#include "InputManager.h"
#include "Level.h"
#include "Timer.h"
#include "TextureImporter.h"
#include "LevelExporter.h"
#include "LevelImporter.h"
#include "StateManager.h"


#include <glm.hpp>
#include <cstdint>


class LevelEditor
{
public:
	const static int SIZE_X = 84;
	const static int SIZE_Y = 48;

	//::.. CONSTRUCTORS ..:://
	LevelEditor();
	virtual ~LevelEditor();

	//::.. UPDATE FUNCTIONS ..:://
	void Update();

private:
	//::.. HELP FUNCTIONS ..:://
	void AxisMove();
	void ButtonInput();
	void ClampPos();
	void RenderSelector();
	void Reset();

private:
	enum MarkerMode
	{
		NORMAL = 0,
		ADD,
		REMOVE
	};

	InputManager *		m_input;	

	Level				m_level;
	LevelExporter		m_levelExporter;
	LevelImporter		m_levelImporter;

	// MARKER
	AShader				m_green;
	uint32_t			m_currentPosX;
	uint32_t			m_currentPosY;
	uint32_t			m_savedPosX;
	uint32_t			m_savedPosY;
	Transform			m_transform;
	Camera				m_camera;
	Mesh				m_mesh;

	Timer				m_timer;
	TextureImporter		m_textureTemp;
	Texture				m_texture;

	uint32_t			m_mode;
};

#endif // __LEVELEDITOR_H__