#include "MenuScene.h"
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

	//bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Elinia.wav"));
	//bgm.play();

	sment.setString("Single");
	sment.setPosition(300, 200);
	sment.setCharacterSize(150);
	//Utils::SetOrigin(sment,Origins::TC);
	sment.setFont(*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"));
	dment.setString("Dual");
	dment.setPosition(1260, 200);
	dment.setCharacterSize(150);
	//Utils::SetOrigin(dment, Origins::ML);
	dment.setFont(*ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"));

	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/Arrow.png")));
	objs.push_back(charactor[0]);
	charactor[0]->SetOrigin(Origins::MR);
	charactor[0]->SetPosition(sment.getPosition());
	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player3.png")));
	objs.push_back(charactor[1]);
	charactor[1]->SetOrigin(Origins::TC);
	charactor[1]->SetPosition({sment.getPosition().x + sment.getLocalBounds().width / 2, 500});
	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player4.png")));
	objs.push_back(charactor[2]);
	charactor[2]->SetOrigin(Origins::TL);
	charactor[2]->SetPosition({ dment.getPosition().x + dment.getLocalBounds().width / 2, 500 });
	charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player5.png")));
	objs.push_back(charactor[3]);
	charactor[3]->SetOrigin(Origins::TR);
	charactor[3]->SetPosition({ dment.getPosition().x + dment.getLocalBounds().width / 2, 500 });


	
	
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

	if (!InputMgr::GetKeyDown(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	{
		MoveSelect(Moves::Right);
	}

	if (!InputMgr::GetKeyDown(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		MoveSelect(Moves::Left);
	}
	//if (Select::S_SINGLE == nowSelect)
	//{
	//	if (!InputMgr::GetKeyDown(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	//	{
	//		ChangeClothes(Moves::Right);
	//	}

	//	if (!InputMgr::GetKeyDown(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	//	{
	//		ChangeClothes(Moves::Left);
	//	}
	//}
	//if (Select::S_DUAL == nowSelect)
	//{
	//	if (!InputMgr::GetKeyDown(Keyboard::Left) && InputMgr::GetKeyDown(Keyboard::Right))
	//	{
	//		ChangeClothes(Moves::Right);
	//	}

	//	if (!InputMgr::GetKeyDown(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	//	{
	//		ChangeClothes(Moves::Left);
	//	}
	//}
	//Ư����Ȳ���� Ű�Է� ������ Select üũ�ϴ°� ��ġ �ű��(MoveSelect ȣ��)
	//Ư����Ȳ���� Ű�Է� ������ ChangeClothes ȣ��
}

void MenuScene::MoveSelect(Moves move)
{
	selectsound.play();
	charactor[0]->SetOrigin(Origins::MR);
	charactor[0]->SetPosition(dment.getPosition());

}

void MenuScene::ChangeClothes(Moves move)
{
	selectsound.play();

	select.move(0.f, 0.f); 
}
