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
	None,
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
	Sprite background;
	Sound bgm;
	SoundBuffer selectsoundbuffer;
	Sound selectsound;
	Text ment;
	Text select;
	vector<SpriteObject*> charactor;
	Select nowSelect;
	vector<int> clothes;
	Moves pos;

public:
	MenuScene(SceneManager& mgr);
	virtual void Init();
	virtual void Draw();
	virtual void Release();
	virtual ~MenuScene();
	virtual void Update();
	void MoveSelect(Moves move);
	void ChangeClothes(Moves move);
};

// Single, Dual, 캐릭터 선택
// 방향키를 누르면 *을 이동
// 스페이스바를 누르면 선택(이건 싱글, 듀얼에서만 동작)
// 싱글 -> 선택시 게임 스타트
// 듀얼 -> 선택시 캐릭터 선택창(esc입력시 메뉴 복귀) -> 선택후 게임 스타트