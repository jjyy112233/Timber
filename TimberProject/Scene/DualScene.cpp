#include "DualScene.h"
#include "SceneManager.h"

DualScene::DualScene(SceneManager& mgr, Texture& cloths1, Texture& cloths2)
	:Scene(mgr)
{
	/*
		���, ����, ��, ���� objs�� �־��ְ�
		Ʈ���� new �� ����� ��ġ ��� (mgr.GetSize()) �� ��ġ ����
		branchs �� ���� ������ְ�(������ Ʈ�� ��ġ �����ְ�)
		���� Ư��������ŭ push_back ���ְ�
		�÷��̾����� ���̶� branchs[idx] �����ڷ� �ְ�

		�÷��̾� set���� ��ġ �߾� ������ְ�
		�ʿ��� �ؽ�Ʈ�� ���� uis�� �־��ְ�
		Timer�� ���� ������Ʈ�� �־��ְ� �� Ÿ�̸Ӵ� ui�ε� �� sprite�ΰųİ� ¥����
	*/
	
}

void DualScene::Init()
{
}

void DualScene::Draw()
{ 

}

void DualScene::Release()
{
}

DualScene::~DualScene()
{
}

void DualScene::Update()
{
}
