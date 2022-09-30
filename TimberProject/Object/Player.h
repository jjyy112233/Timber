#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include "Branch.h"

class Player : public SpriteObject
{
private:
    Texture Rip;
    Sprite axe; //����ִ� ����
    Sides side; // �÷��̾� ��ġ
    Vector2f center; //�����ڷ� ������ġ �޾ƿ���, ���� ���.
    Vector2f axePos; //���� ��ġ �굵 ������������ origins ��� flip����

    int addScore; //�þ�� ����
    bool isAlive; //��Ҵ��� �׾�����
    
    vector<Branch*>& branch; //�귱ġ �ּ�(���Ӿ�(single, dual ���� ������)
    Sound ripSound;
public:
    Player(Texture& tex, vector<Branch*>& branch); //SpriteObject �����ڷ� �� ������,
    void Set(int clothIdx, Vector2f tree); //�� ����,  ������ �������� ��� ��ġ ���
    virtual void Init();
    virtual void Release();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);
    virtual void SetPosition(Vector2f pos);
    virtual void SetFlipX(bool flip);
    void Die();
    virtual ~Player();

    bool Chop(Sides branchSide);    //������Ʈ���� Ű �Է� ����, �¿��̵� ������ Die �ϰ� false��ȯ ������ ���� Flip���ֱ�
    int GetScore();

};

