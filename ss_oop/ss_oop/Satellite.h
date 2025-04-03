#pragma once
#include "SpaceObject.h"
#include "Planet.h"
class Satellite : public SpaceObject
{
	Planet* parentPlanet; 
public:
	Satellite(std::string name, float mass, float diameter, sf::Vector2f position, std::string color, Planet* parentPlanet);
	Planet* getParentPlanet() const { return parentPlanet; }
};

