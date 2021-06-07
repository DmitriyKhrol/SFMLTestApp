#include "Game.h"

Game::Game()
  : mWindow(sf::VideoMode(640, 480), "SFML Application")
  , mTexture()
  , mPlayer()
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
  
  if (!mTexture.loadFromFile("../SFMLTestApp/Resources/hero.png"))
  {
    // Handle loading error
  }
  mPlayer.setTexture(mTexture);
  mPlayer.setPosition(100.f, 100.f);

  if (!mFont.loadFromFile("../SFMLTestApp/Resources/AGENCYB.TTF"))
  {
    // Handle loading error
  }
  mFPS.setFont(mFont);
  mFPS.setCharacterSize(12);
  mFPS.setFillColor(sf::Color::White);
  mFPS.setPosition(50.0f, 50.0f); 
}

void Game::run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (mWindow.isOpen())
  {
    processEvents();
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > TimePerFrame)
    {
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      update(TimePerFrame);
    }
    render();
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
    if (event.type == sf::Event::Closed)
      mWindow.close();
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
  if(movement.x != 0 && movement.y != 0)
    mPlayer.move(movement / 1.414214f * deltaTime.asSeconds());    // 1.414214f = sqrt(2), �������� �� ���������
  else
    mPlayer.move(movement * deltaTime.asSeconds());
  mFPS.setString(std::to_string(1 / deltaTime.asSeconds()) + " fps");        /////////////////////////////////////////
}

void Game::render()
{
  mWindow.clear();
  mWindow.draw(mPlayer);
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