#include "Satellite.h"

Satellite::Satellite(std::string name, float mass, float diameter, sf::Vector2f position, std::string color,Planet* parentPlanet) : SpaceObject(name, mass, diameter, position, color)
{
	this->parentPlanet = parentPlanet;
}
