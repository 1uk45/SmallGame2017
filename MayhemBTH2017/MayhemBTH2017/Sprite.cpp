#include "Sprite.h"



Sprite::Sprite(const std::string & filename, bool geom)
{
	m_vboID = 0;
	shader = new AShader(filename, geom);
}


Sprite::~Sprite()
{
}

void Sprite::Init(float x, float y, float width, float height)
{

	m_BB.x = x - width / 2;
	m_BB.y = y - height / 2;
	m_BB.z = x + width / 2;
	m_BB.w = y + height / 2;

	//m_BB.x = x;
	//m_BB.y = y;
	//m_BB.z = x + width;
	//m_BB.w = y + height;

	m_quad.m_arr[0].m_position = glm::vec2(m_BB.x, m_BB.y);

	m_quad.m_arr[1].m_position = glm::vec2(m_BB.z, m_BB.y);

	m_quad.m_arr[2].m_position = glm::vec2(m_BB.x, m_BB.w);

	m_quad.m_arr[3].m_position = glm::vec2(m_BB.z, m_BB.w);

	if (m_vboID == 0)
	{
		glGenBuffers(1, &m_vboID);
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(m_quad.m_arr[0]), &m_quad.m_arr, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Sprite::SetColor(glm::vec4 color)
{
	//change color
	m_quad.m_color = color;

}

void Sprite::Draw()
{
	shader->Bind();

	GLint loc = glGetUniformLocation(shader->GetProgramID(), "color");
	glProgramUniform4f(shader->GetProgramID(), loc, m_quad.m_color.x, m_quad.m_color.y, m_quad.m_color.z, m_quad.m_color.w);


	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GUIVertex), 0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::AddAttributeLocation()
{
}
