#include "SingleScene.h"
#include "SceneManager.h"
#include "../Object/ActiveObject.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "../Object/LogsPool.h"
#include <string>

SingleScene::SingleScene(SceneManager& mgr)
	:Scene(mgr), branchCurrent(0), nowScore(0),
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
	bee->Set({ 100,200 }, { 300,800 }, { 2000,0 }, { -100,0 });

	for (auto go : objs)
	{
		go->Init();
	}
	float x = tree->GetPosition().x;
	float y = 800;
	float offset = (float)ResourceManager::GetInstance()->GetTexture("graphics/branch.png")->getSize().y;
	offset += 100;
	for (int i = 0; i < branches.size(); ++i)
	{
		branchsArr[i] = Vector2f(x, y);
		y -= offset;
		branches[i] = new Branch(*ResourceManager::GetInstance()->GetTexture("graphics/branch.png"), *tree);
		branches[i]->SetSide((Sides)Utils::Range(0, 2));
		branches[i]->SetPosition(branchsArr[i]);
		objs.push_back(branches[i]);
	}

	txtMessage = new TextObject("PushEnter",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"),
		75, Color::White, { (float)size.x / 2 , (float)size.y / 2 });
	txtMessage->SetOrigin(Origins::MC);

	txtScore = new TextObject("Score : 0",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"),
		90, Color::Red, { 10,10 });
	txtScore->SetOrigin(Origins::TL);


	Vector2f timerBarSize(400, 80);
	timerBar.setSize(timerBarSize);
	timerBar.setFillColor(Color::Red);
	timerBar.setPosition((float)size.x * 0.5f - timerBarSize.x * 0.5f, (float)size.y - 100);

	player = new Player(ResourceManager::GetInstance()->GetTexture("graphics/player1.png"), branches, branchCurrent, isPuase);
	player->SetTreeCenter(tree->GetPosition());
	objs.push_back(player);
	bee->Init();
	objs.push_back(bee);
	txts.push_back(txtMessage);
	txts.push_back(txtScore);
	bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/gameSceneBgm.wav"));
	timeOutSound.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/death.wav"));
	bgm.setLoop(true);
	keySound.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Select.wav"));
}

void SingleScene::Init()
{
	isPuase = true;
	isGameOver = false;
	time = duration;

	for (auto obj : objs)
	{
		obj->Init();
	}
	nowScore = 0;
	txtScore->SetString("Score: " + to_string(nowScore));
	LogsPool::GetInstance()->Init();

	Sides pos = player->GetSide();
	pos = pos == Sides::Left ? Sides::Right : Sides::Left;
	branches[branchCurrent]->SetSide(pos);

	if(bgm.getStatus() == Sound::Status::Stopped)
		bgm.play();
}

void SingleScene::Draw(RenderWindow& window)
{
	for (auto obj : objs)
	{
		obj->Draw(window);
	}
	LogsPool::GetInstance()->Draw(window);
	txtScore->Draw(window);
	if (isMentShow)
		txtMessage->Draw(window);
	window.draw(timerBar);
}
void SingleScene::Set(vector<Texture*> cloth)
{
	player->Set(cloth[0]);
}
void SingleScene::Release()
{
}

SingleScene::~SingleScene()
{
}

void SingleScene::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		bgm.stop();
		mgr.MoveScene(SceneTypes::SINGLESELECT);
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
			keySound.play();
		}
		else
		{
			isPuase = !isPuase;
			isMentShow = isPuase;
			keySound.play();
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
			if (player->Chop(InputMgr::GetKeyDown(Keyboard::Left) ? Sides::Left : Sides::Right))
			{
				AddScore();
				time += 0.2f;
				time = min(time, 4.f);
				LogsPool::GetInstance()->ShowLogEffect(player->GetSide(), tree->GetPosition());
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
			isPuase = true;
			txtMessage->SetString("TimeOver");
			timeOutSound.play();
		}

		time -= dt;
		float normTime = time / duration;
		float timerSizeX = 400 * normTime;
		timerBar.setSize({ timerSizeX,  timerBar.getSize().y });
		LogsPool::GetInstance()->Update(dt);
	}
	for (auto obj : objs)
	{
		obj->Update(dt);
	}
	for (auto ui : txts)
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
	nowScore += player->GetScore();
	txtScore->SetString("Score: " + to_string(nowScore));
}
