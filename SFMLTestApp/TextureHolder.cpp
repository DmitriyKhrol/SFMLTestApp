#include "TextureHolder.h"
#include "GlobalData.h"
#include <cassert>


void TextureHolder::Load(Textures::ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if (!texture->loadFromFile(filename))
        throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

sf::Texture& TextureHolder::Get(Textures::ID id)
{
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end() && "Not found this texture!");    // Утверждение, если не нашли текстуру с таким ID
    return *found->second;
}