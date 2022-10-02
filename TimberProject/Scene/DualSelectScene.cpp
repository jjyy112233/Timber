#include "TitleScene.h"
#include "SceneManager.h"
#include "DualSelectScene.h"
#include "MenuScene.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"
#include <string>

DualSelectScene::DualSelectScene(SceneManager& mgr)
	:Scene(mgr)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"),
		{ (float)size.x / 2,(float)size.y / 2 });
	background->SetOrigin(Origins::MC);
	objs.push_back(background);

	p1 = 0;
	p2 = 0;
}

void DualSelectScene::Init()
{
	for (int i = 0; i< 5; ++i)
	{
		charactor.push_back(ResourceManager::GetInstance()->GetTexture(
			"graphics/player" + to_string(i + 1) + ".png"));
	}
	player1 = new SpriteObject(*charactor[0], { (float)size.x * 0.33f, (float)size.y / 2 });
	player2 = new SpriteObject(*charactor[0], { (float)size.x * 0.66f, (float)size.y / 2 });
	player1->SetScale({ 2, 2 });
	player2->SetScale({ 2, 2 });

	player1->SetOrigin(Origins::MC);
	player2->SetOrigin(Origins::MC);

	objs.push_back(player1);
	objs.push_back(player2);

	bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Perion.wav"));
	bgm.play();
}

void DualSelectScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
	window.draw(sment);
	window.draw(dment);
}

void DualSelectScene::Release()
{
	for (auto it : objs)
	{
		delete it;
	}
	objs.clear();
}

DualSelectScene::~DualSelectScene()
{
	Release();
}

void DualSelectScene::Update(float dt)
{
	if (!InputMgr::GetKey(Keyboard::A) && InputMgr::GetKeyDown(Keyboard::D))
	{
		ChangeClothes(DualMoves::D);
	}
	if (!InputMgr::GetKey(Keyboard::D) && InputMgr::GetKeyDown(Keyboard::A))
	{
		ChangeClothes(DualMoves::A);
	}

	if (!InputMgr::GetKey(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	{
		ChangeClothes(DualMoves::Right);
	}
	if (!InputMgr::GetKey(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		ChangeClothes(DualMoves::Left);
	}

	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		mgr.MoveScene(SceneTypes::DUAL);
		bgm.stop();
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		mgr.MoveScene(SceneTypes::MENU);
		bgm.stop();
	}
}

void DualSelectScene::ChangeClothes(DualMoves move)
{
	if (InputMgr::GetKeyDown(Keyboard::D))
	{
		if (p1 == 4) return;
		player1->SetTexture(*charactor[++p1]);
	}
	if (InputMgr::GetKeyDown(Keyboard::A))
	{
		if (p1 == 0) return;
		player1->SetTexture(*charactor[--p1]);
	}
	if (InputMgr::GetKeyDown(Keyboard::Right))
	{
		if (p2 == 4) return;
		player2->SetTexture(*charactor[++p2]);
	}
	if (InputMgr::GetKeyDown(Keyboard::Left))
	{
		if (p2 == 0) return;
		player2->SetTexture(*charactor[--p2]);
	}
		
}
