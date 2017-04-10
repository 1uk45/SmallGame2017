#include "Mesh.h"



//::.. CONSTRUCTORS ..:://
Mesh::Mesh()
	: m_isLoaded(false), m_drawCount(0)
{

}

Mesh::~Mesh()
{
	FreeMesh();
}


//::.. INITIALIZERS ..:://
bool Mesh::LoadMesh(Vertex * vertices, uint64_t numVerts, uint16_t numAttr)
{
	if (m_isLoaded)
	{
		return false;
	}

	m_drawCount = numVerts;

	// Generate VAO.
	glGenVertexArrays(1, &m_vao);

	// Bind VAO.
	glBindVertexArray(m_vao);

	// Enable attributes.
	for (uint16_t i = 0; i < numAttr; i++)
	{
		glEnableVertexAttribArray(i);
	}

	// Generate buffers.
	glGenBuffers(1, &m_buffer);

	glBindBuffer(GL_ARRAY_BUFFER, m_buffer);

	// Copy data to the gpu.
	glBufferData(GL_ARRAY_BUFFER, sizeof (Vertex) * numVerts, vertices, GL_STATIC_DRAW);
	
	uint64_t offset = 0;

	// Position.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(offset));
	offset += 3;
	
	// Normal.
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(offset));
	offset += 3;
	
	// Texture Coordinates.
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(offset));

	// Unbind
	glBindVertexArray(0);


	m_isLoaded = true;
	return true;
}

bool Mesh::FreeMesh()
{
	if (!m_isLoaded)
	{
		return false;
	}

	glDeleteVertexArrays(1, &m_vao);

	m_isLoaded = false;
	return true;
}


//::.. RENDER ..:://
bool Mesh::Render()
{

	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glBindVertexArray(0);
	return true;
}


//::.. GET FUNCTIONS ..:://
bool Mesh::GetIsLoaded()
{
	return m_isLoaded;
}
