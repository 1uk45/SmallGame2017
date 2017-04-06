#ifndef __TEXT_H__
#define __TEXT_H__


#include "AShader.h"
#include "GUIQuad.h"

#include <glm.hpp>
#include <glew.h>
#include <SDL_ttf.h>


class Text
{
public:
	Text();
	virtual ~Text();

	void Init(float x, float y, float width, float height);
	void SetColor(glm::vec4 color);
	void Render();
	void Bind();

private:
	void AddAttributeLocation();

private:
	GLint m_loc;
	GLint m_locTex;
	GLint m_locUV;
	glm::vec4 m_bb;
	GLboolean m_isSelected;
	GLuint m_vboID;
	GUIQuad m_quad;
	AShader *m_shader;
	GLTexture m_text;
	GLuint m_texture;
	Mesh m_mesh;
	Transform m_transform;

};


#endif // __TEXT_H__