#pragma once
#include "Planet.h"
#include "SpaceObject.h"
namespace Space {

    class GazeousPlanet : public Space::Planet {
    public:
        GazeousPlanet(std::string name, double mass, double diameter, sf::Vector2f position,
            std::string color, bool atmosphere, float temperature,
            std::string type, Star* parentStar);

        GazeousPlanet(std::string name, sf::Vector2f position, Star* parentStar);

        void afisare() const override;
    };

} 



