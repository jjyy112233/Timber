#pragma once
#include "TitleScene.h"
#include "MenuScene.h"
#include "SingleScene.h"
#include "DualScene.h"

class SceneManager
{
protected:
	Vector2u size;
	RenderWindow window;
public:
	SceneManager(Vector2u size);

	void MoveScene(SceneTypes type, vector<int> sceneInfo = vector<int>());
	const Vector2u GetSize() const;
	RenderWindow& GetWindow();
};