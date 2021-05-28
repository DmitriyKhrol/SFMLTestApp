#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works!");

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




    window.display();
  }

  return 0;
}

