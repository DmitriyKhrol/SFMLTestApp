#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

// Texture (graphics card)     // sf::Texture::getMaximumSize()
// Image -> Texture -> Sprite
// JPEG, BMP, PNG

// Image (RAM)
// Image -> Texture -> Sprite
// JPEG, BMP, PNG

// Font (file, memory location, or stream)
// Font -> Text
// TTF (true type fonts), OTF (open type fonts)

// Shader (graphics card)
// bloom shader - ��������� ����� ����� �����
// toon shader - ���������� ������� ��������� ��� � �����������
// blur effect - ���������� �������� �������� �������
// vertex shaders - ������ �� ��������� �������� � �����
// fragment shaders - ������������ ��������� �����
// GLSL

// SoundBuffer    //  containing the audio samples
/* �� �������� ������ �� 16-������ ������������, ��� ������ ������� ���������� ��������� ������������ � ������ ������ �������.*/
// SoundBuffer -> Sound
// WAV, OGG, AIFF

// Music (file or memory location)
// Music
// WAV, OGG, AIFF




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
  sf::Sprite playerPlane;
  sf::Text mFPS;
  sf::Font mFont;
  bool mIsMovingUp;
  bool mIsMovingDown;
  bool mIsMovingLeft;
  bool mIsMovingRight;
  float PlayerSpeed;
  const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
  //sf::Texture mTexture;
  TextureHolder textures;
};
