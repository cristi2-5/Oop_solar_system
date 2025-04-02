#include "System.h"
#include <iostream>
class Stea;
class Planet;



void System::adaugaCorp(CorpCeresc* corp) {
	corpuri.push_back(corp);
}

sf::CircleShape System::createEntity(CorpCeresc* corp)
{
	sf::CircleShape sprite(corp->getDiameter());
	sprite.setFillColor(colorConvertor(corp->getColor()));
	sprite.setPosition(corp->getPosition());
	sprite.setOrigin(sprite.getGeometricCenter());
	return sprite;
}
sf::Color System::colorConvertor(std::string color) {
	if (color == "Red")
		return sf::Color::Red;
	if (color == "Blue")
		return sf::Color::Blue;
}

std::vector<sf::CircleShape> System::drawEntities()
{   
	std::vector < sf::CircleShape> sprites;
	for (auto corp : corpuri) {
		sprites.push_back(createEntity(corp));
	}
	return sprites;
}


