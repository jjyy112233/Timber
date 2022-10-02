#pragma once
#include "TitleScene.h"
#include "MenuScene.h"
#include "SingleScene.h"
#include "DualScene.h"
#include "SingleSelectScene.h"
#include "DualSelectScene.h"

class SceneManager
{
protected:
	Vector2u size;
	map<SceneTypes,Scene*> scenes;
	SceneTypes nowScene;
public:
	SceneManager(Vector2u size);
	void AddScene(SceneTypes type, Scene* scene);
	Vector2u GetSize();
	void SceneInit();
	void SceneUpdata(float dt);
	void SceneDraw(RenderWindow& window);
	void MoveScene(SceneTypes type, vector<int> sceneInfo = vector<int>());
};