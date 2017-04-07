#include "Text.h"



Text::Text()
{
	m_vboID = 0;
	m_shader = new AShader("DebugShader", false);
}


Text::~Text()
{
}

void Text::Init(float x, float y, float width, float height)
{
	TTF_Init();

	m_bb.x = x - width / 2;
	m_bb.y = y - height / 2;
	m_bb.z = x + width / 2;
	m_bb.w = y + height / 2;

	m_quad.m_arr[0].m_position = glm::vec2(m_bb.x, m_bb.y);
	m_quad.m_arr[1].m_position = glm::vec2(m_bb.z, m_bb.y);
	m_quad.m_arr[2].m_position = glm::vec2(m_bb.x, m_bb.w);
	m_quad.m_arr[3].m_position = glm::vec2(m_bb.z, m_bb.w);



	TTF_Font* font = TTF_OpenFont(".\\Assets\\Fonts\\SkaterGirlsRock.ttf", 10); //this opens a font style and sets a size

	SDL_Color White = { 255, 255, 255 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "FUCK YOU", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

//	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture


	if (surfaceMessage == nullptr)
	{
		std::cout << "Fuck uuuu" << std::endl;
	}

	int colors = surfaceMessage->format->BytesPerPixel;
	int texture_format;
	if (colors == 4) {   // alpha
		if (surfaceMessage->format->Rmask == 0x000000ff)
			texture_format = GL_RGBA;
		else
			texture_format = GL_BGRA;
	}
	else {             // no alpha
		if (surfaceMessage->format->Rmask == 0x000000ff)
			texture_format = GL_RGB;
		else
			texture_format = GL_BGR;
	}



	Vertex verts[6];

	verts[0].position = glm::vec3((0.5f),  0.5f, -2.0f);
	verts[0].normal = glm::vec3(0.0f, 0.0f, -1.0f);
	verts[0].texCoordsAlpha = glm::vec3(0.0f, 1.0f, 0.0f);
			   
	verts[0 + 1].position = glm::vec3((  0.5f), ( - 0.5f), -2.0f);
	verts[0 + 1].normal = glm::vec3(0.0f, 0.0f, -1.0f);
	verts[0 + 1].texCoordsAlpha = glm::vec3(0.0f, 1.0f, 0.0f);
			   
	verts[0 + 2].position = glm::vec3(( - 0.5f), ( 0.5f), -2.0f);
	verts[0 + 2].normal = glm::vec3(0.0f, 0.0f, -1.0f);
	verts[0 + 2].texCoordsAlpha = glm::vec3(0.0f, 1.0f, -2.0f);
			   
	verts[0 + 3].position = glm::vec3(( - 0.5f), (  0.5f), -2.0f);
	verts[0 + 3].normal = glm::vec3(0.0f, 0.0f, -1.0f);
	verts[0 + 3].texCoordsAlpha = glm::vec3(0.0f, 1.0f, 0.0f);
			   
	verts[0 + 4].position = glm::vec3((  0.5f), ( - 0.5f), -2.0f);
	verts[0 + 4].normal = glm::vec3(0.0f, 0.0f, -1.0f);
	verts[0 + 4].texCoordsAlpha = glm::vec3(0.0f, 1.0f, 0.0f);

	verts[0 + 5].position = glm::vec3(( - 0.5f), ( - 0.5f), -2.0f);
	verts[0 + 5].normal = glm::vec3(0.0f, 0.0f, -1.0f);
	verts[0 + 5].texCoordsAlpha = glm::vec3(0.0f, 1.0f, 0.0f);

	m_transform.SetPosition(0.0f, 0.0f, 0.0f);
	m_mesh.LoadMesh(verts, 6);

//	int l = surfaceMessage->w * surfaceMessage->h;
//	std::cout << l << std::endl;
//
//	int l2 = sizeof(surfaceMessage[0].pixels) / sizeof(surfaceMessage[0]);
//	std::cout << sizeof(surfaceMessage[1].pixels) << std::endl;
//
//
//	unsigned int * pixels = (unsigned int*)malloc(sizeof(unsigned int) * l);
//
//	for (size_t i = 0; i < l; i++)
//	{
//		std::cout << (unsigned int)surfaceMessage[i].pixels << std::endl;
//		pixels[i] = (unsigned int)surfaceMessage[i].pixels;
//	}
//
//	glGenTextures(1, &m_texture);
//	glBindTexture(GL_TEXTURE_2D, m_texture);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//	glTexImage2D(GL_TEXTURE_2D, 0, colors, surfaceMessage->w, surfaceMessage->h, 0,
//		GL_RGBA, GL_UNSIGNED_BYTE, pixels);
//


}

void Text::SetColor(glm::vec4 color)
{
	//change color
	m_quad.m_color = color;

}

void Text::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}

void Text::Render()
{
//	Bind();
	m_shader->Bind();
	Camera cam;
	m_transform.SetScale(10.0f, 10.0f, 10.0f);
	m_shader->Update(m_transform, cam);
	m_mesh.Render();


}

void Text::AddAttributeLocation()
{

}