#pragma once
#include <SFML/Graphics.hpp> 

class IRotatingEntity {
public:
    virtual void updateRotation(float step) = 0;
    virtual sf::Vector2f getRotationCenter() const = 0;
    virtual float getRotationRadius() const = 0;
    virtual ~IRotatingEntity() = default;
};
