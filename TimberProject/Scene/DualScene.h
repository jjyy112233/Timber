#pragma once
#include "Scene.h"
#include "../Object/Player.h"

class SceneManager;
class DualScene : public Scene
{
	SpriteObject* background;
	Sound bgm;
	UiObject* txtMessage;
	vector<UiObject*> txtScore;

	vector<SpriteObject*> trees;//트리 만들때 플레이어, 브런치 에게 트리 위치 주기
	vector<vector<Branch*>> branches; //가지들은 오브젝트풀로, 가지가 사운드 가지고 있게 하자
	vector<int> branchCurrent;
	vector<vector<Vector2f>> branchsArr;
	vector<Player*> players;	//플렝이어 두개

	vector<RectangleShape> timerBar;

	float duration;
	vector<int> nowScore;
	vector<float> time;
	bool isPuase;
	bool isGameOver;
	bool isMentShow;

public:
	DualScene(SceneManager& mgr); //매니저에서 옷도 같이 주자
	virtual void Init();
	virtual void Set(vector<Texture*> cloths);
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~DualScene();
	virtual void Update(float dt);
	void AddScore(int i);
	void UpdateBranch(int i);
};

