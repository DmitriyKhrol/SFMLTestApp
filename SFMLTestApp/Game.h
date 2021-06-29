#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "ResourceHolder.h"

//                      ** ������� � SFML **
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
// bloom shader - ��������� ����� ����� �����
// toon shader - ���������� ������� ��������� ��� � �����������
// blur effect - ���������� �������� �������� �������
// vertex shaders - ������ �� ��������� �������� � �����
// fragment shaders - ������������ ��������� �����
// GLSL
//
//
//                      * SOUND_BUFFER *
// 
// SoundBuffer    //  containing the audio samples
// �� �������� ������ �� 16-������ ������������, ��� ������ ������� ���������� ��������� ������������ � ������ ������ �������.
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
    �������� �� ������ ���������� ����� ���� �������.   
*/
class Game
{
public:
    Game();

    // ��������� ����, ��������� ���� ����
    void Run();

private:
    // ������� ��������� ���� ������������ ������� �� ������������ �� �������� ���������� ����� ����
    void processEvents();

    // ������������ ����� �������� ����� ����� ����, ���������� ��� ����
    void update(sf::Time deltaTime, sf::Time oneFrameTime, int countTick);

    // ���������� ����� ���� �� ������ ������ ����������� ���� ����
    void render();

    // ������������ ������� � ������� ������ �������������, �������� ��������� ������ � �����
    // \param ������������� ������ � ��������� ������� ������, ��� true - ������, false - ������
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    sf::RenderWindow mWindow;
    sf::Sprite playerPlane;     // ������ ������
    sf::Text mFPS;              // �����
    sf::Font mFont;             // �����
    bool mIsMovingUp;           // ���� ����������� �������� ������ �����
    bool mIsMovingDown;         // ���� ����������� �������� ������ ����
    bool mIsMovingLeft;         // ���� ����������� �������� ������ �����
    bool mIsMovingRight;        // ���� ����������� �������� ������ ������
    float PlayerSpeed;          // ������� �������� ������
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    TextureHolder textures;
};
