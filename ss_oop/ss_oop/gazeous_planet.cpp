#include "gazeous_planet.h"
#include <iostream>

namespace Space {

    GazeousPlanet::GazeousPlanet(std::string name, double mass, double diameter, sf::Vector2f position,
        std::string color, bool atmosphere, float temperature, std::string type, Star* parent_star)
        : Planet(name, mass, diameter, position, color, atmosphere, temperature, type, parent_star) {
    }

    GazeousPlanet::GazeousPlanet(std::string name, sf::Vector2f position, Star* parent_star)
        : Planet(name, 150.0, 60.0, position, "Cyan", true, 80.0f, "gaseous", parent_star) {
    }

    void GazeousPlanet::Afisare() const {
        std::cout << "Planeta gazoasa " << GetName() << " are un diametru de " << GetDiameter() << " km, temperatura de "
            << GetTemperature() << "C, culoarea " << GetColor() << ", si atmosfera " << GetAtmosphere()
            << ". Se afla la pozitia (" << GetPosition().x << ", " << GetPosition().y << ")." << std::endl;
    }
} 
