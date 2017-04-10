#include "ParticleSystem.h"



ParticleSystem::ParticleSystem(std::string shadername, glm::vec3 pos, glm::vec3 col)

{
	m_drawShader.Init("DrawShader", 1, 0); //Shade for drawing the transformed particles
	m_pShader.Init(shadername, false, 1); //sets varying to "outValue" and only uses a vertex shader

	glLinkProgram(m_pShader.GetProgramID()); ///////////////////////////////////////////////LINK THE PROGRAM
	glUseProgram(m_pShader.GetProgramID());

	//GENERATE VERTEX ARRAY OBJECT
	glGenVertexArrays(1, &m_vao[0]); //Vertex array object to store  the data
	glBindVertexArray(m_vao[0]); //use this vertex arrray object


	Particle particle[10000];

	for (uint64_t i = 0; i < 10000; i++) {

		particle[i].position = pos;
		particle[i].color = col;
		particle[i].direction = normalize(GetRandomDir());
		particle[i].velocity = 0.5f;
		particle[i].timeAlive = 0.0f;
	}


	//BUFFERS
	glGenBuffers(1, &m_particleBufferA);
	glBindBuffer(GL_ARRAY_BUFFER, m_particleBufferA);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Particle)*PARTICLE_COUNT, particle, GL_STREAM_DRAW);

	offset = 0;
	//SET ATTRIBUTE POINTERS
	inPosID = glGetAttribLocation(m_pShader.GetProgramID(), "inPos");
	glEnableVertexAttribArray(inPosID);
	glVertexAttribPointer(inPosID, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(0));
	offset += 3;

	inDirID = glGetAttribLocation(m_pShader.GetProgramID(), "inDir");
	glEnableVertexAttribArray(inDirID);
	glVertexAttribPointer(inDirID, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(glm::vec3)));
	offset += 3;

	inColID = glGetAttribLocation(m_pShader.GetProgramID(), "inCol");
	glEnableVertexAttribArray(inColID);
	glVertexAttribPointer(inColID, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(glm::vec3) * 2));
	offset += 3;

	inVelID = glGetAttribLocation(m_pShader.GetProgramID(), "inVel");
	glEnableVertexAttribArray(inVelID);
	glVertexAttribPointer(inVelID, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(glm::vec3) * 3));
	offset += 1;

	inTimeID = glGetAttribLocation(m_pShader.GetProgramID(), "inLife");
	glEnableVertexAttribArray(inTimeID);
	glVertexAttribPointer(inTimeID, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(glm::vec3) * 3 + sizeof(GLfloat)));

	//Buffer to hold the outValue retrieved from the geopass vertex shader
	glGenBuffers(1, &m_particleBufferB);
	glBindBuffer(GL_ARRAY_BUFFER, m_particleBufferB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Particle)*PARTICLE_COUNT, 0, GL_STREAM_DRAW); //does not have any initial value (since its on the GPU)

	glEnable(GL_RASTERIZER_DISCARD); //Disable rasterizer
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, m_particleBufferB);

	//defines bufferB as the current transform feedback buffer
	//BUFFER A->BUFFER B
	//SEND THE DATA TO BUFFER B
	//The output from geometrypass-vertexshader is catched by the transformBuffer!
	glBeginTransformFeedback(GL_POINTS);
	glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);
	glEndTransformFeedback();
	glFlush();

	std::swap(m_particleBufferA, m_particleBufferB); //input in bufferB becomes input 

	glDisable(GL_RASTERIZER_DISCARD);
	glBindVertexArray(0);





	//// INFO FOR TRIANGLE

	Transform tpm;
	tpm.SetPosition(0, 0, 100);
	tmpTransform = tpm;

}
glm::vec3 ParticleSystem::GetRandomDir() {

	return glm::vec3((rand() % (0, 1000 + 1000)) - 1000, (rand() % (0, 1000 + 1000)) - 1000, (rand() % (0, 1000 + 1000)) - 1000);
}

void ParticleSystem::ShadersInit() {





}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::AddAttributeLocation() {





}


void ParticleSystem::AddTimerUniform() {

	this->AddUniforms();

}

void ParticleSystem::TransformFeedbackSwap() {



}

void ParticleSystem::LoadParticleVBOS(Particle* p, GLuint nrOfVerts) {


}

void ParticleSystem::RenderTransformed() {


	glUseProgram(m_drawShader.GetProgramID()); //the program that draws the transformed particle
	glBindVertexArray(m_drawVAO);
	glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);
	glBindVertexArray(0);

}
void ParticleSystem::UpdateParticles() {

	glUseProgram(m_pShader.GetProgramID());

	glEnable(GL_RASTERIZER_DISCARD);
	glBindBuffer(GL_ARRAY_BUFFER, m_particleBufferA);


	//SET ATTRIBUTE POINTERS
	inPosID = glGetAttribLocation(m_pShader.GetProgramID(), "inPos");
	glEnableVertexAttribArray(inPosID);
	glVertexAttribPointer(inPosID, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(0));

	inDirID = glGetAttribLocation(m_pShader.GetProgramID(), "inDir");
	glEnableVertexAttribArray(inDirID);
	glVertexAttribPointer(inDirID, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(glm::vec3)));

	inColID = glGetAttribLocation(m_pShader.GetProgramID(), "inCol");
	glEnableVertexAttribArray(inColID);
	glVertexAttribPointer(inColID, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(glm::vec3) * 2));

	inVelID = glGetAttribLocation(m_pShader.GetProgramID(), "inVel");
	glEnableVertexAttribArray(inVelID);
	glVertexAttribPointer(inVelID, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(glm::vec3) * 3));

	inTimeID = glGetAttribLocation(m_pShader.GetProgramID(), "inLife");
	glEnableVertexAttribArray(inTimeID);
	glVertexAttribPointer(inTimeID, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), BUFFER_OFFSET(sizeof(glm::vec3) * 3 + sizeof(GLfloat)));

	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, m_particleBufferB);

	glBeginTransformFeedback(GL_POINTS);
	glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);
	glEndTransformFeedback();
	std::swap(m_particleBufferA, m_particleBufferB);
	glDisable(GL_RASTERIZER_DISCARD);

	//glGetBufferSubData(GL_TRANSFORM_FEEDBACK_BUFFER, 0, sizeof(info), &info);
	//std::cout << info[0] << ". " << info[1] << ", " << info[2] << ", " << info[3] << ", " << info[4] << ", " << info[5] << std::endl;


	const static int SIZE_X = 84;
	const static int SIZE_Y = 48;

	m_camera.SetRotation(0.0f, -0.0f);
	m_camera.SetPosition(glm::vec3(((SIZE_X / 2) - 0.5f), ((SIZE_Y / 2) + 0.5f), -60));

	m_drawShader.Bind();
	m_drawShader.Update(tmpTransform, m_camera);
	RenderTransformed();

}

