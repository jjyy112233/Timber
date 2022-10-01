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
	sprite.setOrigin(tree.GetSize().x * 0.5f * -1, 0);
}

void Branch::SetSide(Sides side)
{
	this->side = side;
	switch (side)
	{
	case Sides::Left:
		sprite.setScale(-1, 1);
		break;
	case Sides::Right:
		sprite.setScale(1, 1);
	case Sides::None:
		break;
	}
}
Sides Branch::GetSide()
{
	return side;
}
