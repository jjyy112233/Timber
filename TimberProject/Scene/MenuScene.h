#pragma once
#include "Scene.h"
#include <vector>



using namespace std;

enum class Moves
{
	Left,
	Right,
};

enum class Select
{
	S_SINGLE,
	S_DUAL,
};

class SceneManager;
class MenuScene : public Scene
{
protected:
	SpriteObject* background;
	Sound bgm;	
	UiObject* sment;
	UiObject* dment;
	UiObject* select;
	SpriteObject* arrow;
	Select nowSelect;
public:
	MenuScene(SceneManager& mgr);
	virtual void Init();
	virtual void Set(vector<string> cloths) {};
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~MenuScene();
	virtual void Update(float dt);
	void MoveSelect(Moves move);
};

// Single, Dual, ĳ���� ����
// ����Ű�� ������ *�� �̵�
// �����̽��ٸ� ������ ����(�̰� �̱�, ��󿡼��� ����)
// �̱� -> ���ý� ���� ��ŸƮ
// ��� -> ���ý� ĳ���� ����â(esc�Է½� �޴� ����) -> ������ ���� ��ŸƮ
