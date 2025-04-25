#pragma once

#include "planet.h"

namespace Space {
    class TelluricPlanet : public Planet {
    private:

    public:
        TelluricPlanet(std::string name, double mass, double diameter, sf::Vector2f position,
            std::string color, bool atmosphere, float temperature, std::string type, Star* parent_star);

        TelluricPlanet(std::string name, sf::Vector2f position, Star* parent_star);

        void Afisare() const override; 
    };

} 
