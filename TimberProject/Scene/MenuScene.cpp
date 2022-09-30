#include "MenuScene.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"

MenuScene::MenuScene(SceneManager& mgr)
	:Scene(mgr), nowSelect(Select::S_SINGLE)
{
	background.getTexture();
	selectsoundbuffer.loadFromFile("sound/select/");
	selectsound.setBuffer(selectsoundbuffer);
	
	ment.setString("Single Mode");
	Utils::SetOrigin(ment, Origins::TL);

	
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

void MenuScene::Draw()
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
	for (auto it : objs)
	{
		delete it;
	}
	objs.clear();
	for (auto it : uis)
	{
		delete it;
	}
	uis.clear();
}

MenuScene::~MenuScene()
{
	Release();
}

void MenuScene::Update()
{
	if (!InputMgr::GetKeyDown(Keyboard::Up) && InputMgr::GetKeyDown(Keyboard::Down))
	{
		MoveSelect(Moves::Down);
	}

	if (!InputMgr::GetKeyDown(Keyboard::Down) && InputMgr::GetKeyDown(Keyboard::Up))
	{
		MoveSelect(Moves::Up);
	}

	if (!InputMgr::GetKeyDown(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		ChangeClothes(Moves::Left);
	}

	if (!InputMgr::GetKeyDown(Keyboard::Left) &&	InputMgr::GetKeyDown(Keyboard::Right))
	{
		ChangeClothes(Moves::Right);
	}
	//특정상황에서 키입력 받으면 Select 체크하는거 위치 옮기기(MoveSelect 호출)
	//특정상황에서 키입력 받으면 ChangeClothes 호출
}

void MenuScene::MoveSelect(Moves move)
{
	selectsound.play();

	select.move(0.f, 0.f); // *표시 이동 (X좌표 고정,Y좌표 +-이동)
}

void MenuScene::ChangeClothes(Moves move)
{
	selectsound.play();

	select.move(0.f, 0.f); // *표시 이동 (X좌표 +-이동,Y좌표 고정)
}
