#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <glew.h>
#include "GUIQuad.h"
#include "AShader.h"
#include "ImageLoader.h"

class Sprite
{
public:
	Sprite(const std::string & filename, bool geom);
	virtual ~Sprite();

	void Init(float x, float y, float width, float height, glm::vec3 color);

	glm::vec3 SetColor(glm::vec3 color);

	void setTexture(std::string filePath);

	void Draw();

private:
	GLint m_loc;
	GLint m_locTex;
	GLint m_locUV;
	glm::vec4 m_BB;
	GLboolean m_isSelected;
	GLuint m_vboID;
	GUIQuad m_quad;
	void AddAttributeLocation();
	AShader *shader;
	GLTexture m_texture;
};

#endif // !__SPRITE_H__


