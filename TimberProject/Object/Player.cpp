#include "Player.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"

Player::Player(Texture& tex, vector<Branch*>& branchs, int& branchCurrent)
	: SpriteObject(tex),tex(tex), branchCurrent(branchCurrent),
	rip(*ResourceManager::GetInstance()->GetTexture("graphics/rip.png")),
	branchs(branchs), addScore(100), isAlive(false), isShowAxe(false), side(Sides::Right),
	axe(*ResourceManager::GetInstance()->GetTexture("graphics/axe.png"))
{
	ripSound.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/death.wav"));
	SetOrigin(Origins::BC);
	axe.SetOrigin(Origins::BC);
	SetPosition(center);
	axe.SetPosition(GetPosition());
}

void Player::Set(Vector2f tree)
{
	Texture treeTex = *ResourceManager::GetInstance()->GetTexture("graphics/tree.png");
	Vector2u treeSize = treeTex.getSize();
	center = tree;

}

Sides Player::GetSide()
{
	return side;
}

void Player::Init()
{
	isAlive = true;
	sprite.setTexture(tex,true);

	SetOrigin(Origins::BC);
	axe.SetOrigin(Origins::BC);
	SetPosition({ side == Sides::Left ? center.x - 300 : center.x + 300,center.y });
	SetFlipX(side == Sides::Left ? true : false);
	axe.SetPosition(GetPosition());
	ripSound.stop();
	isChopAxe = false;
}

void Player::Release()
{
}

void Player::Update(float dt)
{
	SpriteObject::Update(dt);
	
	if (isAlive)
	{
		if (InputMgr::GetKey(Keyboard::Left) || InputMgr::GetKey(Keyboard::Right))
			isChopAxe = true;
		else if(isShowAxe)
			isChopAxe = false;
	}
}

void Player::Draw(RenderWindow& window)
{
	SpriteObject::Draw(window);
	if(isChopAxe && isShowAxe)
		axe.Draw(window);
}

void Player::SetPosition(Vector2f pos)
{
	SpriteObject::SetPosition(pos);
	//일단 잠시 비워놓기
}

void Player::SetFlipX(bool flip)
{
	SpriteObject::SetFlipX(flip);
	axe.SetFlipX(flip);
}

void Player::Die()
{
	isAlive = false;
	sprite.setTexture(rip,true);
	SetOrigin(Origins::BC);
	SetFlipX(false);

}

Player::~Player()
{
}

bool Player::Chop(Sides moveSide)
{
	side = moveSide;

	SetFlipX(side == Sides::Left ? true : false);
	SetPosition({ side == Sides::Left ? center.x -300: center.x + 300,center.y });
	axe.SetPosition(GetPosition());

	if (side == branchs[branchCurrent]->GetSide())
	{
		Die();
		return false;
	}
	return true;
}
void Player::SetChopShow(bool state)
{
	isShowAxe = state;
}

int Player::GetScore()
{
	return addScore;
}
