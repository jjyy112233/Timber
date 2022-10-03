#pragma once
#include "Scene.h"
#include <vector>

enum class SingleMoves
{
	Left,
	Right,
	Space,
};

class MenuScene;
class SceneManager;
class SingleSelectScene : public Scene
{
protected:
	SpriteObject* background;
	Sound bgm;
	Sound selectSound;
	vector<Texture*> charactor;
	SoundBuffer selectsoundbuffer;
	Sound selectsound;
	Text sment;
	Text dment;
	UiObject* select;
	vector<int> clothes;
	SingleMoves pos;
	SpriteObject* player;
	int p;
public:
	SingleSelectScene(SceneManager& mgr);
	virtual void Init();
	virtual void Set(vector<string> cloths) {};
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~SingleSelectScene();
	virtual void Update(float dt);
	void ChangeClothes(SingleMoves move);
};

