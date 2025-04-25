#pragma once

#include "space_object.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>


namespace Space {


    class BlackHole : public SpaceObject {
    private:
        float m_strength; 

    public:
        BlackHole(sf::Vector2f position, float strength = 10000000.f);

        // atrage obiectele catre centrul gaurii negre
        void Attract(std::vector<SpaceObject*>& bodies, float delta_time);

        void Draw(sf::RenderWindow& window); 
        void Afisare() const override; 

    };

} 


