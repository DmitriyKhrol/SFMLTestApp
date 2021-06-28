#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

/*
	Вход в программу, вызывает запуск игры. Создаёт игру и вызывает её исполнение. 
	(ЧТО делает? КАК код выполняет задание? ПОЧЕМУ код выполняет задание именно так, а не иначе?)
	\param Отсутствуют
	\return (int 0) - нет ошибок, иначе произошла ошибка	
*/
int main()
{
	Game game;
	game.Run();

	//sf::RenderWindow window(sf::VideoMode(640, 480), "Field");
	//window.setFramerateLimit(65);


	//sf::Texture herotexture;
	//herotexture.loadFromFile("../SFMLTestApp/Resources/hero.png");

	//sf::Sprite herosprite;
	//herosprite.setTexture(herotexture);
	//herosprite.setTextureRect(sf::IntRect(0, 192, 96, 96));
	//herosprite.setPosition(250, 250);

	//float CurrentFrame = 0;//хранит текущий кадр
	//sf::Clock clock;

	//while (window.isOpen())
	//{

	//	float time = clock.getElapsedTime().asMicroseconds();
	//	clock.restart();
	//	time = time / 800;


	/*sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}*/


	//	///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
	//	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) { //если нажата клавиша стрелка влево или англ буква А
	//		CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	//		if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
	//		herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
	//		herosprite.move(-0.1 * time, 0);//происходит само движение персонажа влево
	//	}

	//	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
	//		CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	//		if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
	//		herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96

	//		herosprite.move(0.1 * time, 0);//происходит само движение персонажа вправо

	//	}


	//	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) {
	//		CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	//		if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
	//		herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
	//		herosprite.move(0, -0.1 * time);//происходит само движение персонажа вверх
	//	}

	//	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
	//		CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	//		if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
	//		herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 0, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
	//		herosprite.move(0, 0.1 * time);//происходит само движение персонажа вниз
	//	}

	//	window.clear();
	//	window.draw(herosprite);
	//	window.display();
	//}

	return 0;
}

