#pragma once
#include "CorpCeresc.h"
#include <SFML/Graphics.hpp>
class Stea : public CorpCeresc 
{
private:
	float temperatura;
	std::string color;
public:
	
	Stea(std::string nume, float masa, float diametru, sf::Vector2f position, float temperatura, std::string culoare); 

	void afisare(); // Afiseaza informatiile despre stea
};

