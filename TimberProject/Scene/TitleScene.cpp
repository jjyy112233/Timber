#include "TitleScene.h"
#include "SceneManager.h"

TitleScene::TitleScene(SceneManager& mgr)
	: Scene(mgr)
{
	//배경 생성, 텍스트 생성
	//vector에 넣어주고
	//브금 가져오고
	//Init()
}

void TitleScene::Init()
{
	//텍스트 위치 맞춰주고
	//브금 틀어주기
}

void TitleScene::Draw()
{
	//for (auto obj : objs)
	//{
	//	obj->Draw(window);
	//}
}

void TitleScene::Release()
{
	//objs와 uis에 있는거 비우기
}

TitleScene::~TitleScene()
{
	//Release();
}

void TitleScene::Update()
{
	//GetKeyDown으로 눌리면
	//mgr.MoveScene(SceneTypes::MENU);
}
