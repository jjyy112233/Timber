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

	vector<SpriteObject*> trees;//Ʈ�� ���鶧 �÷��̾�, �귱ġ ���� Ʈ�� ��ġ �ֱ�
	vector<vector<Branch*>> branches; //�������� ������ƮǮ��, ������ ���� ������ �ְ� ����
	vector<int> branchCurrent;
	vector<vector<Vector2f>> branchsArr;
	vector<Player*> players;	//�÷��̾� �ΰ�

	vector<RectangleShape> timerBar;

	float duration;
	vector<int> nowScore;
	vector<float> time;
	bool isPuase;
	bool isGameOver;
	bool isMentShow;

public:
	DualScene(SceneManager& mgr); //�Ŵ������� �ʵ� ���� ����
	virtual void Init();
	virtual void Set(vector<Texture*> cloths);
	virtual void Draw(RenderWindow& window);
	virtual void Release();
	virtual ~DualScene();
	virtual void Update(float dt);
	void AddScore(int i);
	void UpdateBranch(int i);
};

