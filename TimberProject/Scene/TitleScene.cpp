#include "TitleScene.h"
#include "SceneManager.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include <SFML/Audio.hpp>

TitleScene::TitleScene(SceneManager& mgr) // 매번 생성이 아니라 생성해놓고 재활용할 것이기 때문에 빼야할 것이 있고, 넣어야 할 것이 있다. 그게 뭘까?
	: Scene(mgr)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"));
	objs.push_back(background);

	ment = new UiObject("Press Enter To Start!", *ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"), 75, Color::White);
	uis.push_back(ment);

	//리소스매니저::Get인스턴스()->Get폰트("경로");
	//배경생성

	bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Hennesis.wav"));
	//브금 가져오고
	// bgm.setBuffer(""); // 수정
}

void TitleScene::Init()
{

	ment->SetOrigin(Origins::MC);
	ment->SetPosition(Vector2f{(float)1920/2, (float)1080/2});

	
	bgm.play();
	// 게임씬이 바뀌고 그러면서 게이지바나 캐릭터의 위치들을 초기화해주는게 Init이다.
	// 텍스트 위치 맞춰주고


	// 브금 틀어주기
	//bgm.play();
}

void TitleScene::Draw(RenderWindow& window)
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

void TitleScene::Release()
{
	//objs와 uis에 있는거 비우기
}

TitleScene::~TitleScene()
{
	Release();
}

void TitleScene::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		bgm.stop();
		exit(-1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		mgr.MoveScene(SceneTypes::MENU);
		bgm.stop();
	}
}