#include "Texture.h"


Texture::Texture(void)
{
}


Texture::~Texture(void)
{
}

void Texture::load(std::string location)
{
	m_texture.load(location);
}

void Texture::bind()
{
	m_texture.bind();
}