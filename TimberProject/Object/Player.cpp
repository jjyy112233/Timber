#include "Player.h"
#include "../ResourceManager.h"
#include "../InputMgr.h"

Player::Player(Texture& tex, vector<Branch*>& branchs, int& branchCurrent, bool& isPuase)
	: SpriteObject(tex), tex(tex), rip(*ResourceManager::GetInstance()->GetTexture("graphics/rip.png")),
	axe(*ResourceManager::GetInstance()->GetTexture("graphics/axe.png")),
	branchCurrent(branchCurrent), branchs(branchs), side(Sides::Right),
	isPuase(isPuase), addScore(100), isAlive(false)
{
	ripSound.setBuffer(*ResourceManager::GetInstance()->GetSoundBuffer("sound/death.wav"));
	SetOrigin(Origins::BC);
	axe.SetOrigin(Origins::BC);
	SetPosition(center);
	axe.SetPosition(GetPosition());
}


void Player::SetTreeCenter(Vector2f tree)
{
	center = tree;
}
void Player::Set(Texture& tex)
{
	this->tex = tex;
	sprite.setTexture(tex,true);
	SetOrigin(Origins::BC);
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
	
	if (isAlive && !isPuase)
	{
		if (InputMgr::GetKey(Keyboard::Left) || InputMgr::GetKey(Keyboard::Right))
			isChopAxe = true;
		else
			isChopAxe = false;
	}
}

void Player::Draw(RenderWindow& window)
{
	SpriteObject::Draw(window);
	if(isChopAxe)
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

int Player::GetScore()
{
	return addScore;
}
