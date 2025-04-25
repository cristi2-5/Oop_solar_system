#include "telluric_planet.h"
#include <iostream>

namespace Space {

    TelluricPlanet::TelluricPlanet(std::string name, double mass, double diameter, sf::Vector2f position,
        std::string color, bool atmosphere, float temperature, std::string type, Star* parent_star)
        : Planet(name, mass, diameter, position, color, atmosphere, temperature, type, parent_star) {
    }

    TelluricPlanet::TelluricPlanet(std::string name, sf::Vector2f position, Star* parent_star)
        : Planet(name, 80.0, 30.0, position, "Blue", true, 15.0f, "telluric", parent_star) {
    }

    void TelluricPlanet::Afisare() const {
        std::cout << "Planeta telurica " << GetName() << " are un diametru de " << GetDiameter() << " km, temperatura de "
            << GetTemperature() << "C, culoarea " << GetColor() << ", si atmosfera " << GetAtmosphere()
            << ". Se afla la pozitia (" << GetPosition().x << ", " << GetPosition().y << ")." << std::endl;
    }

} 
