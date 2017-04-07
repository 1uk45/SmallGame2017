#include "SpriteImage.h"



SpriteImage::SpriteImage() : ASprite()
{

}

SpriteImage::SpriteImage(const std::string & filename, bool geom) : ASprite()
{

}

SpriteImage::~SpriteImage()
{
	
}

void SpriteImage::Init(float x, float y, float width, float height)
{
	//calls onto the abstract class

}

void SpriteImage::SetImage()
{
	//add texture / image
}

void SpriteImage::Render() const
{
	//update image
}
