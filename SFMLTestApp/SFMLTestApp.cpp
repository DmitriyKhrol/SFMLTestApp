#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(600, 600), "Field");

  window.setFramerateLimit(65);

  sf::Texture textureActor;
  if (!textureActor.loadFromFile("../SFMLTestApp/Resources/actor.png"))
    return -1;

  sf::Sprite spriteActor;
  spriteActor.setTexture(textureActor);

  /*sf::Texture textureFPS;
  if (!textureFPS.create(100, 100))
    return -1;

  sf::Sprite spriteFPS(textureFPS);*/


  // Главный цикл приложения. Выполняется, пока открыто окно
  while (window.isOpen())
  {
    // Обрабатываем очередь событий в цикле
    sf::Event event;
    while (window.pollEvent(event))
    {
      // Пользователь нажал на «крестик» и хочет закрыть окно?
      if (event.type == sf::Event::Closed)
        window.close();



    }

    /*sf::Uint8* pixels = ;
    textureFPS.update(pixels);
    window.draw(spriteFPS);*/

    window.draw(spriteActor);
    window.display();
  }

  return 0;
}

