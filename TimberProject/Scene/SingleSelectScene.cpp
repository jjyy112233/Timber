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

	select = new TextObject("SELECT A CHARACTOR WHITH THE DIRECTION KEY",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"), 75, Color::White, { 1920.f / 2.f, 1080.f * 0.33f });
	select->SetOrigin(Origins::MC);
	txts.push_back(select);
	for (int i = 0; i < 5; ++i)
	{
		charactor.push_back(ResourceManager::GetInstance()->GetTexture(
			"graphics/player" + to_string(i + 1) + ".png"));
	}
	player = new SpriteObject(*charactor[0], { (float)size.x / 2, (float)size.y / 2 });
	player->SetScale({ 2, 2 });	
	player->SetOrigin(Origins::MC);	

	objs.push_back(player);
}

void SingleSelectScene::Init()
{

	bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Cuningcity.wav"));
	bgm.play();
	bgm.setLoop(true);
}

void SingleSelectScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
	for (auto ui : txts)
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
		selectSound.play();
		bgm.stop();
		mgr.MoveScene(SceneTypes::SINGLE, { charactor[p] });
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		selectSound.play();
		bgm.stop();
		mgr.MoveScene(SceneTypes::MENU);
	}
}

void SingleSelectScene::ChangeClothes(SingleMoves move)
{
	if (InputMgr::GetKeyDown(Keyboard::Right))
	{
		if (p == 4) return;
		player->SetTexture(*charactor[++p]);
		player->SetOrigin(Origins::MC);
	}
	if (InputMgr::GetKeyDown(Keyboard::Left))
	{
		if (p == 0) return;

		player->SetTexture(*charactor[--p]);
		player->SetOrigin(Origins::MC);
	}
}
