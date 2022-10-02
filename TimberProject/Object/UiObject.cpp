#include "UiObject.h"

UiObject& UiObject::operator=(const UiObject& ref)
{
	return *this;
}

UiObject::UiObject(string str,Font& font,int size,const Color& color, Vector2f pos)
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(str);
	text.setPosition(pos);

	Init();
}

UiObject::~UiObject()
{
	Release();
}

void UiObject::Init()
{

}

void UiObject::Release()
{
}

void UiObject::Update(float dt)
{
}

void UiObject::Draw(RenderWindow& window)
{
	window.draw(text);
}

Vector2f UiObject::GetPosition()
{
	return text.getPosition();
}
void UiObject::SetString(string str)
{
	text.setString(str);
}

void UiObject::SetSize(int size)
{
	text.setCharacterSize(size);
}

void UiObject::SetScale(Vector2f scale)
{
	text.setScale(scale);
}

Vector2f UiObject::GetSize() const
{
	FloatRect rect = text.getLocalBounds();
	return Vector2f{ rect.width, rect.height };
}

void UiObject::SetPosition(Vector2f pos)
{
	text.setPosition(pos);
}

void UiObject::Translate(Vector2f delta)
{
	Vector2f pos = text.getPosition() + delta;
	pos += delta;
	text.setPosition(pos);
}

void UiObject::SetOrigin(Origins orgin)
{
	Utils::SetOrigin(text, orgin);
}

void UiObject::SetFillColor(Color color)
{
	text.setFillColor(color);
}

void UiObject::SetFlipX(bool flip)
{
	Vector2f scale = text.getScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	text.setScale(scale);
}
