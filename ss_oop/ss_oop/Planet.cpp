#include "Planet.h"
#include <iostream>
#include <string>

Planet::Planet(std::string name, double mass, double diameter, sf::Vector2f position,std::string color, bool atmosphere, float temperature) : SpaceObject(name, mass, diameter, position,color){
this->atmosphere = atmosphere;
this->temperature = temperature;
}



void Planet::afisare() {
	std::cout << "Planeta: " << getName() << " | Tip: " << type << " | Atmosfera: "
		<< (atmosphere ? "Da" : "Nu");
	
}

float Planet::getTemperature() const
{
	return temperature;
}


