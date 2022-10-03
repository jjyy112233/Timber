#include "TitleScene.h"
#include "SceneManager.h"
#include "SingleSelectScene.h"
#include "MenuScene.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"
#include <string>

SingleSelectScene::SingleSelectScene(SceneManager& mgr)
	:Scene(mgr)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"),
		{ (float)size.x / 2,(float)size.y / 2 });
	background->SetOrigin(Origins::MC);
	objs.push_back(background);

	p = 0;

	selectSound.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Select.wav"));

	select = new UiObject("SELECT A CHARACTOR WHITH THE DIRECTION KEY",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"), 75, Color::White, { 1920 /2, 1080 / 2 });
	select->SetOrigin(Origins::MC);
	uis.push_back(select);
}

void SingleSelectScene::Init()
{
	for (int i = 0; i < 5; ++i)
	{
		charactor.push_back(ResourceManager::GetInstance()->GetTexture(
			"graphics/player" + to_string(i + 1) + ".png"));
	}
	player = new SpriteObject(*charactor[0], { (float)size.x / 2, (float)size.y / 2 });
	player->SetScale({ 2, 2 });	

	player->SetOrigin(Origins::MC);	

	objs.push_back(player);

	bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Cuningcity.wav"));
	bgm.play();
}

void SingleSelectScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
	window.draw(sment);
	window.draw(dment);
	for (auto ui : objs)
	{
		ui->Draw(window);
	}
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
		selectSound.play();
	}
	if (!InputMgr::GetKey(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		ChangeClothes(SingleMoves::Left);
		selectSound.play();
	}

	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		mgr.MoveScene(SceneTypes::SINGLE);
		selectSound.play();
		bgm.stop();
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		mgr.MoveScene(SceneTypes::MENU);
		selectSound.play();
		bgm.stop();
	}
}

void SingleSelectScene::ChangeClothes(SingleMoves move)
{
	if (InputMgr::GetKeyDown(Keyboard::Right))
	{
		if (p == 4) return;
		player->SetTexture(*charactor[++p]);
	}
	if (InputMgr::GetKeyDown(Keyboard::Left))
	{
		if (p == 0) return;
		player->SetTexture(*charactor[--p]);
	}
}
