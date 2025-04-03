#include "System.h"
#include <iostream>
#include <cmath>
class Star;
class Planet;
class Satellite;




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

void System::addSatellite(Satellite* body)
{
	satellites.push_back(body);
	bodies.push_back(body);
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
void System::updateSatelliteRotation(Satellite* satellite, float step)
{
	Planet* planet = satellite->getParentPlanet();
	if (!planet) return; // Dacă satelitul nu are planetă, ieșim

	static std::unordered_map<Satellite*, float> angles; // Unghiurile relative ale sateliților

	auto [Xp, Yp] = planet->getPosition(); // Poziția actualizată a planetei

	// Distanța inițială față de planetă trebuie memorată separat
	static std::unordered_map<Satellite*, float> distances;

	if (distances.find(satellite) == distances.end()) {
		// Inițializăm distanța și unghiul inițial la prima actualizare
		auto [Xs, Ys] = satellite->getPosition();
		float dx = Xs - Xp;
		float dy = Ys - Yp;
		distances[satellite] = sqrt(dx * dx + dy * dy);
		angles[satellite] = atan2(dy, dx);
	}

	// Creștem unghiul de rotație
	angles[satellite] += step;

	// Calculăm noua poziție pe orbită
	float radius = distances[satellite];
	float newX = Xp + radius * cos(angles[satellite]);
	float newY = Yp + radius * sin(angles[satellite]);

	satellite->setPosition({ newX, newY });
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


