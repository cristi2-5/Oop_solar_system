#pragma once
#include "SpaceObject.h"

namespace Space {

    class Star : public SpaceObject {
    private:
        float temperature;

    public:
        Star(std::string name, float mass, float diameter, sf::Vector2f position, float temperature, std::string color);
        Star(std::string name, sf::Vector2f position); 

        float getTemperature() const;
        void afisare() const override;
    };

} 


