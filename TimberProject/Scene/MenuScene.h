#pragma once
#include "Scene.h"
#include <vector>
using namespace std;

enum class Select
{
	S_SINGLE,
	S_DUAL,
	S_CHARACTOR1,
	S_CHARACTOR2,
};

class SceneManager;
class MenuScene : public Scene
{
protected:
	Sprite background;
	Sound bgm;
	Text ment;
	vector<SpriteObject*> charactor;
	Select nowSelect;
	vector<int> clothes;

public:
	MenuScene(SceneManager& mgr);
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~MenuScene();
	virtual void Update();
	void MoveSelect();
	void ChangeClothes();
};

// Single, Dual, ĳ���� ����
// ����Ű�� ������ *�� �̵�
// �����̽��ٸ� ������ ����(�̰� �̱�, ��󿡼��� ����)
// �̱� -> ���ý� ���� ��ŸƮ
// ��� -> ���ý� ĳ���� ����â(esc�Է½� �޴� ����) -> ������ ���� ��ŸƮ
