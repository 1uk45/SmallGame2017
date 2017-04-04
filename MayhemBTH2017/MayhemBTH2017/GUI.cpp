#include "GUI.h"
#include "InputManager.h"
#include "VideoManager.h"



GUI::GUI(const std::string & filename, bool geom) 
	: AShader(filename, geom)
{

}


GUI::~GUI()
{
}

void GUI::AddSprite(Sprite sprite)
{
	m_spriteArr.PushBack(sprite);
}

void GUI::Update()
{



	InputManager::Get()->Update();
	InputManager::Get()->
	/*int mouse_x;
	int mouse_y;

	SDL_GetMouseState(&mouse_x, &mouse_y);

	float new_mouseX = VideoManager::Get()->GetScreenWidth() / (float)mouse_x;
	float new_mouseY = VideoManager::Get()->GetScreenHeight() / (float)mouse_y;*/

	for (int i = 0; i < m_spriteArr.GetSize(); i++)
	{
		m_spriteArr[i].ButtonUpdate(mouse_x, mouse_y);
	}

	GLint myLoc = glGetUniformLocation(GetProgramID(), "color");
	glProgramUniform3f(GetProgramID(), myLoc, 1, 1, 1);
}

void GUI::Render()
{
	Bind();
	for (int i = 0; i < m_spriteArr.GetSize(); i++)
	{
		m_spriteArr[i].Draw();
	}

	Release();
}

void GUI::AddAttributeLocation()
{

}
