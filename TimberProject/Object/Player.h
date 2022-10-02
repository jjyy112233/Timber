#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include "Branch.h"

class Player : public SpriteObject
{
private:
    Texture& tex;
    Texture& rip;
    SpriteObject axe; //����ִ� ����
    Sides side; // �÷��̾� ��ġ
    Vector2f center; //�����ڷ� ������ġ �޾ƿ���, ���� ���.
    Vector2f axePos; //���� ��ġ �굵 ������������ origins ��� flip����

    const int addScore; //�þ�� ����
    bool isAlive; //��Ҵ��� �׾�����
    bool isChopAxe;
    bool& isPuase;
    
    vector<Branch*>& branchs; //�귱ġ �ּ�(���Ӿ�(single, dual ���� ������)
    int& branchCurrent;
    Sound ripSound;
public:
    Player(Texture& tex, vector<Branch*>& branch, int& branchCurrent, bool& isPuase); //SpriteObject �����ڷ� �� ������,
    void SetTreeCenter(Vector2f tree); //������ �������� ��� ��ġ ���
    void Set(Texture& tex); //�� ����
    Sides GetSide();
    virtual void Init();
    virtual void Release();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);
    virtual void SetPosition(Vector2f pos);
    virtual void SetFlipX(bool flip);
    void Die();
    virtual ~Player();

    bool Chop(Sides moveSide);    //������Ʈ���� Ű �Է� ����, �¿��̵� ������ Die �ϰ� false��ȯ ������ ���� Flip���ֱ�
    int GetScore();

};

