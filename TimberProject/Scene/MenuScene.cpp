#include "MenuScene.h"

MenuScene::MenuScene(SceneManager& mgr)
	:Scene(mgr), nowSelect(Select::S_SINGLE)
{
	//배경 가져오기
	//bgm 가져오기
	//ment 작성
	//charactor두개 생성
	//cloth 두개 push_back 0으로 초기화
	// 배경 objs에 넣어주고 캐릭터 넣어주고
	//싱글모드, 듀얼모드 ui 만들어서 uis에 넣어주기 
	//
}

void MenuScene::Init()
{
	//배경 
	// objs와 uis 전부 위치 맞춰주기.
	// select와 캐릭터 옷 선택한거는 기존대로 유지해준것도 나쁘지 않을지도

}

void MenuScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
	for (auto ui : uis)
	{
		ui->Draw(window);
	}
}

void MenuScene::Release()
{
	//objs와 uis 비워주기
}

MenuScene::~MenuScene()
{
	Release();
}

void MenuScene::Update()
{
	//특정상황에서 키입력 받으면 Select 체크하는거 위치 옮기기(MoveSelect 호출)
	//특정상황에서 키입력 받으면 ChangeClothes 호출
}

void MenuScene::MoveSelect()
{
}

void MenuScene::ChangeClothes()
{
}
