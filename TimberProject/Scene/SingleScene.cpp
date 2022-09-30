#include "SingleScene.h"
#include "SceneManager.h"


SingleScene::SingleScene(SceneManager& mgr, Texture& cloth)
	:Scene(mgr), player(cloth,branchs)
{

}

void SingleScene::Init()
{
}

void SingleScene::Draw()
{
}

void SingleScene::Release()
{
}

SingleScene::~SingleScene()
{
}

void SingleScene::Update()
{
}
