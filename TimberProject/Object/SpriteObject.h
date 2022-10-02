#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils.h"

using namespace sf;
using namespace std;

class SpriteObject
{
protected:
	Sprite sprite;

	SpriteObject(const SpriteObject& ref);
	SpriteObject& operator=(const SpriteObject& ref);
public:
	SpriteObject(Texture& tex, Vector2f pos = Vector2f());
	virtual ~SpriteObject();

	virtual void Init();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
	virtual void SetPosition(Vector2f pos);

	Vector2f GetPosition();
	Vector2f GetSize() const;
	void Translate(Vector2f delta);
	void SetOrigin(Origins orgin);
	void SetOrigin(Vector2f origins);
	Vector2f GetOrigin();
	void SetScale(Vector2f scale);
	void SetTexture(Texture& tex);

	virtual void SetFlipX(bool flip);
};

