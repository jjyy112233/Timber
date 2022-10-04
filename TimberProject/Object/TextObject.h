#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils.h"

using namespace sf;
using namespace std;
class TextObject
{
protected:
	Text text;
	TextObject(const TextObject& ref);
	TextObject& operator=(const TextObject& ref);
public:
	TextObject(string str,Font& font,int size,const Color& color, Vector2f pos = Vector2f());
	virtual ~TextObject();

	virtual void Init();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
	virtual void SetPosition(Vector2f pos);

	Vector2f GetPosition();
	void SetString(string str);
	void SetSize(int size);
	void SetScale(Vector2f scale);
	Vector2f GetSize() const;
	void Translate(Vector2f delta);
	void SetOrigin(Origins orgin);
	void SetFillColor(Color color);

	virtual void SetFlipX(bool flip);
};

