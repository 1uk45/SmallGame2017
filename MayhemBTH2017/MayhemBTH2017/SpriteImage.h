#ifndef __SPRITEIMAGE_H__
#define __SPRITEIMAGE_H__

#include "ASprite.h"

class SpriteImage : public ASprite
{
public:
	SpriteImage();
	SpriteImage(const std::string & filename, bool geom);
	virtual ~SpriteImage();

	void Init(float x, float y, float width, float height);

	void SetImage();

	void Render() const;

private:


};

#endif // !__SPRITEIMAGE_H__
