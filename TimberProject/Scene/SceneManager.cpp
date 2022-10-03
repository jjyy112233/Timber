#include "SceneManager.h"
#include "../ResourceManager.h"

SceneManager::SceneManager(Vector2u size, RenderWindow& window)
    :size(size), nowScene(SceneTypes::TITLE)
{
    tex.loadFromFile("graphics/background.png");
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    loading.setTexture(tex);
    loadingText.setFont(font);

    loadingText.setFillColor(Color::White);
    loadingText.setString("Loading...");
    loadingText.setCharacterSize(75);
    loadingText.setOrigin({ loadingText.getLocalBounds().width * 0.5f ,loadingText.getLocalBounds().height * 0.5f });
    loadingText.setPosition(Vector2f{ (float)size.x / 2,(float)size.y / 2 });

    window.draw(loading);
    window.draw(loadingText);
    window.display();
}
SceneManager::~SceneManager()
{
    for (auto scene : scenes)
    {
        delete scene.second;
    }
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
void SceneManager::MoveScene(SceneTypes type, vector<Texture*> sceneInfo)
{
    nowScene = type;
    scenes[nowScene]->Set(sceneInfo);
    scenes[nowScene]->Init();
    if (sceneInfo.empty())
    {
       // scenes[nowScene]->Set(sceneInfo);
    }
}
