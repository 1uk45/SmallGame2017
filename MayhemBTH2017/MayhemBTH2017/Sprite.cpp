#include "Sprite.h"



Sprite::Sprite()
{
	m_vboID = 0;
}


Sprite::~Sprite()
{
}

void Sprite::Init(float x, float y, float width, float height)
{

	m_BB.x = x;
	m_BB.y = y;
	m_BB.z = x + width;
	m_BB.w = y + height;

	m_quad.m_arr[0].m_position = glm::vec2(x, y);

	m_quad.m_arr[1].m_position = glm::vec2(x + width, y);

	m_quad.m_arr[2].m_position = glm::vec2(x, y + height);

	m_quad.m_arr[3].m_position = glm::vec2(x + width, y + height);

	m_quad.m_color = glm::vec3(0, 0, 1);


	if (m_vboID == 0)
	{
		glGenBuffers(1, &m_vboID);
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(m_quad.m_arr[0]), &m_quad.m_arr, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

glm::vec3 Sprite::ButtonUpdate(int mouse_x, int mouse_y)
{

	if (mouse_x > m_BB.x && mouse_y > m_BB.y
		&& mouse_x < m_BB.x + m_BB.z
		&& mouse_y < m_BB.y + m_BB.w)
	{
		//change color
		m_quad.m_color = glm::vec3(1,1,1);

	}
	else
	{
		m_quad.m_color = glm::vec3(0, 0, 1);
	}

	return m_quad.m_color;

}

void Sprite::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GUIVertex), 0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
