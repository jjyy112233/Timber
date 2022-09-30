#pragma once
#include "Scene.h"
#include "../Object/Player.h"

class SceneManager;
class SingleScene : public Scene
{
protected:
	Sprite background;
	Sound bgm;
	Text ment;

	Player player;
	vector<Branch*> branchs; //가지들은 오브젝트풀로, 가지가 사운드 가지고 있게 하자
	
	list<SpriteObject*> objs; //오브젝트들 동적할당으로 만들어서 저장
	list<UiObject*> uis;      //ui들 동적할당으로 만들어서 저장

	Sprite tree;
	Sprite Timer;
	Text pushEnter;
	Text GameOver;
	Text TimeOut;

public:
	SingleScene(SceneManager& mgr, Texture& clotus); //매니저에서 옷도 같이 주자
	virtual void Init();
	virtual void Draw();
	virtual void Release();
	virtual ~SingleScene();
	virtual void Update();
};