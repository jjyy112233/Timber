#include "SceneManager.h"
#include "../ResourceManager.h"

SceneManager::SceneManager(Vector2u size)
    :size(size), nowScene(SceneTypes::TITLE)
{
}

void SceneManager::AddScene(SceneTypes type, Scene* scene)
{
    scenes[type] = scene;
}
Vector2u SceneManager::GetSize()
{
    return size;
}

void SceneManager::SceneInit()
{
    scenes[nowScene]->Init();
}
void SceneManager::SceneUpdata(float dt)
{
    scenes[nowScene]->Update(dt);
}
void SceneManager::SceneDraw(RenderWindow& window)
{
    scenes[nowScene]->Draw(window);
}
void SceneManager::MoveScene(SceneTypes type, vector<int> sceneInfo)
{
    nowScene = type;
    scenes[nowScene]->Init();
}
