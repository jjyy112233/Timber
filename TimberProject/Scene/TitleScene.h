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
	virtual void Draw();
	virtual void Release();
	virtual ~TitleScene();
	virtual void Update();
};


//Ÿ��Ʋ
//����̹���, �������, ��Ʈ(�����̽��ٸ� �����ּ���.)
//�����̽��ٸ� ������ �޴� ����, escŰ�� ������ ���α׷� ����, ����Ű ���Ʒ��� �޴� �̵� (�ֿ� ���)
