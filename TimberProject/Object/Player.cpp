#include "Player.h"

Player::Player(Texture& tex, vector<Branch*>& branch)
	:SpriteObject(tex), branch(branch), addScore(100), isAlive(true), side(Sides::Left)
{
}

void Player::Set(int clothIdx, Vector2f tree)
{
}

void Player::Init()
{
}

void Player::Release()
{
}

void Player::Update(float dt)
{
}

void Player::Draw(RenderWindow& window)
{
}

void Player::SetPosition(Vector2f pos)
{
}

void Player::SetFlipX(bool flip)
{
}

void Player::Die()
{
}

Player::~Player()
{
}

bool Player::Chop(Sides branchSide)
{
	return false;
}

int Player::GetScore()
{
	return 0;
}
