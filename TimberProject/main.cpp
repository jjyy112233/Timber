﻿#include "Scene/SceneManager.h"
#include "ResourceManager.h"
#include "InputMgr.h"

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!", Style::Default);
    SceneManager mgr(window.getSize());
    mgr.scenes[SceneTypes::MENU] = new MenuScene(mgr);
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

    return 0;
}