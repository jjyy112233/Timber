#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include "Branch.h"

class Player : public SpriteObject
{
private:
    Texture& tex;
    Texture& rip;
    SpriteObject axe; //들고있는 도끼
    Sides side; // 플레이어 위치
    Vector2f center; //생성자로 나무위치 받아오고, 센터 잡기.
    Vector2f axePos; //도끼 위치 얘도 나무기준으로 origins 잡고 flip하자

    const int addScore; //늘어나는 점수
    bool isAlive; //살았는지 죽었는지
    bool isChopAxe;
    bool& isPuase;
    
    vector<Branch*>& branchs; //브런치 주소(게임씬(single, dual 에서 가져옴)
    int& branchCurrent;
    Sound ripSound;
public:
    Player(Texture& tex, vector<Branch*>& branch, int& branchCurrent, bool& isPuase); //SpriteObject 생성자로 옷 입히고,
    void SetTreeCenter(Vector2f tree); //나무를 기준으로 가운데 위치 잡고
    void Set(Texture& tex); //옷 변경
    Sides GetSide();
    virtual void Init();
    virtual void Release();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);
    virtual void SetPosition(Vector2f pos);
    virtual void SetFlipX(bool flip);
    void Die();
    virtual ~Player();

    bool Chop(Sides moveSide);    //업데이트에서 키 입력 감지, 좌우이동 죽으면 Die 하고 false반환 도끼도 같이 Flip해주기
    int GetScore();

};

