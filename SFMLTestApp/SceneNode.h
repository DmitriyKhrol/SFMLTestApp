#pragma once
#include <vector>
#include <memory>       // std::unique_ptr
#include <cassert>      // assert()
#include <SFML/Graphics.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    void AttachChild(Ptr child);
    Ptr DetachChild(const SceneNode& node);
public:
    SceneNode();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<Ptr> mChildren;
    SceneNode* mParent;
};