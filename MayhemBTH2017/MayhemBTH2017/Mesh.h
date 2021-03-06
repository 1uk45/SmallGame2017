#ifndef __MESH_H__
#define __MESH_H__


#include <glew.h>
#include <glm.hpp>
#include <cstdint>


#define BUFFER_OFFSET(i) ((char *)nullptr + (i))


struct Vertex2D
{
	glm::vec3 position;
	glm::vec2 texCoords;
};


struct Vertex3D
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 texCoordsAlpha;
};

struct Vertex3DSkelAnimation
{
	Vertex3D	vertex;
	glm::ivec4	jointIDs;
	glm::vec4	weights;

};


class Mesh
{
public:
	//::.. CONSTRUCTORS ..:://
	Mesh();
	virtual ~Mesh();

	//::.. INITIALIZERS ..:://
	bool LoadMesh(Vertex2D * vertices, uint64_t numVerts);
	bool LoadMesh(Vertex3D * vertices, uint64_t numVerts);
//	bool LoadMesh(Vertex3DBlendAnimation * vertices, uint64_t numVerts);
	bool FreeMesh();

	//::.. RENDER ..:://
	bool Render();

	//::.. GET FUNCTIONS ..:://
	bool GetIsLoaded();

	//::.. SET FUNCTIONS ..:://
	void SetRenderMode(GLenum renderMode);

	void Update();

private:
	bool		m_isLoaded;
	uint64_t	m_drawCount;
	GLuint		m_vao;
	GLuint		m_buffer;

	Vertex2D *	m_vertices2D;
	Vertex3D *	m_vertices3D;

	GLenum		m_renderMode;

};


#endif