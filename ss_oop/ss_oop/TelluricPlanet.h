#pragma once
#include "Planet.h"
#include "SpaceObject.h"

class TelluricPlanet : public Planet
{
public:
	TelluricPlanet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color, bool atmosphere, float temperature, std::string type,Star* parentStar);
		
};

