#pragma once
#include "SpaceObject.h"
#include <SFML/Graphics.hpp>
 class Meteorite : public SpaceObject {
    private:
        sf::Vector2f velocity;
    public:
        Meteorite(float spawnWidth, float spawnHeight);

        void update(float dt);
        void draw(sf::RenderWindow& window);
  };


