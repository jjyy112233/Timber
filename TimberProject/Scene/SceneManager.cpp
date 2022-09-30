#include "SceneManager.h"
#include "../ResourceManager.h"

SceneManager::SceneManager(Vector2u size)
    :size(size)
{
}
Vector2u SceneManager::GetSize()
{
    return size;
}

void SceneManager::SceneInit()
{
    scenes[SceneTypes::SINGLE]->Init();

}
void SceneManager::SceneUpdata(float dt)
{
    scenes[SceneTypes::SINGLE]->Update(dt);
}
void SceneManager::SceneDraw(RenderWindow& window)
{
    scenes[SceneTypes::SINGLE]->Draw(window);
}
void SceneManager::MoveScene(SceneTypes type, vector<int> sceneInfo)
{
}

