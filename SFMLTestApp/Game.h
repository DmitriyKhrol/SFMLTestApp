#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
  Game();
  void run();
private:
  void processEvents();
  void update(sf::Time deltaTime);
  void render();
  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
  sf::RenderWindow mWindow;
  sf::Sprite mPlayer;
  sf::Text mFPS;
  sf::Font mFont;
  bool mIsMovingUp;
  bool mIsMovingDown;
  bool mIsMovingLeft;
  bool mIsMovingRight;
  float PlayerSpeed;
  const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
  sf::Texture mTexture;
};