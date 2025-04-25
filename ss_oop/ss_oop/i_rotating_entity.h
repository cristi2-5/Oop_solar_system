#pragma once

#include <SFML/System/Vector2.hpp>

namespace Space {

    // interfata pentru entitati care pot efectua rotatii orbitale
    class IRotatingEntity {
    public:
        virtual ~IRotatingEntity() = default;

        virtual void UpdateRotation(float step) = 0; // actualizeaza pozitia pe orbita
        virtual sf::Vector2f GetRotationCenter() const = 0; // returneaza centrul de rotatie
        virtual float GetRotationRadius() const = 0; // returneaza raza de rotatie
    };

} 

