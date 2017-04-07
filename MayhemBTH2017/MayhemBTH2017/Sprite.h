#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <glew.h>
#include "GUIQuad.h"
#include "AShader.h"


class Sprite
{
public:
	Sprite(const std::string & filename, bool geom);
	virtual ~Sprite();

	void Init(float x, float y, float width, float height);

	void SetColor(glm::vec4 color);

	void SetTexture(std::string filepath);

	void Render();

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
	AShader *shader;
	GLTexture m_texture;
};

#endif // !__SPRITE_H__


