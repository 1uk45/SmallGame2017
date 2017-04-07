#ifndef __SPRITETEXT_H__
#define __SPRITETEXT_H__

#include "ASprite.h"

class SpriteText : public ASprite
{
	SpriteText();
	SpriteText(const std::string & filename, bool geom);
	virtual ~SpriteText();

	void Init(float x, float y, float width, float height);

	void SetText();

	void Render() const;

private:


};

#endif // !__SPRITETEXT_H__

