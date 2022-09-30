#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Object/SpriteObject.h"

enum class Sides
{
    Left,
    Right,
    None,
};

class Branch : public SpriteObject
{
private:
    SpriteObject& tree;
    Sides side;
    Sound chopSound;

public:
    Branch(Texture& tex, SpriteObject& tree);
    virtual void Init() override;
    void SetSide(Sides side);
    Sides GetSide();

};
