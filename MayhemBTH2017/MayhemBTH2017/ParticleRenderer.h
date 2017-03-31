#ifndef __PARTICLERENDERER_H__
#define __PARTICLERENDERER_H__

#include "MemoryManager.h"
#include "StackAllocator.h"

#include <glew.h>
#include <SDL.h>
#include <glm.hpp>
#include <iostream>
#include <fstream>
#include <string>
class ParticleRenderer:public Ashader
{
public:
	ParticleRenderer();
	virtual ~ParticleRenderer();
};

#endif
