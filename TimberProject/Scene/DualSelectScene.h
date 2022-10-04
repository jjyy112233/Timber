#pragma once
#include "Scene.h"
#include <vector>

enum class DualMoves
{
	Left,
	Right,
	A,
	D,
	Space,
};

class MenuScene;
class SceneManager;
class DualSelectScene : public Scene
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
	TextObject* select;
	vector<int> clothes;
	SpriteObject* player1;
	SpriteObject* player2;
	int p1;
	int p2;

public:
	DualSelectScene(SceneManager& mgr);
	virtual void Init();
	virtual void Set(vector<Texture*> cloths) {};
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~DualSelectScene();
	virtual void Update(float dt);
	void ChangeClothes(DualMoves move);
};

