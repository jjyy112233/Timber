#pragma once
#include "Scene.h"
#include <vector>

enum class SelectMoves
{
	Left,
	Right,
	A,
	D,
};

class MenuScene;
class SceneManager;
class CharactorSelectScene
{
protected:

public:
	CharactorSelectScene(SceneManager& mgr);
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~CharactorSelectScene();
	virtual void Update(float dt);
	void ChangeClothes(SelectMoves move);

};

