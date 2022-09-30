#include "SceneManager.h"

SceneManager::SceneManager(Vector2u size)
    :size(size)
{
}

void SceneManager::MoveScene(SceneTypes type, vector<int> sceneInfo)
{
}

const Vector2u SceneManager::GetSize() const
{
    return window.getSize();
}

RenderWindow& SceneManager::GetWindow()
{
    return window;
}
