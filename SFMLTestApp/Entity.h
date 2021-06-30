#pragma once
#include <SFML/Graphics.hpp>
#include "SceneNode.h"

/*
    ������� �������� �������� �������� � ���� (��������, �������, ������ � ��.)
*/
class Entity : public SceneNode
{
public:
    void SetVelocity(sf::Vector2f velocity);
    void SetVelocity(float vx, float vy);
    sf::Vector2f GetVelocity() const;
private:
    sf::Vector2f mVelocity;     // ������� �������� ��������
};