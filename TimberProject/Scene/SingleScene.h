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
	vector<Branch*> branches; //�������� ������ƮǮ��, ������ ���� ������ �ְ� ����
	int branchCurrent;
	vector<Vector2f> branchsArr;

	SpriteObject* tree;
	RectangleShape timerBar;
	Text txtMessage;
	Text texScore;

	int duration;
	int time;
	bool isPuase;
	bool isGameOver;

public:
	SingleScene(SceneManager& mgr, Texture& clotus); //�Ŵ������� �ʵ� ���� ����
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~SingleScene();
	virtual void Update(float dt);
	void UpdateBranch();
	void AddScore();
};