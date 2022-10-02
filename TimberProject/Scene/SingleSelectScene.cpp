#include "SingleSelectScene.h"
#include "MenuScene.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"
#include <string>

//charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player3.png")));
//objs.push_back(charactor[1]);
//charactor[1]->SetOrigin(Origins::TC);
//charactor[1]->SetPosition({ sment.getPosition().x + sment.getLocalBounds().width / 2, 500 });
//charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player4.png")));
//objs.push_back(charactor[2]);
//charactor[2]->SetOrigin(Origins::TL);
//charactor[2]->SetPosition({ dment.getPosition().x + dment.getLocalBounds().width / 2, 500 });
//charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player5.png")));
//objs.push_back(charactor[3]);
//charactor[3]->SetOrigin(Origins::TR);
//charactor[3]->SetPosition({ dment.getPosition().x + dment.getLocalBounds().width / 2, 500 });

SingleSelectScene::SingleSelectScene(SceneManager& mgr)
	:Scene(mgr)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"),
		{ (float)size.x / 2,(float)size.y / 2 });
	background->SetOrigin(Origins::MC);
	objs.push_back(background);

	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player1.png")));
	objs.push_back(charactor[0]);
	charactor[0]->SetOrigin(Origins::MC);
	charactor[0]->SetPosition({ (float)size.x / 2, (float)size.y / 2 });
}

void SingleSelectScene::Init()
{
}

void SingleSelectScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
	window.draw(sment);
	window.draw(dment);
}

void SingleSelectScene::Release()
{
	for (auto it : objs)
	{
		delete it;
	}
	objs.clear();
}

SingleSelectScene::~SingleSelectScene()
{
	Release();
}

void SingleSelectScene::Update(float dt)
{
	if (!InputMgr::GetKey(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	{
		ChangeClothes(SingleMoves::Right);
	}

	if (!InputMgr::GetKey(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		ChangeClothes(SingleMoves::Left);
	}
}

void SingleSelectScene::ChangeClothes(SingleMoves move)
{
}
