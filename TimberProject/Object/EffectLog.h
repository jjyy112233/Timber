#pragma once
#include "SpriteObject.h"
#include "SFML/Audio.hpp"
class EffectLog : public SpriteObject
{
private:
	Vector2f velocity;
	float angularVelocity;
	float duration;
	float timer;

	bool active;
	Sound chopSound;

public:
	static const Vector2f Gravity; //public Static const�� �빮�ڷ� �ϴ� 

	EffectLog(Texture& tex, float duration);
	~EffectLog();

	void Fire(const Vector2f v, float av);
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
	bool GetActive();
};

