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

	void Draw();

private:

	glm::vec4 m_BB;
	GLboolean m_isSelected;
	GLuint m_vboID;
	GUIQuad m_quad;
	void AddAttributeLocation();
	AShader *shader;
};

#endif // !__SPRITE_H__


