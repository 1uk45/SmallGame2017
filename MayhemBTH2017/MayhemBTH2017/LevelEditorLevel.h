#ifndef __LEVELEDITORLEVEL_H__
#define __LEVELEDITORLEVEL_H__


#include "LevelExporter.h"
#include "Transform.h"
#include "DebugShaderTech.h"
#include "Camera.h"
#include "Mesh.h"


#include <glm.hpp>
#include <cstdint>


class LevelEditorLevel
{
public:
	const static int SIZE_X = 16;
	const static int SIZE_Y = 16;

	struct Block
	{
		uint32_t	textureID;
		bool		isOccupied;
		bool		isSpawnPoint;
	};

	LevelEditorLevel();
	virtual ~LevelEditorLevel();

	void Render();

	//::.. SET FUNCTIONS ..:://
	void SetTexture(uint32_t textureID);
	void SetOccupied(bool isOccupied);
	void SetSpawnPoint(bool isSpawnPoint);

private:
	//::.. HELP FUNCTIONS ..:://
	void Init();
	void InitGrid();
	void InitMeshes();


private:
	struct MeshObjects
	{
		Transform transform;
		Mesh mesh;
	};

	Block m_grid[SIZE_X][SIZE_Y];
	MeshObjects m_meshObjects[SIZE_X][SIZE_Y];
	uint32_t m_posX;
	uint32_t m_posY;

	AShader			m_debugShader;
	Camera			m_camera;
};


#endif // __LEVELEDITORLEVEL_H__