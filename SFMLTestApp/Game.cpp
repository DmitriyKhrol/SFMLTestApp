#pragma once
#include "Game.h"



Game::Game()
    : mWindow(sf::VideoMode(640, 480), "SFML Application")
    , playerPlane()
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

    // �������� �������� �����
    textureHolder.Load(Textures::ID::Hero, "../SFMLTestApp/Resources/actor.png");
    playerPlane.setTexture(textureHolder.Get(Textures::ID::Hero));
    playerPlane.setPosition(100.f, 100.f);
    playerPlane.setScale(sf::Vector2f(0.2f, 0.2f));

    // �������� ������ ��� �������� FPS
    fontHolder.Load(Fonts::ID::FPS, "../SFMLTestApp/Resources/AGENCYB.TTF");
    mFPS.setFont(fontHolder.Get(Fonts::ID::FPS));
    mFPS.setCharacterSize(12);
    mFPS.setFillColor(sf::Color::White);
    mFPS.setPosition(50.0f, 50.0f);






}

void Game::Run()
{
    sf::Clock clock;    // ������ �������, �� �������� ����� ��������� ������� ������ �������
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time currSteoOfTime = sf::Time::Zero;
    int countTick = 0;

    while (mWindow.isOpen())    // �������� ���� ��������� true
    {
        processEvents();    // ������������ ��� ������������ ������� �� ������������, ��������� �������� ������, �������� ����� ������� ���� ������
        currSteoOfTime = clock.restart();                    // ���������� ��������� ����� �� ������� � ���������� ������ �� 0
        countTick++;
        timeSinceLastUpdate += currSteoOfTime;     
   
        while (timeSinceLastUpdate >= TimePerFrame) {        // ������ ���������� ������� ��� ���������� �����
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();     
            update(timeSinceLastUpdate + TimePerFrame, TimePerFrame, countTick);       // ������������ ����� �������� ����� ����� ����, ���������� ��� ����
            countTick = 0;
        }
        
        render();   // ���������� ����� ���� �� ������ ������ ����������� ���� ����
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

void Game::update(sf::Time deltaTime, sf::Time oneFrameTime, int countTick)
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
        playerPlane.move(movement / 1.414214f * deltaTime.asSeconds());    // 1.414214f = sqrt(2), �������� �� ���������
    else
        playerPlane.move(movement * deltaTime.asSeconds());

    mFPS.setString(std::to_string(deltaTime.asSeconds() / oneFrameTime.asSeconds() / oneFrameTime.asSeconds() * countTick) + " fps");
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