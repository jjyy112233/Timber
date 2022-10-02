#include "DualScene.h"
#include "SceneManager.h"
#include "../Object/ActiveObject.h"
#include "../ResourceManager.h"
#include "../Object/LogsPool.h"

DualScene::DualScene(SceneManager& mgr)
	:Scene(mgr), duration(4), isPuase(true), isGameOver(false), isMentShow(true)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"), { (float)size.x / 2, (float)size.y / 2 });
	background->SetOrigin(Origins::MC);
	objs.push_back(background);

	vector<float> startVector = { 2000, -300 };
	vector<float> endVector = { -300, 2000 };
	for (int i = 0; i < 3; ++i)
	{
		auto cloud = new ActiveObject(*ResourceManager::GetInstance()->GetTexture("graphics/cloud.png"));
		auto index = Utils::Range(0, 2);
		cloud->Set(
			{ 200,400 }, { 100,400 },
			{ startVector[index], 0 }, { endVector[index], 0 });
		objs.push_back(cloud);
	}

	Texture& texTree = *ResourceManager::GetInstance()->GetTexture("graphics/tree.png");
	trees.push_back(new SpriteObject(texTree));
	trees.push_back(new SpriteObject(texTree));
	trees[0]->SetScale({ 0.6f ,1.f });
	trees[1]->SetScale({ 0.6f ,1.f });
	trees[0]->SetPosition({ (float)size.x *0.3f, trees[0]->GetSize().y });
	trees[1]->SetPosition({ (float)size.x *0.7f, trees[1]->GetSize().y });
	trees[0]->SetOrigin(Origins::BC);
	trees[1]->SetOrigin(Origins::BC);
	objs.push_back(trees[0]);
	objs.push_back(trees[1]);



	branches.push_back(vector<Branch*>(6));
	branchsArr.push_back(vector<Vector2f>(6));
	branches.push_back(vector<Branch*>(6));
	branchsArr.push_back(vector<Vector2f>(6));


	for (int n = 0; n < 2; n++)
	{
		float x = trees[n]->GetPosition().x;
		float y = 800;
		float offset = ResourceManager::GetInstance()->GetTexture("graphics/branch.png")->getSize().y;
		offset += 100;
		for (int i = 0; i < branches[n].size(); ++i)
		{
			branchsArr[n][i] = Vector2f(x, y);
			y -= offset;
			branches[n][i] = new Branch(*ResourceManager::GetInstance()->GetTexture("graphics/branch.png"), *trees[n]);
			branches[n][i]->SetSide((Sides)Utils::Range(0, 2));
			branches[n][i]->SetScale({ 0.6f, 0.6f });
			branches[n][i]->SetPosition(branchsArr[n][i]);
			objs.push_back(branches[n][i]);
		}
	}
	branchCurrent.push_back(0);
	branchCurrent.push_back(0);
	players.push_back(new Player(*ResourceManager::GetInstance()->GetTexture("graphics/player1.png"), branches[0], branchCurrent[0], isPuase));
	players.push_back(new Player(*ResourceManager::GetInstance()->GetTexture("graphics/player1.png"), branches[1], branchCurrent[1], isPuase));
	players[0]->SetTreeCenter(trees[0]->GetPosition());
	players[1]->SetTreeCenter(trees[1]->GetPosition());
	objs.push_back(players[0]);
	objs.push_back(players[1]);

	auto bee = new ActiveObject(*ResourceManager::GetInstance()->GetTexture("graphics/bee.png"));
	bee->Set({ 200,400 }, { 500,1000 }, { 2000,0 }, { -100,0 });

	for (auto go : objs)
	{
		go->Init();
	}
	nowScore.push_back(0);
	nowScore.push_back(0);
	time.push_back(duration);
	time.push_back(duration);

	txtMessage = new UiObject("PushEnter",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"),
		75, Color::White, { (float)size.x / 2 , (float)size.y / 2 });
	txtMessage->SetOrigin(Origins::MC);

	txtScore.push_back(new UiObject("Score : 0",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"),
		90, Color::Red, { 10,10 }));

	txtScore.push_back(new UiObject("Score : 0",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"),
		90, Color::Red, {(float)size.x-30,10 }));
	txtScore[0]->SetOrigin(Origins::TL);
	txtScore[1]->SetOrigin(Origins::TR);

	uis.push_back(txtMessage);
	uis.push_back(txtScore[0]);
	uis.push_back(txtScore[1]);

}

void DualScene::Init()
{
	isPuase = true;
	isGameOver = false;
	time[0] = duration;
	time[1] = duration;

	for (auto obj : objs)
	{
		obj->Init();
	}
	nowScore[0] = 0;
	nowScore[1] = 0;
	txtScore[0]->SetString("Score: " + to_string(nowScore[0]));
	txtScore[1]->SetString("Score: " + to_string(nowScore[1]));
	LogsPool::GetInstance()->Init();

	Sides pos = players[0]->GetSide();
	pos = pos == Sides::Left ? Sides::Right : Sides::Left;
	branches[0][branchCurrent[0]]->SetSide(pos);
	pos = players[1]->GetSide();
	pos = pos == Sides::Left ? Sides::Right : Sides::Left;
	branches[1][branchCurrent[1]]->SetSide(pos);
}

void DualScene::Set(vector<string> cloths)
{
	//Å×½º¤Ñ
	//players[0]->Set(clock[0]);
	//players[1]->Set(clock[1]);

}
void DualScene::Draw(RenderWindow& window)
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

void DualScene::Release()
{
}

DualScene::~DualScene()
{
}

void DualScene::Update(float dt)
{
	for (auto obj : objs)
	{
		obj->Update(dt);
	}
	for (auto ui : uis)
	{
		ui->Update(dt);
	}
}
