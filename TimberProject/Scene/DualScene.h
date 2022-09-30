#pragma once
#include "Scene.h"
#include "../Object/Player.h"

class SceneManager;
class DualScene : public Scene
{
	Sprite background;
	Sound bgm;
	Text ment;

	vector<SpriteObject*> trees;//트리 만들때 플레이어, 브런치 에게 트리 위치 주기
	vector<vector<Branch*>*> branchs; //가지들은 오브젝트풀로, 가지가 사운드 가지고 있게 하자
	vector<Player> players;	//플렝이어 두개

	vector<SpriteObject*> timer; //타이머 두개
	UiObject* pushEnter;//두개
	UiObject* gameOver;	//두개
	UiObject* timeOut;	//두개

public:
	DualScene(SceneManager& mgr, Texture& cloths1, Texture& cloths2); //매니저에서 옷도 같이 주자
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~DualScene();
	virtual void Update();
};

