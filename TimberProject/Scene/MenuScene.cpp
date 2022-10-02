#include "MenuScene.h"
#include "SceneManager.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"
#include <string>

MenuScene::MenuScene(SceneManager& mgr)
	:Scene(mgr), nowSelect(Select::S_SINGLE)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"),
		{ (float)size.x / 2,(float)size.y / 2 });
	background->SetOrigin(Origins::MC);
	objs.push_back(background);

	sment = new UiObject("Single", *ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"), 150, Color::White, { 300, 200 });
	sment->SetOrigin(Origins::ML);
	uis.push_back(sment);
	dment = new UiObject("Dual", *ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"), 150, Color::White, { 1260, 200 });
	dment->SetOrigin(Origins::ML);
	uis.push_back(dment);

	arrow = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/Arrow.png"));
	arrow->SetOrigin(Origins::MR);
	arrow->SetPosition({ sment->GetPosition().x , sment->GetPosition().y + 20 });
	objs.push_back(arrow);
	dment->SetFillColor(Color(0, 0, 0, 200));
	
	select = new UiObject("PUSH ARROW KEY! NEXT SCENE IS SPACEBAR!",
		*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"), 75, Color::White, { 1920/2, 1080/2 });
	select->SetOrigin(Origins::MC);
	uis.push_back(select);



	//��� �������� .
	//bgm �������� .
	//ment �ۼ�
	//charactor�ΰ� ����
	//cloth �ΰ� push_back 0���� �ʱ�ȭ
	// ��� objs�� �־��ְ� ĳ���� �־��ְ�
	//�̱۸��, ����� ui ���� uis�� �־��ֱ� 
	//
}

void MenuScene::Init()
{
	nowSelect = Select::S_SINGLE;
	arrow->SetPosition({ sment->GetPosition().x , sment->GetPosition().y + 20 });
	dment->SetFillColor(Color(0, 0, 0, 200));

	bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Elinia.wav"));
	bgm.play();

	//cselect = false;
	//��� 
	// objs�� uis ���� ��ġ �����ֱ�.
	// select�� ĳ���� �� �����ѰŴ� ������� �������ذ͵� ������ ��������

}

void MenuScene::Draw(RenderWindow& window)
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

void MenuScene::Release()
{
	//objs�� uis ����ֱ�
	for (auto it : objs)
	{
		delete it;
	}
	objs.clear();
	for (auto it : uis)
	{
		delete it;
	}
	uis.clear();
}

MenuScene::~MenuScene()
{
	Release();
}

void MenuScene::Update(float dt)
{
	if (!InputMgr::GetKey(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	{
		nowSelect = Select::S_DUAL;
		MoveSelect(Moves::Right);
	}

	if (!InputMgr::GetKey(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		nowSelect = Select::S_SINGLE;
		MoveSelect(Moves::Left);
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		mgr.MoveScene(SceneTypes::TITLE);
		bgm.stop();
	}

	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		mgr.MoveScene(nowSelect == Select::S_DUAL ? SceneTypes::DUALSELECT : SceneTypes::SINGLESELECT);
		bgm.stop();
	}
	//Ư����Ȳ���� Ű�Է� ������ Select üũ�ϴ°� ��ġ �ű��(MoveSelect ȣ��)
	//Ư����Ȳ���� Ű�Է� ������ ChangeClothes ȣ��
}

void MenuScene::MoveSelect(Moves move)
{
	if (move == Moves::Right)
	{
		sment->SetFillColor(Color(0, 0, 0, 200));
		dment->SetFillColor(Color::White);
		arrow->SetPosition({ dment->GetPosition().x , dment->GetPosition().y + 20 });
	}
	if(move == Moves::Left)
	{
		sment->SetFillColor(Color::White);
		dment->SetFillColor(Color(0, 0, 0, 200));
		arrow->SetPosition({ sment->GetPosition().x , sment->GetPosition().y + 20 });
	}
}


