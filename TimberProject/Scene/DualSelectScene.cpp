#include "TitleScene.h"
#include "SceneManager.h"
#include "DualSelectScene.h"
#include "MenuScene.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"
#include <string>

DualSelectScene::DualSelectScene(SceneManager& mgr)
	:Scene(mgr), select(nullptr), player1(nullptr), player2(nullptr)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"),
		{(float)size.x / 2, (float)size.y / 2 });
	background->SetOrigin(Origins::MC);
	objs.push_back(background);

	p1 = 0;
	p2 = 0;

	selectSound.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Select.wav"));

	for (int i = 0; i < 5; ++i)
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
}

void DualSelectScene::Init()
{

	bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Perion.wav"));
	bgm.play();
	bgm.setLoop(true);

	select = new TextObject("SELECT A CHARACTOR \n WHITH A,W KEY AND DIRECTION KEY",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"), 75, Color::White, { (float)1920 /2.f , (float)1080 * 0.33f });
	select->SetOrigin(Origins::MC);
	txts.push_back(select);
}

void DualSelectScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
	window.draw(sment);
	window.draw(dment);
	for (auto ui : txts)
	{
		ui->Draw(window);
	}
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
		selectSound.play();
	}
	if (!InputMgr::GetKey(Keyboard::D) && InputMgr::GetKeyDown(Keyboard::A))
	{
		ChangeClothes(DualMoves::A);
		selectSound.play();
	}

	if (!InputMgr::GetKey(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	{
		ChangeClothes(DualMoves::Right);
		selectSound.play();
	}
	if (!InputMgr::GetKey(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		ChangeClothes(DualMoves::Left);
		selectSound.play();
	}

	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		mgr.MoveScene(SceneTypes::DUAL, {charactor[p1], charactor[p2]});
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
