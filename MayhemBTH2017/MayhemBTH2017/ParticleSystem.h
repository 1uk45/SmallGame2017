#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__

//#include "MemoryManager.h"
//#include "StackAllocator.h"

#include <glew.h>
#include <SDL.h>
#include <glm.hpp>

#include "Vector.h"
#include "Ashader.h"
struct Particle{
	Vector<GLfloat> position;
	Vector<GLfloat> velocity;
	GLfloat birthTime;
	

};
class ParticleSystem: public AShader
{
public:
	//::..CONSTRUCTORS..:://
	ParticleSystem();
	
	//Destructor
	virtual ~ParticleSystem();

	//::..HELPER FUNCTIONS..:://

	void Update();
	void Render();
	
private:
	//::..HELPER FUNCTIONS..:://
	void AddAttributeLocation();
	void InitVBO();
private:
	GLuint m_particleBufferA, m_particleBufferB;
	GLfloat m_timer=0;
	GLuint m_timerID;
	GLuint m_particleCount;

};

#endif
