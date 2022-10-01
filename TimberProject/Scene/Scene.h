#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Object/SpriteObject.h"
#include "../Object/UiObject.h"
#include <list>
//#include "../UiObject.h"

using namespace sf;
using namespace std;

class SceneManager;
enum class SceneTypes
{
	None = -1,
	TITLE,
	MENU,
	SINGLE,
	DUAL,
	Count,
};

class Scene
{
protected:
	SceneManager& mgr;
	Vector2u size;
	list<SpriteObject*> objs;
	list<UiObject*> uis;
public:
	Scene(SceneManager& mgr);
	virtual void Init() = 0;
	virtual void Draw(RenderWindow& window) = 0;
	virtual void Release() = 0;
	virtual ~Scene();
	virtual void Update(float dt) = 0;
};

