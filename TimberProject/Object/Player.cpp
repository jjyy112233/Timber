#include "Player.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"

Player::Player(Texture& tex, vector<Branch*>& branchs, int& branchCurrent)
	: SpriteObject(tex),tex(tex), branchCurrent(branchCurrent),
	rip(*ResourceManager::GetInstance()->GetTexture("graphics/rip.png")),
	branchs(branchs), addScore(100), isAlive(true), side(Sides::Right),
	axe(*ResourceManager::GetInstance()->GetTexture("graphics/axe.png"))
{
	ripSound.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/death.wav"));
	SetOrigin(Origins::BL);
	axe.SetOrigin(Origins::BL);
}

void Player::Set(Vector2f tree)
{
	Texture treeTex = *ResourceManager::GetInstance()->GetTexture("graphics/tree.png");
	Vector2u treeSize = treeTex.getSize();
	center = tree;

	SetOrigin(Origins::BL);
	SetOrigin({ GetOrigin().x - 200 , GetOrigin().y });
	SetPosition(center);
	axe.SetOrigin(Origins::BL);
	axe.SetOrigin({ axe.GetOrigin().x - 200 , axe.GetOrigin().y });
	axe.SetPosition(center);
}

Sides Player::GetSide()
{
	return side;
}

void Player::Init()
{
	sprite.setTexture(tex,true);
	isAlive = true;

	ripSound.stop();
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
			isShowAxe = true;
		else
			isShowAxe = false;
	}
}

void Player::Draw(RenderWindow& window)
{
	SpriteObject::Draw(window);
	if(isShowAxe)
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
	SetOrigin(Origins::BL);
	SetOrigin({ GetOrigin().x - 200 , GetOrigin().y });
	SetPosition(center);
}

Player::~Player()
{
}

bool Player::Chop(Sides moveSide)
{
	side = moveSide;

	SetFlipX(side == Sides::Left ? true : false);

	if (side == branchs[branchCurrent]->GetSide())
	{
		Die();
		return false;
	}
	return true;
}

int Player::GetScore()
{
	return addScore;
}
