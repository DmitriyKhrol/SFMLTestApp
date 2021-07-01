#include "SceneNode.h"

void SceneNode::AttachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::DetachChild(const SceneNode& node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
                              [&](Ptr& p) -> bool { return p.get() == &node; });
    assert(found != mChildren.end());
    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    states.transform *= getTransform();
    drawCurrent(target, states);

    for (auto itr = mChildren.begin();
         itr != mChildren.end(); ++itr)
    {
        (*itr)->draw(target, states);
    }
}



void SceneNode::Update(sf::Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time)
{
}

void SceneNode::updateChildren(sf::Time dt)
{
    for(Ptr& child : mChildren)     // FOREACH
        child->Update(dt);
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* node = this;
         node != nullptr; node = node->mParent)
        transform = node->getTransform() * transform;
    return transform;
}
sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}