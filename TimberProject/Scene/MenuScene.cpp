#include "MenuScene.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"
#include <string>

MenuScene::MenuScene(SceneManager& mgr)
	:Scene(mgr), nowSelect(Select::S_SINGLE), SelectDown(false)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"),
		{ (float)size.x / 2,(float)size.y / 2 });
	background->SetOrigin(Origins::MC);
	objs.push_back(background);

	//bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Elinia.wav"));
	//bgm.play();

	sment.setString("Single");
	sment.setPosition(300, 200);
	sment.setCharacterSize(150);
	sment.setFont(*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"));
	Utils::SetOrigin(sment,Origins::BL);
	dment.setString("Dual");
	dment.setPosition(1260, 200);
	dment.setCharacterSize(150);
	Utils::SetOrigin(dment, Origins::ML);
	dment.setFont(*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"));
	Utils::SetOrigin(dment, Origins::BL);

	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/Arrow.png")));
	objs.push_back(charactor[0]);
	charactor[0]->SetOrigin(Origins::MR);
	charactor[0]->SetPosition(sment.getPosition());
	
	sment.setFillColor(Color::White);
	dment.setFillColor(Color(125, 125, 125, 200));
	
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
	SelectDown = false;
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
	window.draw(sment);
	window.draw(dment);
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
		MoveSelect(Moves::Right);
	}

	if (!InputMgr::GetKey(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		MoveSelect(Moves::Left);
	}
	//Ư����Ȳ���� Ű�Է� ������ Select üũ�ϴ°� ��ġ �ű��(MoveSelect ȣ��)
	//Ư����Ȳ���� Ű�Է� ������ ChangeClothes ȣ��
}

void MenuScene::MoveSelect(Moves move)
{
	selectsound.play();
	charactor[0]->SetOrigin(Origins::MR);
	if (move == Moves::Right)
	{
		charactor[0]->SetPosition(dment.getPosition());
		sment.setFillColor(Color(125, 125, 125, 200));
		dment.setFillColor(Color::White);
	}
	if(move == Moves::Left)
	{
		charactor[0]->SetPosition(sment.getPosition());
		sment.setFillColor(Color::White);
		dment.setFillColor(Color(125, 125, 125, 200));
	}
}


