#include "SpriteObject.h"

SpriteObject& SpriteObject::operator=(const SpriteObject& ref)
{
	return *this;
}

SpriteObject::SpriteObject(Texture& tex, Vector2f pos)
{
	sprite.setTexture(tex);
	sprite.setPosition(pos);

	Init();
}

SpriteObject::~SpriteObject()
{
	Release();
}

void SpriteObject::Init()
{

}

void SpriteObject::Release()
{
}

void SpriteObject::Update(float dt)
{
}

void SpriteObject::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

Vector2f SpriteObject::GetPosition()
{
	return sprite.getPosition();
}

Vector2f SpriteObject::GetSize() const
{
	FloatRect rect = sprite.getLocalBounds();
	return Vector2f{ rect.width, rect.height };
}

void SpriteObject::SetPosition(Vector2f pos)
{
	sprite.setPosition(pos);
}

void SpriteObject::Translate(Vector2f delta)
{
	Vector2f pos = sprite.getPosition() + delta;
	pos += delta;
	sprite.setPosition(pos);
}

void SpriteObject::SetOrigin(Origins orgin)
{
	Utils::SetOrigin(sprite, orgin);
}

void SpriteObject::SetFlipX(bool flip)
{
	Vector2f scale = sprite.getScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	sprite.setScale(scale);
}
