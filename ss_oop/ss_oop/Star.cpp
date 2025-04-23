#include "Star.h"
#include <iostream>

namespace Space {

    Star::Star(std::string name, float mass, float diameter, sf::Vector2f position, float temperature, std::string color) :SpaceObject(name, mass, diameter, position, color) {
        this->temperature = temperature;
    }

    float Star::getTemperature() const
    {
        return temperature;
    }


    void Star::afisare() const {
        std::cout << "Stea: " << getName() << " | Tip: " << " | Temp: "
            << temperature << "K" << std::endl;
    }

    Star::Star(std::string name, sf::Vector2f position)
        : SpaceObject(name, 100.0f, 50.0f, position, "Yellow"), temperature(5500.0f) {
    }

}