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
	vector<Branch*> branchs; //�������� ������ƮǮ��, ������ ���� ������ �ְ� ����
	
	list<SpriteObject*> objs; //������Ʈ�� �����Ҵ����� ���� ����
	list<UiObject*> uis;      //ui�� �����Ҵ����� ���� ����

	Sprite tree;
	Sprite Timer;
	Text pushEnter;
	Text GameOver;
	Text TimeOut;

public:
	SingleScene(SceneManager& mgr, Texture& clotus); //�Ŵ������� �ʵ� ���� ����
	virtual void Init();
	virtual void Draw();
	virtual void Release();
	virtual ~SingleScene();
	virtual void Update();
};