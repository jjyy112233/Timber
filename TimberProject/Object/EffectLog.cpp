#include "EffectLog.h"

const Vector2f EffectLog::Gravity = Vector2f(0.f, 2000.f);

EffectLog::EffectLog(Texture& tex, float duration)
	:SpriteObject(tex), duration(duration), active(true), angularVelocity(0), timer(0)
{
	SetOrigin(Origins::MC);
}

EffectLog::~EffectLog()
{
}

void EffectLog::Fire(const Vector2f v, float av)
{
	active = true;
	timer = 0;
	velocity = v;
	angularVelocity = av;
}

void EffectLog::Init()
{
	SpriteObject::Init();
	SetOrigin(Origins::MC);
}

void EffectLog::Release()
{
	SpriteObject::Release();
}

void EffectLog::Update(float dt)
{
	SpriteObject::Update(dt);

	timer += dt;
	if (timer > duration)
	{
		active = false;
	}

	float angle = sprite.getRotation();
	angle += angularVelocity * dt;
	sprite.setRotation(angle);

	velocity += Gravity * dt;
	Vector2f delta = velocity * dt;
	Translate(delta);
}

void EffectLog::Draw(RenderWindow& window)
{
	SpriteObject::Draw(window);
}

bool EffectLog::GetActive()
{
	return active;
}
