#include "System.h"
#include <iostream>
#include <cmath>
class Star;
class Planet;





void System::addSun(Star* body)
{
	stars.push_back(body);
	bodies.push_back(body);
}

void System::addPlanet(Planet* body)
{
	planets.push_back(body);
	bodies.push_back(body);
	closestSunPosition.push_back(FindClosestSunPosition(body));
}

sf::CircleShape System::createEntity(SpaceObject* body)
{
	sf::CircleShape sprite(body->getDiameter());
	sprite.setFillColor(colorConvertor(body->getColor()));
	sprite.setPosition(body->getPosition());
	sprite.setOrigin(sprite.getGeometricCenter());
	return sprite;
}
sf::Color System::colorConvertor(std::string color) {
	if (color == "Red")
		return sf::Color::Red;
	if (color == "Blue")
		return sf::Color::Blue;
	if (color == "Green")
		return sf::Color::Green;
	if (color == "Yellow")
		return sf::Color::Yellow;
	if (color == "White")
		return sf::Color::White;

}


std::vector<sf::CircleShape> System::drawEntities()
{   
	std::vector < sf::CircleShape> sprites;
	for (auto body : bodies) {
		sprites.push_back(createEntity(body));
	}
	return sprites;
}
void System::updatePlanetRotation(float step)
{
	int index = 0;
	for (auto planet : planets) {
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

sf::Vector2f System::FindClosestSunPosition(SpaceObject* body)
{
	SpaceObject* c=nullptr;
	float minDist = 1000000000;
	auto [Xb, Yb] = body->getPosition();
	for (auto star : stars) {
		auto [Xa, Ya] = star->getPosition();
		float distance = sqrt(pow(Xb - Xa, 2) + pow(Yb - Ya, 2));
		if (distance < minDist)
		{
			minDist = distance;
			c = star;
		}
	}
	return c->getPosition();
	
}


