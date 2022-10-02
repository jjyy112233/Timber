#include "CharactorSelectScene.h"

charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player3.png")));
objs.push_back(charactor[1]);
charactor[1]->SetOrigin(Origins::TC);
charactor[1]->SetPosition({ sment.getPosition().x + sment.getLocalBounds().width / 2, 500 });
charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player4.png")));
objs.push_back(charactor[2]);
charactor[2]->SetOrigin(Origins::TL);
charactor[2]->SetPosition({ dment.getPosition().x + dment.getLocalBounds().width / 2, 500 });
charactor.push_back(new SpriteObject(*ResourceManager::GetInstance()->GetTexture("graphics/player5.png")));
objs.push_back(charactor[3]);
charactor[3]->SetOrigin(Origins::TR);
charactor[3]->SetPosition({ dment.getPosition().x + dment.getLocalBounds().width / 2, 500 });