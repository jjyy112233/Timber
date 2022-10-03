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
	Texture tex;
	Sprite loading;
	Font font;
	Text loadingText;

	Vector2u size;
	map<SceneTypes,Scene*> scenes;
	SceneTypes nowScene;
public:
	SceneManager(Vector2u size, RenderWindow& window);
	~SceneManager();
	void AddScene(SceneTypes type, Scene* scene);
	Vector2u GetSize();
	void SceneInit();
	void SceneUpdata(float dt);
	void SceneDraw(RenderWindow& window);
	void MoveScene(SceneTypes type, vector<Texture*> sceneInfo = vector<Texture*>());
};