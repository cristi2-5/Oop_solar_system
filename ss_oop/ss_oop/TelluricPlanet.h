#pragma once
#include "Planet.h"

namespace Space {

    class TelluricPlanet : public Space::Planet {
    public:
        TelluricPlanet(std::string name, double mass, double diameter, sf::Vector2f position,
            std::string color, bool atmosphere, float temperature,
            std::string type, Star* parentStar);

        TelluricPlanet(std::string name, sf::Vector2f position, Star* parentStar);

        void afisare() const override;
    };

}


