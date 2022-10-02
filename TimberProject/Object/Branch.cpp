#include "Branch.h"
#include "../Utils.h"

Branch::Branch(Texture& tex, SpriteObject& tree)
	: SpriteObject(tex), tree(tree)
{

}

void Branch::Init()
{
	chopSound.play();
	SetSide((Sides)Utils::Range(0, 2));
	sprite.setPosition(tree.GetPosition().x, sprite.getPosition().y);

	float scale = abs(sprite.getScale().x);
	
	if(scale != 1)
		sprite.setOrigin(tree.GetSize().x * 0.5f * -(1 + scale), 0);
	else
		sprite.setOrigin(tree.GetSize().x * 0.5f * -1, 0);
}

void Branch::SetSide(Sides side)
{
	this->side = side;
	float scaleX = abs(sprite.getScale().x);
	switch (side)
	{
	case Sides::Left:
		sprite.setScale(-1 * (scaleX), (scaleX));
		break;
	case Sides::Right:
		sprite.setScale(1 * (scaleX), (scaleX));
	case Sides::None:
		break;
	}

}
Sides Branch::GetSide()
{
	return side;
}
