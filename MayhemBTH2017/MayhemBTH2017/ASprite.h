#ifndef __ASPRITE_H__
#define __ASPRITE_H__

#include <glew.h>
#include "GUIQuad.h"
#include "AShader.h"


class ASprite
{
public:
	ASprite();
	ASprite(const std::string & filename, bool geom);
	virtual ~ASprite();

	virtual void Init(float x, float y, float width, float height) = 0;

	void SetColor(glm::vec4 color);

	virtual void Render() = 0;

private:
	void AddAttributeLocation();

private:
	glm::vec4 m_bb;
	GLuint m_vboID;
	GUIQuad m_quad;
	AShader *shader;
};

#endif // !__ASPRITE_H__


