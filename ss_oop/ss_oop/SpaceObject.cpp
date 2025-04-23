#include "SpaceObject.h"
#include <iostream>

namespace Space {

	SpaceObject::SpaceObject(std::string name, float mass, float diameter, sf::Vector2f position, std::string color) {
		this->name = name;
		this->mass = mass;
		this->diameter = diameter;
		this->position = position;
		this->color = color;

	}

	double SpaceObject::getDiameter() const
	{
		return diameter;
	}
	std::string SpaceObject::getColor() const
	{
		return color;
	}
	sf::Vector2f SpaceObject::getPosition() const
	{
		return position;
	}
	void SpaceObject::setPosition(sf::Vector2f position)
	{
		this->position = position;
	}

	std::string SpaceObject::getName() const
	{
		return name;
	}

}