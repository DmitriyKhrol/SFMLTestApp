#include "Entity.h"

void Entity::SetVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}
void Entity::SetVelocity(float vx, float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}
sf::Vector2f Entity::GetVelocity() const
{
    return mVelocity;
}