#pragma once
#include "Entity.h"
#include "Game.h"

class Aircraft : public Entity
{
public:
    enum Type
    {
        Eagle,
        Raptor,
    };
public:
    explicit Aircraft(Type type, const Game::TextureHolder& textures);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    Type mType;
    sf::Sprite mSprite;
};