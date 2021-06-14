#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GlobalData.h"

class TextureHolder {
public:
  void Load(Textures::ID id, const std::string& filename);
  sf::Texture& Get(Textures::ID id);
  const sf::Texture& Get(Textures::ID id) const;
private:
  
private:
  std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};