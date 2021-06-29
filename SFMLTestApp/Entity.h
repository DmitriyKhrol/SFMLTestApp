#pragma once
#include <SFML/Graphics.hpp>

/*
    Базовая сущность игрового элемента в мире (персонаж, предмет, снаряд и др.)
*/
class Entity
{
public:
    void SetVelocity(sf::Vector2f velocity);
    void SetVelocity(float vx, float vy);
    sf::Vector2f GetVelocity() const;
private:
    sf::Vector2f mVelocity;     // текущая скорость сущности
};