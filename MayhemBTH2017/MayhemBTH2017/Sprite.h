#ifndef __ASPRITE_H__
#define __ASPRITE_H__

#include <glew.h>
#include "GUIQuad.h"
#include "AShader.h"
#include "TextureManager.h"


class Sprite
{
public:
	Sprite();
	Sprite(const std::string & filename, bool geom);
	virtual ~Sprite();

	void Init(float x, float y, float width, float height);

	void SetColor(glm::vec4 color);
	void SetTexture(GLuint id, std::string filepath);

	void Render();

private:
	void AddAttributeLocation();

private:
	glm::vec4 m_bb;
	GLuint m_vboID;
	GUIQuad m_quad;
	AShader *shader;
	TextureManager *tex;
};

#endif // !__ASPRITE_H__


