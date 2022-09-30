#pragma once
#include "TitleScene.h"
#include "MenuScene.h"
#include "SingleScene.h"
#include "DualScene.h"
class SceneManager
{
protected:
	Vector2u size;
public:
	SceneManager(Vector2u size);
	map<SceneTypes,Scene*> scenes;
	Vector2u GetSize();
	void SceneInit();
	void SceneUpdata(float dt);
	void SceneDraw(RenderWindow& window);
	void MoveScene(SceneTypes type, vector<int> sceneInfo = vector<int>());

};