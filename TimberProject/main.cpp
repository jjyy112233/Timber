#include "Scene/SceneManager.h"
#include "ResourceManager.h"
#include "Object/LogsPool.h"
#include "InputMgr.h"

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!", Style::Default);


    SceneManager mgr(window.getSize(), window);
    mgr.AddScene(SceneTypes::TITLE, new TitleScene(mgr));
    mgr.AddScene(SceneTypes::MENU, new MenuScene(mgr));
    mgr.AddScene(SceneTypes::SINGLESELECT, new SingleSelectScene(mgr));
    mgr.AddScene(SceneTypes::SINGLE, new SingleScene(mgr));
    mgr.AddScene(SceneTypes::DUAL, new DualScene(mgr));
    mgr.AddScene(SceneTypes::DUALSELECT, new DualSelectScene(mgr));
    mgr.SceneInit();

    Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        Time dt = clock.restart();
        InputMgr::ClearInput();
        while (window.pollEvent(event))
        {
            InputMgr::UpdateInput(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        mgr.SceneUpdata(dt.asSeconds());
        mgr.SceneDraw(window);

        window.display();
    }

    LogsPool::GetInstance()->~LogsPool();
    ResourceManager::GetInstance()->~ResourceManager();

    return 0;
}