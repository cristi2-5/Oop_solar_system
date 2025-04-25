#pragma once

#include "space_object.h"
#include <SFML/System/Vector2.hpp>
#include <string>

namespace Space {

    
    class Star : public SpaceObject {
    private:
        float m_temperature; 

    public:
        Star(std::string name, float mass, float diameter, sf::Vector2f position, float temperature, std::string color);
        Star(std::string name, sf::Vector2f position);

        float GetTemperature() const; 
        void Afisare() const override; 
    };

} 



