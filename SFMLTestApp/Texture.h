#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Textures {
  enum class ID;

  class TextureHolder{
  private:
    void load(Textures::ID id, const std::string& filename);
  private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
  };
  
}