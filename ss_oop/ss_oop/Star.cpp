#include "star.h"
#include <iostream>

namespace Space {

    Star::Star(std::string name, float mass, float diameter, sf::Vector2f position, float temperature, std::string color)
        : SpaceObject(name, mass, diameter, position, color), m_temperature(temperature) {
    }

    Star::Star(std::string name, sf::Vector2f position)
        : SpaceObject(name, 100.0f, 50.0f, position, "Yellow"), m_temperature(5500.0f) {
    }

    float Star::GetTemperature() const {
        return m_temperature;
    }

    void Star::Afisare() const {
        std::cout << "Stea: " << GetName() << " | Temp: " << m_temperature << "K" << std::endl;
    }
} 
