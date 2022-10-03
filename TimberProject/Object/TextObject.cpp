#include "TextObject.h"

TextObject& TextObject::operator=(const TextObject& ref)
{
	return *this;
}

TextObject::TextObject(string str,Font& font,int size,const Color& color, Vector2f pos)
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(str);
	text.setPosition(pos);

	Init();
}

TextObject::~TextObject()
{
	Release();
}

void TextObject::Init()
{

}

void TextObject::Release()
{
}

void TextObject::Update(float dt)
{
}

void TextObject::Draw(RenderWindow& window)
{
	window.draw(text);
}

Vector2f TextObject::GetPosition()
{
	return text.getPosition();
}
void TextObject::SetString(string str)
{
	text.setString(str);
}

void TextObject::SetSize(int size)
{
	text.setCharacterSize(size);
}

void TextObject::SetScale(Vector2f scale)
{
	text.setScale(scale);
}

Vector2f TextObject::GetSize() const
{
	FloatRect rect = text.getLocalBounds();
	return Vector2f{ rect.width, rect.height };
}

void TextObject::SetPosition(Vector2f pos)
{
	text.setPosition(pos);
}

void TextObject::Translate(Vector2f delta)
{
	Vector2f pos = text.getPosition() + delta;
	pos += delta;
	text.setPosition(pos);
}

void TextObject::SetOrigin(Origins orgin)
{
	Utils::SetOrigin(text, orgin);
}

void TextObject::SetFillColor(Color color)
{
	text.setFillColor(color);
}

void TextObject::SetFlipX(bool flip)
{
	Vector2f scale = text.getScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	text.setScale(scale);
}
