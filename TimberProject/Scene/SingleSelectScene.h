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
	vector<SpriteObject*> charactor;
	SoundBuffer selectsoundbuffer;
	Sound selectsound;
	Text sment;
	Text dment;
	Text select;
	vector<int> clothes;
	SingleMoves pos;
public:
	SingleSelectScene(SceneManager& mgr);
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~SingleSelectScene();
	virtual void Update(float dt);
	void ChangeClothes(SingleMoves move);
};

