#include "TitleScene.h"
#include "SceneManager.h"

TitleScene::TitleScene(SceneManager& mgr)
	: Scene(mgr)
{
	//��� ����, �ؽ�Ʈ ����
	//vector�� �־��ְ�
	//��� ��������
	//Init()
}

void TitleScene::Init()
{
	//�ؽ�Ʈ ��ġ �����ְ�
	//��� Ʋ���ֱ�
}

void TitleScene::Draw(RenderWindow& window)
{
	//for (auto obj : objs)
	//{
	//	obj->Draw(window);
	//}
}

void TitleScene::Release()
{
	//objs�� uis�� �ִ°� ����
}

TitleScene::~TitleScene()
{
	//Release();
}

void TitleScene::Update(float dt)
{
}
