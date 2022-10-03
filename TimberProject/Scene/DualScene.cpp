#include "DualScene.h"
#include "SceneManager.h"
#include "../Object/ActiveObject.h"
#include "../ResourceManager.h"
#include "../Object/LogsPool.h"
#include "../InputMgr.h"


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
	
	float tree_size[2] = {0.3f, 0.7f};
	for (int n = 0; n < 2; n++)
	{
		trees.push_back(new SpriteObject(texTree));
		trees[n]->SetScale({ 0.6f ,1.f });
		trees[n]->SetPosition({ (float)size.x * tree_size[n], trees[n]->GetSize().y});
		trees[n]->SetOrigin(Origins::BC);
		objs.push_back(trees[n]);
		branches.push_back(vector<Branch*>(6));
		branchsArr.push_back(vector<Vector2f>(6));
	}

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
	for (int n = 0; n < 2; n++)
	{
		players.push_back(new Player(ResourceManager::GetInstance()->GetTexture("graphics/player1.png"), branches[n], branchCurrent[n], isPuase, n == 0));
		players[n]->SetTreeCenter(trees[n]->GetPosition());
		objs.push_back(players[n]);
	}

	auto bee = new ActiveObject(*ResourceManager::GetInstance()->GetTexture("graphics/bee.png"));
	bee->Set({ 200,400 }, { 500,1000 }, { 2000,0 }, { -100,0 });

	for (auto go : objs)
	{
		go->Init();
	}

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

	for (int n = 0; n < 2; n++)
	{
		nowScore.push_back(0);
		time.push_back(duration);
		timerBar.push_back(RectangleShape({ 400, 50 }));
		timerBar[n].setFillColor(Color::Red);
		timerBar[n].setPosition({ trees[n]->GetPosition().x - 200, trees[n]->GetPosition().y + 20 });
		uis.push_back(txtScore[n]);
	}

	uis.push_back(txtMessage);
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
	for (int n = 0; n < 2; n++)
	{
		nowScore[n] = 0;
		txtScore[n]->SetString("Score: " + to_string(nowScore[n]));
		Sides pos = players[n]->GetSide();
		pos = pos == Sides::Left ? Sides::Right : Sides::Left;
		branches[n][branchCurrent[n]]->SetSide(pos);
	}

	LogsPool::GetInstance()->Init(0.6f);
}

void DualScene::Set(vector<Texture*> cloths)
{
	players[0]->Set(cloths[0]);
	players[1]->Set(cloths[1]);

}
void DualScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}

	LogsPool::GetInstance()->Draw(window);
	txtScore[0]->Draw(window);
	txtScore[1]->Draw(window);
	txtScore[1]->SetOrigin(Origins::TR);
	if (isMentShow)
		txtMessage->Draw(window);
	window.draw(timerBar[0]);
	window.draw(timerBar[1]);
}

void DualScene::Release()
{
}

DualScene::~DualScene()
{
}
void DualScene::UpdateBranch(int pIdx)
{
	branchCurrent[pIdx] = (branchCurrent[pIdx] + 1) % branches[pIdx].size();

	for (int i = 0; i < branches[pIdx].size(); ++i)
	{
		int index = (branchCurrent[pIdx] + i) % branches[pIdx].size();
		branches[pIdx][index]->SetPosition(branchsArr[pIdx][i]);
		if (i == branches[pIdx].size() - 1)
		{
			branches[pIdx][index]->SetSide((Sides)Utils::Range(0, 2));
		}
	}
}

void DualScene::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		mgr.MoveScene(SceneTypes::DUALSELECT);
		return;
	}
	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		if (isGameOver)
		{
			Init();
			txtMessage->SetString("Push Enter");
			isGameOver = false;
			isPuase = true;
		}
		else
		{
			isPuase = !isPuase;
			isMentShow = isPuase;
		}
	}

	dt = isPuase ? 0.f : dt;
	dt = isGameOver ? 0.f : dt;

	if (!isPuase && !isGameOver)
	{
		for (int i = 0; i < 2; i++)
		{
			auto keys = players[i]->GetKeys();

			if (InputMgr::GetKeyDown(keys[0]) && !InputMgr::GetKey(keys[1]) ||
				(InputMgr::GetKeyDown(keys[1]) && !InputMgr::GetKey(keys[0])))
			{
				UpdateBranch(i);
				if (players[i]->Chop(InputMgr::GetKeyDown(keys[0]) ? Sides::Left : Sides::Right))
				{
					AddScore(i);
					time[i] += 0.2f;
					time[i] = min(time[i], 4.f);
					LogsPool::GetInstance()->ShowLogEffect(players[i]->GetSide(), trees[i]->GetPosition());
				}
				else
				{
					isGameOver = true;
					isMentShow = true;
					txtMessage->SetString("Game Over");
				}
			}
			if (time[i] < 0.f)
			{
				if (!isPuase)
				{
					//timeOutSound.play();
				}
				time[i] = 0.f;
				isGameOver = true;
				isMentShow = true;
				isPuase = true;
				txtMessage->SetString("TimeOver");
			}

			time[i] -= dt;
			float normTime = time[i] / duration;
			float timerSizeX = 400 * normTime;
			timerBar[i].setSize({ timerSizeX,  timerBar[i].getSize().y });
			LogsPool::GetInstance()->Update(dt);
		}
		}

	if (!isPuase && !isGameOver)
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
}
void DualScene::AddScore(int i)
{
	nowScore[i] += players[i]->GetScore();
	txtScore[i]->SetString("Score: " + to_string(nowScore[i]));
}
