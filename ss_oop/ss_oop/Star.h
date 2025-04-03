#pragma once
#include "SpaceObject.h"
#include <SFML/Graphics.hpp>
class Star : public  SpaceObject
{
private:
	float temperature;
public:
	
	Star(std::string name, float mass, float diameter, sf::Vector2f position, float temperature, std::string color); 
	float getTemperature() const;
	void afisare(); // Afiseaza informatiile despre stea
};

