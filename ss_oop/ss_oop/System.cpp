#include "System.h"
#include <iostream>
#include <cmath>
class Stea;
class Planet;





void System::adaugaSoare(Stea* corp)
{
	stele.push_back(corp);
	corpuri.push_back(corp);
}

void System::adaugaPlaneta(Planet* corp)
{
	planete.push_back(corp);
	corpuri.push_back(corp);
	closestSunPosition.push_back(FindClosestSunPosition(corp));
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
void System::updatePlanetRotation(float step)
{
	int index = 0;
	for (auto planet : planete) {
		auto [Xb, Yb] = planet->getPosition();
		sf::Vector2f SunPosition = closestSunPosition[index++];

		float dx = Xb - SunPosition.x;
		float dy = Yb - SunPosition.y;
		float distance = sqrt(dx * dx + dy * dy);

		if (distance == 0) continue; 

		float angle = atan2(dy, dx); 
		angle += step / distance; 

		Xb = SunPosition.x + distance * cos(angle);
		Yb = SunPosition.y + distance * sin(angle);

		planet->setPosition({ Xb, Yb });
	}
}

sf::Vector2f System::FindClosestSunPosition(CorpCeresc* corp)
{
	CorpCeresc* c=nullptr;
	float minDist = 1000000000;
	auto [Xb, Yb] = corp->getPosition();
	for (auto stea : stele) {
		auto [Xa, Ya] = stea->getPosition();
		float distance = sqrt(pow(Xb - Xa, 2) + pow(Yb - Ya, 2));
		if (distance < minDist)
		{
			minDist = distance;
			c = stea;
		}
	}
	return c->getPosition();
	
}


