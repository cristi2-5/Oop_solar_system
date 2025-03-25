#pragma once
#include "CorpCeresc.h"
#include <SFML/Graphics.hpp>
class Stea : public CorpCeresc 
{
private:
	float temperatura;
	sf::CircleShape forma;
	std::string culoare;
public:
	Stea()
		: CorpCeresc("Soare", 2000,100, 100,100),
		temperatura(5778),culoare("Yellow") {
		forma.setRadius(10); // Raza default
		forma.setFillColor(sf::Color::Yellow);
	}; // Constructor implicit
    Stea(std::string nume, float masa, float diametru, float x, float y,
		float temperatura,std::string culoare); // Constructor
	void drawme(sf::RenderWindow& window); // Deseneaza steaua
	void afisare(); // Afiseaza informatiile despre stea
};

