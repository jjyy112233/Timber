#pragma once
#include "Scene.h"
#include "../Object/Player.h"

class SceneManager;
class DualScene : public Scene
{
	Sprite background;
	Sound bgm;
	Text ment;

	vector<SpriteObject*> trees;//Ʈ�� ���鶧 �÷��̾�, �귱ġ ���� Ʈ�� ��ġ �ֱ�
	vector<vector<Branch*>*> branchs; //�������� ������ƮǮ��, ������ ���� ������ �ְ� ����
	vector<Player> players;	//�÷��̾� �ΰ�

	vector<SpriteObject*> timer; //Ÿ�̸� �ΰ�
	UiObject* pushEnter;//�ΰ�
	UiObject* gameOver;	//�ΰ�
	UiObject* timeOut;	//�ΰ�

public:
	DualScene(SceneManager& mgr, Texture& cloths1, Texture& cloths2); //�Ŵ������� �ʵ� ���� ����
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~DualScene();
	virtual void Update();
};

