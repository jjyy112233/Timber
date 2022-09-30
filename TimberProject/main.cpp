#include "Scene/SceneManager.h"
#include "ResourceManager.h"
#include "InputMgr.h"

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!", Style::Default);
    SceneManager mgr(window.getSize());
    mgr.scenes[SceneTypes::SINGLE] = new SingleScene(
        mgr, *ResourceManager::GetInstance()->GetTexture("graphics/player.png")
    );


    mgr.SceneInit();
    Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        Time dt = clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //mgr.SceneUpdata(dt.asSeconds());
        mgr.SceneDraw(window);

        window.display();
    }

    return 0;
}