#include "ActiveObject.h"

ActiveObject::ActiveObject(Texture& tex, Vector2f pos)
	:SpriteObject(tex, pos), speed(0)
{
	//Init();
}

ActiveObject::~ActiveObject()
{
	//Release();
}

void ActiveObject::Init()
{
	speed = (float)(rand() % (speedRange.y - speedRange.x)) + speedRange.x;
	startPos.y = (float)((rand() % (yRange.y - yRange.x)) + yRange.x);
	endPos.y = (float)startPos.y;
	SetPosition(startPos);
}

void ActiveObject::Update(float dt)
{
	Vector2f pos = GetPosition();
	float distanceX = endPos.x - pos.x;
	if (abs(distanceX) < 10)
		Init();

	Translate(direction * speed * dt);
}

void ActiveObject::Set(Vector2i sRange, Vector2i yRange, Vector2f start, Vector2f end)
{
	speedRange = sRange;
	this->yRange = yRange;
	startPos = start;
	endPos = end;

	direction = (endPos.x > startPos.x) ? Vector2f(1, 0) : Vector2f(-1, 0);
}
