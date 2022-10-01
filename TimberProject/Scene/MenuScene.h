#pragma once
#include "Scene.h"
#include <vector>



using namespace std;

enum class Moves
{
	Up,
	Down,
	Left,
	Right,
	W,
	A,
	S,
	D,
};

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
	SpriteObject* background;
	Sound bgm;
	SoundBuffer selectsoundbuffer;
	Sound selectsound;
	Text sment;
	Text dment;
	Text select;
	vector<SpriteObject*> charactor;
	Select nowSelect;
	vector<int> clothes;
	Moves pos;
	bool SelectDown;
public:
	MenuScene(SceneManager& mgr);
	virtual void Init();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~MenuScene();
	virtual void Update(float dt);
	void MoveSelect(Moves move);
	void ChangeClothes(Moves move);
};

// Single, Dual, ĳ���� ����
// ����Ű�� ������ *�� �̵�
// �����̽��ٸ� ������ ����(�̰� �̱�, ��󿡼��� ����)
// �̱� -> ���ý� ���� ��ŸƮ
// ��� -> ���ý� ĳ���� ����â(esc�Է½� �޴� ����) -> ������ ���� ��ŸƮ
