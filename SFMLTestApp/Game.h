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
// bloom shader - усиливает яркие части сцены
// toon shader - заставляет объекты выглядеть как в мультфильме
// blur effect - иммитирует мерцание горячего воздуха
// vertex shaders - влияют на геометрию объектов в сцене
// fragment shaders - манипулируют пикселями сцены
// GLSL

// SoundBuffer    //  containing the audio samples
/* Он содержит массив из 16-битных аудиосэмплов, где каждая выборка определяет амплитуду аудиосигнала в данный момент времени.*/
// SoundBuffer -> Sound
// WAV, OGG, AIFF

// Music (file or memory location)
// Music
// WAV, OGG, AIFF

/*
  Данный класс отвечает за полный набор функций жизненного цикла программы.
*/
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
  TextureHolder textures;
};
