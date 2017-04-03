#include "ParticleSystem.h"

#define BUFFER_OFFSET(i) ((char *)nullptr + (i))
//::..CONSTRUCTORS..:://

ParticleSystem::ParticleSystem()
{
}

//Destructor

ParticleSystem::~ParticleSystem()
{
}

//::..HELPER FUNCTIONS..:://

void ParticleSystem::Update() {
	
	//update particle timer
	m_timer += 2.0f;
	if (m_timer > 100.0f)
		m_timer == 0.0f;
}

void ParticleSystem::Render() {

	this->Bind();
	glEnable(GL_RASTERIZER_DISCARD); // Discard the rasterizer stage
	glBindBuffer(GL_ARRAY_BUFFER, m_particleBufferA);
	//Target buffer
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, m_particleBufferB); 

	//GPU transform calculations
	glBeginTransformFeedback(GL_POINTS);
	glDrawArrays(GL_POINTS, 0, m_particleCount);
	glEndTransformFeedback();

	//Swap A and B buffers
	std::swap(m_particleBufferA, m_particleBufferB);
	//Turn Rasterizer ON
	glDisable(GL_RASTERIZER_DISCARD);

	//Draw the particles which have now been swapped and transformed
	glBindBuffer(GL_ARRAY_BUFFER, m_particleBufferA);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(GLfloat) * 8)); //3 float vector													 
	glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(GLfloat) *11)); //3 float vector
	glVertexAttribPointer(5, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(GLfloat) * 12)); //float
	
	glDrawArrays(GL_POINTS, 0, m_particleCount);
}

void ParticleSystem::AddAttributeLocation() {
	
	glBindAttribLocation(this->GetProgramID(), 3, "particle_Position_vert");
	glBindAttribLocation(this->GetProgramID(), 4, "particle_Velocity_vert");
	glBindAttribLocation(this->GetProgramID(), 5, "particle_TimeAlive_vert");

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(GLfloat) * 8)); //3 float vector													 
	glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(GLfloat) * 11)); //3 float vector
	glVertexAttribPointer(5, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(GLfloat) * 12)); //float

	//Particle Timer
	m_timerID = glGetUniformLocation(this->GetProgramID(), "particle_Timer");
	glUniform1f(m_timerID, m_timer);
	
	//These are the names of the outputs from our geometry shader which will be recorded in the transform feedack buffer
	const char* transformFeedbackInput[3] = { "tf_Position", "tf_TimeAlive", "tf_Velocity" };
	glTransformFeedbackVaryings(this->GetProgramID(), 3, transformFeedbackInput, GL_INTERLEAVED_ATTRIBS);
}

void ParticleSystem::InitVBO(){

	const int PARTICLE_COUNT = 100000;
	m_particleCount = PARTICLE_COUNT;
	Particle particles[PARTICLE_COUNT] = {};

	//Use two VBO to ping-pong data on the GPU.
	
	//Buffer A, even frames input
	glGenBuffers(1, &m_particleBufferA);
	glBindBuffer(GL_ARRAY_BUFFER, m_particleBufferA);
	glBufferData(GL_ARRAY_BUFFER, sizeof(particles), &particles[0], GL_STREAM_DRAW);

	//Buffer B, even frames output
	glGenBuffers(1, &m_particleBufferB);
	glBindBuffer(GL_ARRAY_BUFFER, m_particleBufferB);
	//BufferData is here uninitialized. It is needed in buffer A though to transfer from CPU to GPU.
	glBufferData(GL_ARRAY_BUFFER, sizeof(particles), 0, GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


}