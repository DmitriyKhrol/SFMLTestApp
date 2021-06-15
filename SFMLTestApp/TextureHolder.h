#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GlobalData.h"

/*
  Данный класс отвечает за правильную работу с текстурами. Их загрузку в программу, хранение и выдачу.
*/
class TextureHolder {
public:
  void Load(Textures::ID id, const std::string& filename);
  sf::Texture& Get(Textures::ID id);
  const sf::Texture& Get(Textures::ID id) const;
private:
  
private:
  std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};