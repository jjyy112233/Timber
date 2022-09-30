#pragma once
#include "Scene.h"

class SceneManager;
class TitleScene : public Scene //
{
protected:
	SpriteObject* background;
	Sound bgm;
	UiObject* ment;

	list<SpriteObject*> objs;
	list<UiObject*> uis;

public:
	TitleScene(SceneManager& mgr);
	virtual void Init();
	virtual void Draw();
	virtual void Release();
	virtual ~TitleScene();
	virtual void Update();
};


//타이틀
//배경이미지, 배경음악, 멘트(스페이스바를 눌러주세요.)
//스페이스바를 누르면 메뉴 선택, esc키를 누르면 프로그램 종료, 방향키 위아래로 메뉴 이동 (주요 기능)
