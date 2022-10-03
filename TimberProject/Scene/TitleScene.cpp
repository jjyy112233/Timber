#include "TitleScene.h"
#include "SceneManager.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"
#include <SFML/Audio.hpp>

TitleScene::TitleScene(SceneManager& mgr) // �Ź� ������ �ƴ϶� �����س��� ��Ȱ���� ���̱� ������ ������ ���� �ְ�, �־�� �� ���� �ִ�. �װ� ����?
	: Scene(mgr)
{
	background = new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/background.png"));
	objs.push_back(background);

	ment = new UiObject("Press Enter To Start!", *ResourceManager::GetInstance()->GetFont("fonts/KOMIKAP_.ttf"), 75, Color::White);
	uis.push_back(ment);

	//���ҽ��Ŵ���::Get�ν��Ͻ�()->Get��Ʈ("���");
	//������

	bgm.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/Hennesis.wav"));
	//��� ��������
	// bgm.setBuffer(""); // ����
}

void TitleScene::Init()
{

	ment->SetOrigin(Origins::MC);
	ment->SetPosition(Vector2f{(float)1920/2, (float)1080/2});

	
	bgm.play();
	// ���Ӿ��� �ٲ�� �׷��鼭 �������ٳ� ĳ������ ��ġ���� �ʱ�ȭ���ִ°� Init�̴�.
	// �ؽ�Ʈ ��ġ �����ְ�


	// ��� Ʋ���ֱ�
	//bgm.play();
}

void TitleScene::Draw(RenderWindow& window)
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

void TitleScene::Release()
{
	//objs�� uis�� �ִ°� ����
}

TitleScene::~TitleScene()
{
	Release();
}

void TitleScene::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		bgm.stop();
		exit(-1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		mgr.MoveScene(SceneTypes::MENU);
		bgm.stop();
	}
}