#include "Aircraft.h"

Textures::ID toTextureID(Aircraft::Type type)
{
    switch (type)
    {
    case Aircraft::Eagle:
        return Textures::ID::Hero;
    case Aircraft::Raptor:
        return Textures::ID::Hero;
    }
}

Aircraft::Aircraft(Type type, const Game::TextureHolder& textures) : mType(type), mSprite(textures.Get(toTextureID(type)))
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}