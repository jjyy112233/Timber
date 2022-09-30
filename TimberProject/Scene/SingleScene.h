#pragma once
#include "Scene.h"
#include "../Object/Player.h"

class SceneManager;
class SingleScene : public Scene
{
protected:
	SpriteObject* background;
	Sound bgm;
	Sound timeOutSound;
	Text ment;

	Player player;
	vector<Branch*> branches; //가지들은 오브젝트풀로, 가지가 사운드 가지고 있게 하자
	int branchCurrent;
	vector<Vector2f> branchsArr;

	SpriteObject* tree;
	RectangleShape timerBar;
	UiObject* txtMessage;
	UiObject* txtScore;

	int duration;
	int nowScore;
	float time;
	bool isPuase;
	bool isGameOver;
	bool isMentShow;

public:
	SingleScene(SceneManager& mgr, Texture& clotus); //매니저에서 옷도 같이 주자
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~SingleScene();
	virtual void Update(float dt);
	void UpdateBranch();
	void AddScore();
};