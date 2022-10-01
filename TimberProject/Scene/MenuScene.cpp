#include "MenuScene.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"
#include <string>

MenuScene::MenuScene(SceneManager& mgr)
	:Scene(mgr), nowSelect(Select::S_SINGLE)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"),
		{ (float)size.x / 2,(float)size.y / 2 });
	background->SetOrigin(Origins::MC);
	objs.push_back(background);

	//bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Elinia.wav"));
	//bgm.play();

	sment.setString("Single");
	sment.setPosition(300, 200);
	sment.setCharacterSize(150);
	Utils::SetOrigin(sment,Origins::TC);
	sment.setFont(*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"));
	dment.setString("Dual");
	dment.setPosition(1260, 200);
	dment.setCharacterSize(150);
	Utils::SetOrigin(dment, Origins::ML);
	dment.setFont(*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"));

	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/Arrow.png")));
	objs.push_back(charactor[0]);
	charactor[0]->SetOrigin(Origins::MR);
	charactor[0]->SetPosition(sment.getPosition());
	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player3.png")));
	objs.push_back(charactor[1]);
	charactor[1]->SetOrigin(Origins::TC);
	charactor[1]->SetPosition({sment.getPosition().x + sment.getLocalBounds().width / 2, 500});
	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player4.png")));
	objs.push_back(charactor[2]);
	charactor[2]->SetOrigin(Origins::TL);
	charactor[2]->SetPosition({ dment.getPosition().x + dment.getLocalBounds().width / 2, 500 });
	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player5.png")));
	objs.push_back(charactor[3]);
	charactor[3]->SetOrigin(Origins::TR);
	charactor[3]->SetPosition({ dment.getPosition().x + dment.getLocalBounds().width / 2, 500 });


	
	
	//배경 가져오기 .
	//bgm 가져오기 .
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
	window.draw(sment);
	window.draw(dment);
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

void MenuScene::Update(float dt)
{

	if (!InputMgr::GetKeyDown(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	{
		MoveSelect(Moves::Right);
	}

	if (!InputMgr::GetKeyDown(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		MoveSelect(Moves::Left);
	}
	//if (Select::S_SINGLE == nowSelect)
	//{
	//	if (!InputMgr::GetKeyDown(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	//	{
	//		ChangeClothes(Moves::Right);
	//	}

	//	if (!InputMgr::GetKeyDown(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	//	{
	//		ChangeClothes(Moves::Left);
	//	}
	//}
	//if (Select::S_DUAL == nowSelect)
	//{
	//	if (!InputMgr::GetKeyDown(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	//	{
	//		ChangeClothes(Moves::Right);
	//	}

	//	if (!InputMgr::GetKeyDown(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	//	{
	//		ChangeClothes(Moves::Left);
	//	}
	//}
	//특정상황에서 키입력 받으면 Select 체크하는거 위치 옮기기(MoveSelect 호출)
	//특정상황에서 키입력 받으면 ChangeClothes 호출
}

void MenuScene::MoveSelect(Moves move)
{
	selectsound.play();
	charactor[0]->SetOrigin(Origins::MR);
	charactor[0]->SetPosition(dment.getPosition());

}

void MenuScene::ChangeClothes(Moves move)
{
	selectsound.play();

	select.move(0.f, 0.f); 
}
