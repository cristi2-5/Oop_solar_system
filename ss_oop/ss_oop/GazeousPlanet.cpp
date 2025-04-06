#include "GazeousPlanet.h"
#include <iostream>

GazeousPlanet::GazeousPlanet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color, bool atmosphere, float temperature, std::string type,Star* parentStar)
	: Planet(name, mass, diameter, position, color, atmosphere, temperature,type,parentStar)
{
}