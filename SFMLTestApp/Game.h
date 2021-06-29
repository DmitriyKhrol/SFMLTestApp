#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "ResourceHolder.h"

//                      ** РЕСУРСЫ В SFML **
// 
// 
//                         * TEXTURE *
// 
// Texture (graphics card)     // sf::Texture::getMaximumSize()
// Image -> Texture -> Sprite
// JPEG, BMP, PNG
//
// 
//                          * IMAGE *
// 
// Image (RAM)
// Image -> Texture -> Sprite
// JPEG, BMP, PNG
//
// 
//                          * FONT *
// 
// Font (file, memory location, or stream)
// Font -> Text
// TTF (true type fonts), OTF (open type fonts)
//
// 
//                         * SHADER *
// 
// Shader (graphics card)
// bloom shader - усиливает яркие части сцены
// toon shader - заставляет объекты выглядеть как в мультфильме
// blur effect - иммитирует мерцание горячего воздуха
// vertex shaders - влияют на геометрию объектов в сцене
// fragment shaders - манипулируют пикселями сцены
// GLSL
//
//
//                      * SOUND_BUFFER *
// 
// SoundBuffer    //  containing the audio samples
// Он содержит массив из 16-битных аудиосэмплов, где каждая выборка определяет амплитуду аудиосигнала в данный момент времени.
// SoundBuffer -> Sound
// WAV, OGG, AIFF
//
// 
//                          * MUSIC *
// 
// Music (file or memory location)
// Music
// WAV, OGG, AIFF

/*
    Отвечает за работу жизненного цикла игры клиента.   
*/
class Game
{
public:
    Game();

    // Запускает игру, жизненный цикл игры
    void Run();

private:
    // Функция обработки всех накопившихся событий от пользователя за итерацию жизненного цикла игры
    void processEvents();

    // Обрабатывает новую итерацию цикла жизни игры, физический тик игры
    void update(sf::Time deltaTime, sf::Time oneFrameTime, int countTick);

    // Отображает новый кадр на основе нового физического тика игры
    void render();

    // Обрабатывает нажатия и отжатик кнопок пользователем, сохраняя состояния кнопок в флаги
    // \param Идентификатор кнопки и состояние нажатия кнопки, где true - нажата, false - отжата
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    sf::RenderWindow mWindow;
    sf::Sprite playerPlane;     // спрайт игрока
    sf::Text mFPS;              // текст
    sf::Font mFont;             // шрифт
    bool mIsMovingUp;           // флаг направления движения игрока вверх
    bool mIsMovingDown;         // флаг направления движения игрока вниз
    bool mIsMovingLeft;         // флаг направления движения игрока влево
    bool mIsMovingRight;        // флаг направления движения игрока вправо
    float PlayerSpeed;          // текущая скорость игрока
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    TextureHolder textures;
};
