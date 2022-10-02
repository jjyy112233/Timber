#pragma once
#include "Scene.h"
#include <vector>

enum class DualMoves
{
	Left,
	Right,
	Space,
};

class MenuScene;
class SceneManager;
class DualSelectScene : Scene
{
protected:
	SpriteObject* background;
	Sound bgm;
	vector<SpriteObject*> charactor;
	SoundBuffer selectsoundbuffer;
	Sound selectsound;
	Text sment;
	Text dment;
	Text select;
	vector<int> clothes;
	DualMoves pos;
public:
	DualSelectScene(SceneManager& mgr);
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~DualSelectScene();
	virtual void Update(float dt);
	void ChangeClothes(DualMoves move);
};

