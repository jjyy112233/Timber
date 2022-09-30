#include "MenuScene.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include "Scene.h"

MenuScene::MenuScene(SceneManager& mgr)
	:Scene(mgr), nowSelect(Select::S_SINGLE)
{
	background.getTexture();
	selectsoundbuffer.loadFromFile("sound/select/");
	selectsound.setBuffer(selectsoundbuffer);
	
	ment.setString("Single Mode");
	Utils::SetOrigin(ment, Origins::TL);

	
	//��� ��������
	//bgm ��������
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

void MenuScene::Draw()
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

void MenuScene::Update()
{
	if (!InputMgr::GetKeyDown(Keyboard::Up) && InputMgr::GetKeyDown(Keyboard::Down))
	{
		MoveSelect(Moves::Down);
	}

	if (!InputMgr::GetKeyDown(Keyboard::Down) && InputMgr::GetKeyDown(Keyboard::Up))
	{
		MoveSelect(Moves::Up);
	}

	if (!InputMgr::GetKeyDown(Keyboard::Right) && InputMgr::GetKeyDown(Keyboard::Left))
	{
		ChangeClothes(Moves::Left);
	}

	if (!InputMgr::GetKeyDown(Keyboard::Left) &&	InputMgr::GetKeyDown(Keyboard::Right))
	{
		ChangeClothes(Moves::Right);
	}
	//Ư����Ȳ���� Ű�Է� ������ Select üũ�ϴ°� ��ġ �ű��(MoveSelect ȣ��)
	//Ư����Ȳ���� Ű�Է� ������ ChangeClothes ȣ��
}

void MenuScene::MoveSelect(Moves move)
{
	selectsound.play();

	select.move(0.f, 0.f); // *ǥ�� �̵� (X��ǥ ����,Y��ǥ +-�̵�)
}

void MenuScene::ChangeClothes(Moves move)
{
	selectsound.play();

	select.move(0.f, 0.f); // *ǥ�� �̵� (X��ǥ +-�̵�,Y��ǥ ����)
}
