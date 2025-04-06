#include "Planet.h"
#include <iostream>
#include <string>

Planet::Planet(std::string name, double mass, double diameter, sf::Vector2f position,std::string color, bool atmosphere, float temperature,std::string type, Star* parentStar) : SpaceObject(name, mass, diameter, position,color){
this->atmosphere = atmosphere;
this->temperature = temperature;
this->type = type;
this->parentStar = parentStar;
}



void Planet::afisare() {
	std::cout << "Planeta: " << getName() << " | Tip: " << type << " | Atmosfera: "
		<< (atmosphere ? "Da" : "Nu");
	
}

float Planet::getTemperature() const
{
	return temperature;
}

std::string Planet::getType() const
{
	return type;
}


Star* Planet::getParentStar() const
{
	return parentStar;
}