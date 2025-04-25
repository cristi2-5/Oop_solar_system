#pragma once

#include "space_object.h"
#include <SFML/Graphics.hpp>

namespace Space {

    class Meteorite : public SpaceObject {
    private:
        sf::Vector2f m_velocity; // vectorul de viteza si directie al meteoritului

    public:
        Meteorite(float spawn_width, float spawn_height);  

        void Update(float delta_time); // actualizeaza pozitia
        void Draw(sf::RenderWindow& window); 
        void Afisare() const override; 
    };
} 
