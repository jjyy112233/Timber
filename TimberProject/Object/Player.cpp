#include "Player.h"
#include "../ResourceManager.h"

Player::Player(Texture& tex, vector<Branch*>& branchs, int& branchCurrent)
	: SpriteObject(tex),tex(tex), branchCurrent(branchCurrent),
	rip(*ResourceManager::GetInstance()->GetTexture("graphics/rip.png")),
	branchs(branchs), addScore(100), isAlive(true), side(Sides::Left),
	axe(*ResourceManager::GetInstance()->GetTexture("graphics/axe.png"))
{
	SetOrigin(Origins::BL);
	axe.SetOrigin(Origins::BL);
	ripSound.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/death.wav"));
}

void Player::Set(Vector2f tree)
{
	Texture treeTex = *ResourceManager::GetInstance()->GetTexture("graphics/tree.png");
	Vector2u treeSize = treeTex.getSize();
	center = tree;
	SetPosition({ center.x + treeSize.x / 2 + 30 ,center.y });
	axe.SetPosition({ GetPosition().x - 20, GetPosition().y - 10 });
}

Sides Player::GetSide()
{
	return side;
}

void Player::Init()
{
	sprite.setTexture(tex,true);
	SetOrigin(Origins::BL);

	isAlive = true;
	ripSound.stop();
}

void Player::Release()
{
}

void Player::Update(float dt)
{
	SpriteObject::Update(dt);
}

void Player::Draw(RenderWindow& window)
{
	SpriteObject::Draw(window);
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
