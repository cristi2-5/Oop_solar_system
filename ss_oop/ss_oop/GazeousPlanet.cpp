#include "GazeousPlanet.h"
#include <iostream>

namespace Space {

	GazeousPlanet::GazeousPlanet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color, bool atmosphere, float temperature, std::string type, Star* parentStar)
		: Planet(name, mass, diameter, position, color, atmosphere, temperature, type, parentStar)
	{
	}

	GazeousPlanet::GazeousPlanet(std::string name, sf::Vector2f position, Star* parentStar)
		: Planet(name, 150.0, 60.0, position, "Cyan", true, 80.0f, "gaseous", parentStar) {
	}

	void GazeousPlanet::afisare() const {
		std::cout << "Planeta gazoasa " << getName() << " are un diametru de " << getDiameter() << " km, temperatura de " << getTemperature()
			<< "°C, culoarea " << getColor() << ", si atmosfera " << getAtmosphere()
			<< ". Se afla la pozitia (" << getPosition().x << ", " << getPosition().y << ")." << std::endl;
	}
}