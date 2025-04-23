#pragma once
#include "SpaceObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
namespace Space {

    class Meteorite : public SpaceObject {
    private:
        sf::Vector2f velocity;

    public:
        Meteorite(float spawnWidth, float spawnHeight);

        void update(float dt) ;
        void draw(sf::RenderWindow& window);
        void afisare() const override;
    };

} 


