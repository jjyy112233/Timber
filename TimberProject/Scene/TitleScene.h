#pragma once
#include "Scene.h"

class SceneManager;
class TitleScene : public Scene //
{
protected:
	SpriteObject* background;
	Sound bgm;
	UiObject* ment;


public:
	TitleScene(SceneManager& mgr);
	virtual void Init();
	virtual void Set(vector<string> cloths) {};
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~TitleScene();
	virtual void Update(float dt);
};


//Ÿ��Ʋ
//����̹���, �������, ��Ʈ(�����̽��ٸ� �����ּ���.)
//�����̽��ٸ� ������ �޴� ����, escŰ�� ������ ���α׷� ����, ����Ű ���Ʒ��� �޴� �̵� (�ֿ� ���)
