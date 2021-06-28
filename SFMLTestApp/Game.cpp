#include "Game.h"
#include "TextureHolder.h"
#include "GlobalData.h"
#include <SFML/Audio.hpp>

Game::Game()
    : mWindow(sf::VideoMode(640, 480), "SFML Application")
    , playerPlane()
    , mFont()
    , mFPS()
{
    /*mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);*/
    mWindow.setFramerateLimit(60);
    mWindow.setVerticalSyncEnabled(true);
    mIsMovingUp = false;
    mIsMovingLeft = false;
    mIsMovingRight = false;
    mIsMovingDown = false;
    PlayerSpeed = 125.0f;

    textures.Load(Textures::ID::Hero, "../SFMLTestApp/Resources/hero.png");
    playerPlane.setTexture(textures.Get(Textures::ID::Hero));
    playerPlane.setPosition(100.f, 100.f);

    if (!mFont.loadFromFile("../SFMLTestApp/Resources/AGENCYB.TTF"))
    {
        // Handle loading error
    }
    mFPS.setFont(mFont);
    mFPS.setCharacterSize(12);
    mFPS.setFillColor(sf::Color::White);
    mFPS.setPosition(50.0f, 50.0f);


}

void Game::Run()
{
    sf::Clock clock;    // «апуск таймера, по которому будем свер€тьс€ сколько прошло времени
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())    // всЄрнутое окно считаетс€ true
    {
        processEvents();    // ќбрабатываем все накопившиес€ событи€ от пользовател€, обновл€ем значени€ флагов, например какие клавиши были нажаты
        timeSinceLastUpdate += clock.restart();     // «аписываем прошедшее врем€ на таймере и сбрасываем таймер на 0
   
        while (timeSinceLastUpdate >= TimePerFrame) {        // ѕрошло достаточно времени дл€ обновлени€ кадра
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();     
            update(TimePerFrame);       // ќбрабатываем новую итерацию цикла жизни игры, физический тик игры
        }
        
        render();   // ќтображаем новый кадр на основе нового физического тика игры
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
        /*if (event.type == sf::Event::Closed)
            mWindow.close();*/
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= PlayerSpeed;
    if (mIsMovingDown)
        movement.y += PlayerSpeed;
    if (mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if (mIsMovingRight)
        movement.x += PlayerSpeed;
    if (movement.x != 0 && movement.y != 0)
        playerPlane.move(movement / 1.414214f * deltaTime.asSeconds());    // 1.414214f = sqrt(2), движение по диагонали
    else
        playerPlane.move(movement * deltaTime.asSeconds());
    mFPS.setString(std::to_string(1 / deltaTime.asSeconds()) + " fps");        /////////////////////////////////////////
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(playerPlane);
    mWindow.draw(mFPS);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}