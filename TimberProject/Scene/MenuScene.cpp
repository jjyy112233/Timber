#include "MenuScene.h"

MenuScene::MenuScene(SceneManager& mgr)
	:Scene(mgr), nowSelect(Select::S_SINGLE)
{
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
}

MenuScene::~MenuScene()
{
	Release();
}

void MenuScene::Update()
{
	//Ư����Ȳ���� Ű�Է� ������ Select üũ�ϴ°� ��ġ �ű��(MoveSelect ȣ��)
	//Ư����Ȳ���� Ű�Է� ������ ChangeClothes ȣ��
}

void MenuScene::MoveSelect()
{
}

void MenuScene::ChangeClothes()
{
}
