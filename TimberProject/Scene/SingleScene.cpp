#include "SingleScene.h"
#include "SceneManager.h"
#include "../Object/ActiveObject.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include <string>

SingleScene::SingleScene(SceneManager& mgr, Texture& cloth)
	:Scene(mgr), branchCurrent(0), player(cloth, branches, branchCurrent), nowScore(0),
	duration(4), time(4), isPuase(true), isGameOver(false),isMentShow(true), branches(6), branchsArr(branches.size())
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"),
		{ (float)size.x / 2,(float)size.y / 2 });
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
	tree = new SpriteObject(texTree);
	tree->SetPosition({ (float)size.x / 2, tree->GetSize().y});
	tree->SetOrigin(Origins::BC);
	objs.push_back(tree);

	auto bee = new ActiveObject(*ResourceManager::GetInstance()->GetTexture("graphics/bee.png"));
	bee->Set({ 200,400 }, { 500,1000 }, { 2000,0 }, { -100,0 });

	for (auto go : objs)
	{
		go->Init();
	}
	for (int i = 0; i < branches.size(); ++i)
	{
		branches[i] = new Branch(*ResourceManager::GetInstance()->GetTexture("graphics/branch.png"), *tree);
		branches[i]->SetSide((Sides)Utils::Range(0, 2));
		objs.push_back(branches[i]);
	}

	float x = tree->GetPosition().x;
	float y = 800;
	float offset = branches[0]->GetSize().y;
	offset += 100;
	for (int i = 0; i < branches.size(); ++i)
	{
		branchsArr[i] = Vector2f(x, y);
		y -= offset;
		branches[i]->SetSide((Sides)Utils::Range(0, 2));
		branches[i]->SetPosition(branchsArr[i]);
	}
	Sides playerPos = player.GetSide();
	playerPos = playerPos == Sides::Left ? Sides::Right : Sides::Left;
	branches[branchCurrent]->SetSide(playerPos);
	player.Set(tree->GetPosition());

	txtMessage = new UiObject("PushEnter",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"),
		75, Color::White, { (float)size.x / 2 , (float)size.y / 2 });
	txtMessage->SetOrigin(Origins::MC);

	txtScore = new UiObject("Score : 0",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"),
		90, Color::Red, { 10,10 });
	txtScore->SetOrigin(Origins::TL);

	Vector2f timerBarSize(400, 80);
	timerBar.setSize(timerBarSize);
	timerBar.setFillColor(Color::Red);
	timerBar.setPosition(size.x * 0.5f - timerBarSize.x * 0.5f, size.y - 100);

	objs.push_back(&player);
	bee->Init();
	objs.push_back(bee);
	uis.push_back(txtMessage);
	uis.push_back(txtScore);
}

void SingleScene::Init()
{
	isPuase = true;
	isGameOver = false;
	time = duration;
	float x = branches[0]->GetPosition().x;
	float y = 800;
	float offset = branches[0]->GetSize().y;
	offset += 100;

	for (auto obj : objs)
	{
		obj->Init();
	}
	Sides playerPos = player.GetSide();
	playerPos = playerPos == Sides::Left ? Sides::Right : Sides::Left;
	branches[branchCurrent]->SetSide(playerPos);
	nowScore = 0;
	txtScore->SetString("Score: " + to_string(nowScore));
}

void SingleScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
	txtScore->Draw(window);
	if (isMentShow)
		txtMessage->Draw(window);
	window.draw(timerBar);
}

void SingleScene::Release()
{
}

SingleScene::~SingleScene()
{
}

void SingleScene::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		if (isGameOver)
		{
			Init();
			txtMessage->SetString("Push Enter");
			isGameOver = false;
			isPuase = true;
			player.SetChopShow(false);
		}
		else
		{
			isPuase = !isPuase;
			isMentShow = isPuase;
			player.SetChopShow(!isPuase);
		}
	}

	dt = isPuase ? 0.f : dt;
	dt = isGameOver ? 0.f : dt;
	if (!isPuase && !isGameOver)
	{
		if (InputMgr::GetKeyDown(Keyboard::Left) && !InputMgr::GetKey(Keyboard::Right) || 
			(InputMgr::GetKeyDown(Keyboard::Right) && !InputMgr::GetKey(Keyboard::Left)))
		{
			UpdateBranch();
			if (player.Chop(InputMgr::GetKeyDown(Keyboard::Left) ? Sides::Left : Sides::Right))
			{
				AddScore();
				time += 0.2f;
				time = min(time, 4.f);
			}
			else
			{
				isGameOver = true;
				isMentShow = true;
				txtMessage->SetString("Game Over");
			}
		}
		if (time < 0.f)
		{
			if (!isPuase)
			{
				timeOutSound.play();
			}
			time = 0.f;
			isGameOver = true;
			isMentShow = true;
			player.SetChopShow(false);
			txtMessage->SetString("TimeOver");
		}

		time -= dt;
		float normTime = time / duration;
		float timerSizeX = 400 * normTime;
		timerBar.setSize({ timerSizeX,  timerBar.getSize().y });
		//timerBar.setPosition(size.x * 0.5f - timerSizeX * 0.5f, size.y - 100);
	}
	for (auto obj : objs)
	{
		obj->Update(dt);
	}
	player.Update(dt);
	for (auto ui : uis)
	{
		ui->Update(dt);
	}
}

void SingleScene::UpdateBranch()
{
	branchCurrent = (branchCurrent + 1) % branches.size();

	for (int i = 0; i < branches.size(); ++i)
	{
		int index = (branchCurrent + i) % branches.size();
		branches[index]->SetPosition(branchsArr[i]);
		if (i == branches.size() - 1)
		{
			branches[index]->SetSide((Sides)Utils::Range(0, 2));
		}
	}
}
void SingleScene::AddScore()
{
	nowScore += player.GetScore();
	txtScore->SetString("Score: " + to_string(nowScore));
}
