#include "TelluricPlanet.h"
#include <iostream>

namespace Space {

	TelluricPlanet::TelluricPlanet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color, bool atmosphere, float temperature, std::string type, Star* parentStar)
		: Planet(name, mass, diameter, position, color, atmosphere, temperature, type, parentStar)
	{
	}

	TelluricPlanet::TelluricPlanet(std::string name, sf::Vector2f position, Star* parentStar)
		: Planet(name, 80.0, 30.0, position, "Blue", true, 15.0f, "telluric", parentStar) {
	}
	void TelluricPlanet::afisare() const {
		std::cout << "Planeta telurica " << getName() << " are un diametru de " << getDiameter() << " km, temperatura de " << getTemperature() << "°C, culoarea " << getColor()
			<< ", si atmosfera " << getAtmosphere() << ". Se afla la pozitia (" << getPosition().x << ", " << getPosition().y << ")." << std::endl;
	}
}